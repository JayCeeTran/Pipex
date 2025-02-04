/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:02:28 by jtran             #+#    #+#             */
/*   Updated: 2025/02/04 11:15:09 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_command(char **cmd, char *path, t_fds *data, int child)
{
	execve(path, cmd, NULL);
	which_fd_to_close(child, data);
	free_split(cmd);
	free(path);
	exit(EXIT_FAILURE);
}

void	check_command_arguments(char **argv, int *fd, int ac)
{
	int	i;
	int	j;

	j = 0;
	i = 2;
	while (i < ac - 1)
	{
		while (argv[i][j] == ' ')
			j++;
		if (argv[i][j] == '\0')
		{
			close_fds(fd);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
