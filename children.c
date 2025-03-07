/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:36:42 by jtran             #+#    #+#             */
/*   Updated: 2025/02/07 09:18:03 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork_error(t_data *data)
{
	free_split(data->env);
	close_fds(data->pipe);
	perror("Error\n");
	exit(EXIT_FAILURE);
}

void	child1(t_data *data, char **av, char **ev, char **cmd)
{
	char	*path;

	data->fd[0] = validate_infile(av[1]);
	if (data->fd[0] == -1)
		free_exit(data);
	if (!space_only_commands(av[2]))
		cmd = ft_split(av[2], ' ');
	else if(space_only_commands(av[2]) == -1)
		command_not_found(data, cmd);
	else
		cmd = ft_split(av[2], 'a');
	if (!cmd)
		failed_malloc(data);
	path = path_as_command(data, cmd);
	if(!path)
		path = find_correct_bin(data, cmd);
	if (!path)
		command_not_found(data, cmd);
	dup2(data->fd[0], 0);
	dup2(data->pipe[1], 1);
	close(data->fd[0]);
	execute_command(data, cmd, path, ev);
}

void	child2(t_data *data, char **av, char **ev, char **cmd)
{
	char	*path;

	data->fd[1] = validate_outfile(av[4]);
	if (data->fd[1] == -1)
		free_exit(data);
	if (!space_only_commands(av[3]))	
		cmd = ft_split(av[3], ' ');
	else if(space_only_commands(av[3]) == -1)
		command_not_found(data, cmd);
	else
		cmd = ft_split(av[3], 'a');
	if (!cmd)
		failed_malloc(data);		
	path = path_as_command(data, cmd);
	if(!path)
		path = find_correct_bin(data, cmd);
	if (!path)
		command_not_found(data, cmd);
	dup2(data->pipe[0], 0);
	dup2(data->fd[1], 1);
	close(data->fd[1]);
	execute_command(data, cmd, path, ev);
}
