/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:37:04 by jtran             #+#    #+#             */
/*   Updated: 2025/02/07 08:37:08 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	too_few_arguments(void)
{
	write(2, "Error\nInvalid amount of arguments\n", 34);
	exit(EXIT_FAILURE);
}

void	pipe_failed(char **env)
{
	free_split(env);
	perror("Error\nPipe failed\n");
	exit(EXIT_FAILURE);
}

void	failed_malloc(t_data *data)
{
	free_split(data->env);
	close_fds(data->pipe);
	write(2, "Error\nFailed to malloc command strings\n", 39);
	exit(EXIT_FAILURE);
}

void	free_close_exit(t_data *data, char **cmd, char *path)
{
	free_all(cmd, data->env, path);
	close_fds(data->pipe);
	exit(EXIT_FAILURE);
}
