/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_as_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:17:37 by jtran             #+#    #+#             */
/*   Updated: 2025/02/07 09:17:41 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    free_exit_dir(t_data *data, char **cmd, char *path);
void	helper(t_data *data, char **cmd, char *s);

char	*path_as_command(t_data *data, char **cmd)
{
	char *s;

	if (access(cmd[0], F_OK) == 0)
	{
		s = ft_strdup(cmd[0]);
		if(!s)
		{
			free(cmd);
			failed_malloc(data);
		}
		helper(data, cmd, s);
		return(s);
	}
	return (NULL);
}

void	helper(t_data *data, char **cmd, char *s)
{
	int fd;

	if (access(cmd[0], X_OK) == 0)
	{
		fd = open(s, O_WRONLY);
		if(fd > 0)
			close(fd);
		if(fd == -1 && errno == EISDIR && s[0] == '/')
		{
			is_dir(s);
			free_exit_dir(data, cmd, s);
		}
		if(s[0] != '.' && s[0] != '/')
		{
			free(s);
			command_not_found(data, cmd);
		}
		return ;
	}
	else
		execute_permission(data, cmd, s);
}

void    free_exit_dir(t_data *data, char **cmd, char *path)
{
    free_all(cmd, data->env, path);
    close_fd_pipe(data->pipe, data->fd);
    exit(126);
}
