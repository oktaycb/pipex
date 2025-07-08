/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocubukcu <ocubukcu@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 05:35:40 by ocubukcu          #+#    #+#             */
/*   Updated: 2024/12/19 21:44:08 by ocubukcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>

void	error_message(char *s, char **s2, int i)
{
	if (i == 1)
		free(s);
	free_args(s2);
	ft_putstr_fd("Fault message: There is no way.", 2);
	exit(EXIT_FAILURE);
}

char	*check_cmd(char *path)
{
	if (access(path, F_OK) == 0)
		return (path);
	free(path);
	return (0);
}

void	terminate_fd(int fd1, int fd2)
{
	if (fd1 != -1)
		close(fd1);
	if (fd2 != -1)
		close(fd2);
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
		free(args[i++]);
	free(args);
}
