/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_only_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:37:51 by jtran             #+#    #+#             */
/*   Updated: 2025/02/07 08:37:54 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	space_only_commands(char *av)
{
	int	j;

	j = 0;
	while (av[j] == ' ')
		j++;
	if (av[j] == '\0')
	{
		return (1);
	}
	return (0);
}

void	free_exit(t_data *data)
{
	free_split(data->env);
	close_fds(data->pipe);
	exit(EXIT_FAILURE);
}

void	create_out_exit(t_data *data, char *av, int exitcode)
{
	int	fd;

	if (av)
	{
		fd = open(av, O_CREAT | O_WRONLY | O_TRUNC, 0664);
		if (fd == -1)
			perror("Error\n");
		else
			close(fd);
	}
	free_split(data->env);
	close_fds(data->pipe);
	exit(exitcode);
}
