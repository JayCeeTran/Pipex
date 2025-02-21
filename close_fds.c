/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:02:40 by jtran             #+#    #+#             */
/*   Updated: 2025/02/07 08:36:55 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fds(int *fd)
{
	if (fd)
	{
		if (fd[0] > 0 && fd[0] < 2147483647)
			close(fd[0]);
		if (fd[1] > 0 && fd[1] < 2147483647)
			close(fd[1]);
	}
}

void	close_fd_pipe(int *pipefd, int *fd)
{
	close_fds(pipefd);
	close_fds(fd);
}
