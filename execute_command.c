/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:02:28 by jtran             #+#    #+#             */
/*   Updated: 2025/02/07 08:37:12 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_command(t_data *data, char **cmd, char *path, char **ev)
{
	close_fds(data->pipe);
	execve(path, cmd, ev);
	free_all(cmd, data->env, path);
	exit(0);
}
