/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocubukcu <ocubukcu@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 00:50:33 by ocubukcu          #+#    #+#             */
/*   Updated: 2024/12/20 01:05:41 by ocubukcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>

void	child1(char **env, int *pipefd, char **argv, char *path)
{
	int		fd;
	char	**split;

	split = ft_split(argv[2], ' ');
	if (!split || fork() == 0)
	{
		close(pipefd[0]);
		fd = open(argv[1], O_RDWR);
		if (fd == -1 || dup2(fd, 0) == -1 || dup2(pipefd[1], 1) == -1)
			error_message("Error in child1", split, 1);
		execve(path, split, env);
		perror("Execve error");
		exit(EXIT_FAILURE);
	}
	free_args(split);
}

void	child2(char **env, int *pipefd, char **av, char *path)
{
	int		fd;
	char	**split;

	split = ft_split(av[3], ' ');
	if (!split || fork() == 0)
	{
		close(pipefd[1]);
		fd = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (fd == -1 || dup2(pipefd[0], 0) == -1 || dup2(fd, 1) == -1)
			error_message("Error in child2", split, 1);
		execve(path, split, env);
		perror("Execve error");
		exit(EXIT_FAILURE);
	}
	terminate_fd(pipefd[0], pipefd[1]);
	free_args(split);
}

char	*path_finder(char **env, char *cmd)
{
	int		i;
	char	**dup_path;
	char	**path_way;
	char	*path;
	char	*way;

	path = NULL;
	dup_path = ft_split(cmd, ' ');
	path_way = search_path(env);
	if (!dup_path || !path_way)
		error_message("Path error", dup_path, 1);
	path = ft_strjoin("/", dup_path[0]);
	free_args(dup_path);
	i = -1;
	while (path_way[++i])
	{
		way = check_cmd(ft_strjoin(path_way[i], path));
		if (way)
			return (free_args(path_way), free(path), way);
	}
	return (error_message(path, path_way, 1), NULL);
}

char	**search_path(char **env)
{
	char	*path_var;
	char	**path_dirs;

	while (*env && !ft_strnstr(*env, "PATH=", 5))
		env++;
	path_var = ft_substr(*env, 5, ft_strlen(*env) - 5);
	path_dirs = ft_split(path_var, ':');
	free(path_var);
	if (!path_dirs)
		return (free_args(path_dirs), free(path_var), NULL);
	return (path_dirs);
}

int	main(int argc, char **argv, char **env)
{
	int		pipeid[2];
	char	*path;

	if (!(*env))
		exit(EXIT_FAILURE);
	if (argc != 5)
		exit(EXIT_FAILURE);
	if (pipe(pipeid) == -1)
		exit(EXIT_FAILURE);
	path = path_finder(env, argv[2]);
	child1(env, pipeid, argv, path);
	free(path);
	waitpid(-1, NULL, 0);
	path = path_finder(env, argv[3]);
	child2(env, pipeid, argv, path);
	free(path);
	waitpid(-1, NULL, 0);
	close(pipeid[0]);
	close(pipeid[1]);
	return (0);
}
