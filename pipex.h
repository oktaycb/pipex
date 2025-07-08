/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocubukcu <ocubukcu@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 00:50:30 by ocubukcu          #+#    #+#             */
/*   Updated: 2024/12/18 06:24:52 by ocubukcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	child1(char **env, int *pipefd, char **argv, char *path);
void	child2(char **env, int *pipefd, char **argv, char *path);
void	error_message(char *s, char **s2, int i);
void	free_args(char **args);
void	terminate_fd(int fd1, int fd2);
char	*check_cmd(char *path);
char	*path_finder(char **env, char *cmd);
char	**search_path(char **env);

#endif
