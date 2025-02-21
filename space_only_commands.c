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
	while(av[j] == ' ')
		j++;
	if (av[j] == '\0')
	{
		if(j == 0)
		{
			return(-1);
		}
		return(1);
	}
	return (0);
}

void	free_exit(t_data *data)
{
	free_split(data->env);
	close_fd_pipe(data->pipe, data->fd);
	exit(EXIT_FAILURE);
}
