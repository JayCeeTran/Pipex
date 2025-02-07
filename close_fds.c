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

void	close_fd_pipe(int *pipefd, int *fd)
{
	close_fds(pipefd);
	close_fds(fd);
}
