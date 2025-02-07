/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:02:28 by jtran             #+#    #+#             */
/*   Updated: 2025/02/05 13:41:52 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_command(t_data *data, char **cmd, char *path, int i)
{
	close_fds(data->pipe);
	close(data->fd[i]);
	execve(path, cmd, NULL);
	free_all(cmd, data->env, path);
	exit(0);
}
