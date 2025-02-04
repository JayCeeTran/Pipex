/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:02:50 by jtran             #+#    #+#             */
/*   Updated: 2025/02/04 09:02:50 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	find_path(char **env, t_fds *data)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
		{
			data->envp = ft_split(env[i] + 5, ':');
			if (!data->envp)
			{
				write(2, "Error\nFailed to malloc envp\n", 28);
				close_fds(data->fd);
				exit(EXIT_FAILURE);
			}
			break ;
		}
		i++;
	}
	if (!env[i])
	{
		write(2, "Error\nNo envp found\n", 20);
		close_fds(data->fd);
		exit(EXIT_FAILURE);
	}
}

void	execute_permission(char *path, t_fds *data, int child, char **cmd)
{
	if (access(path, X_OK) == -1)
	{
		which_fd_to_close(child, data);
		free_split(cmd);
		free_split(data->envp);
		free(path);
		write(2, "Error\nExecution Permission denied\n", 34);
		exit(126);
	}
}

char	*find_correct_bin(char **cmd, t_fds *data, int child)
{
	char	*path_exe;
	char	*slash;
	int		i;

	i = 0;
	while (data->envp[i])
	{
		slash = ft_strjoin(data->envp[i], "/");
		path_exe = ft_strjoin(slash, cmd[0]);
		if (!slash || !path_exe)
		{
			free(slash);
			path_failed_malloc(cmd, data, child);
		}
		free(slash);
		if (access(path_exe, F_OK) == 0)
		{
			execute_permission(path_exe, data, child, cmd);
			return (path_exe);
		}
		free(path_exe);
		i++;
	}
	return (NULL);
}
