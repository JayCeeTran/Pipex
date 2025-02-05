/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:02:40 by jtran             #+#    #+#             */
/*   Updated: 2025/02/05 11:52:19 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fds(int *fd)
{
	if (fd)
	{
		if(fd[0] > 0)
			close(fd[0]);
		if(fd[1] > 0)
			close(fd[1]);
	}
}

void	close_pipefd(int *pipefd)
{
	if (pipefd)
	{
		if(pipefd[0] > 0)
			close(pipefd[0]);
		if(pipefd[1] > 0)
			close(pipefd[1]);
	}
}

void	close_fd_pipe(int *pipefd, int *fd)
{
	close_pipefd(pipefd);
	close_fds(fd);
}

void	pipe_failed(int *pipe1, int *fd, char **envp)
{
	close_pipefd(pipe1);
	close_fds(fd);
	free_split(envp);
	perror("Error\nPipe failed\n");
	exit(EXIT_FAILURE);
}

void	fd_open_fail_out(int *fd)
{
	close_fds(fd);
	exit(EXIT_FAILURE);
}
