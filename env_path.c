/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:02:50 by jtran             #+#    #+#             */
/*   Updated: 2025/02/07 08:36:59 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_permission(t_data *data, char **cmd, char *path)
{
	if (access(path, X_OK) == -1)
	{
		if(path[0] != '.' && path[0] != '/')
		{
			free(path);
			command_not_found(data, cmd);
		}
		permission_denied(path);
		free_all(cmd, data->env, path);
		close_fd_pipe(data->pipe, data->fd);
		exit(126);
	}
}

void	strjoin_failed(t_data *data, char **cmd, char *slash)
{
	free_split(cmd);
	free_split(data->env);
	if (slash)
		free(slash);
	close_fd_pipe(data->pipe, data->fd);
	write(2, "Error\nFailed to malloc path to command\n", 39);
	exit(EXIT_FAILURE);
}

char	*find_correct_bin(t_data *data, char **cmd)
{
	char	*path;
	char	*slash;
	int		i;

	i = 0;
	while (data->env[i])
	{
		slash = ft_strjoin(data->env[i], "/");
		if (!slash)
			strjoin_failed(data, cmd, NULL);	
		path = ft_strjoin(slash, cmd[0]);
		if (!path)
			strjoin_failed(data, cmd, slash);
		free(slash);
		if (access(path, F_OK) == 0)
		{
			execute_permission(data, cmd, path);
			return (path);
		}
		free(path);
		i++;
	}
	return (NULL);
}
