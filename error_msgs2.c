/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msgs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:02:34 by jtran             #+#    #+#             */
/*   Updated: 2025/02/04 11:29:03 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	failed_malloc(t_fds *data, int child)
{
	which_fd_to_close(child, data);
	free_split(data->envp);
	write(2, "Error\nFailed to malloc command strings\n", 39);
	exit(EXIT_FAILURE);
}

void	which_fd_to_close(int child, t_fds *data)
{
	if (child == 1)
		close_pipefd(data->pipe1);
	else if (child == 3)
		close_pipefd(data->pipe2);
	else if (child == 2)
		close_fd_pipe(data->pipe1, data->pipe2);
	close_fds(data->fd);
}

void	path_failed_malloc(char **cmd, t_fds *data, int child)
{
	which_fd_to_close(child, data);
	free_split(cmd);
	free_split(data->envp);
	write(2, "Error\nFailed to malloc path string\n", 35);
	exit(EXIT_FAILURE);
}

void	too_few_arguments(void)
{
	write(2, "Error\nToo few arguments\n", 24);
	exit(EXIT_FAILURE);
}

void	fd_open_fail(int *fd)
{
	close_fds(fd);
	exit(0);
}
