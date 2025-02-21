/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:37:21 by jtran             #+#    #+#             */
/*   Updated: 2025/02/07 08:37:22 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_closepipe(t_data *data)
{
	free_split(data->env);
	close(data->pipe[0]);
}

int	main(int ac, char **av, char **ev)
{
	t_data	data;

	if (ac != 5)
		too_few_arguments();
	store_ac_env_to_struct(&data, ev);
	if (pipe(data.pipe) == -1)
		pipe_failed(data.env);
	data.pid1 = fork();
	if (data.pid1 == -1)
		fork_error(&data);
	if (data.pid1 == 0)
		child1(&data, av, ev, NULL);
	close(data.pipe[1]);
	data.pid2 = fork();
	if (data.pid2 == -1)
		fork_error(&data);
	if (data.pid2 == 0)
		child2(&data, av, ev, NULL);
	waitpid(data.pid1, &data.status, 0);
	waitpid(data.pid2, &data.status, 0);
	free_closepipe(&data);
	if (WIFEXITED(data.status))
		exit(WEXITSTATUS(data.status));
	return (0);
}
