/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:02:20 by jtran             #+#    #+#             */
/*   Updated: 2025/02/04 09:02:23 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **commands)
{
	int	i;

	i = 0;
	if (!commands)
		return ;
	while (commands[i])
		free(commands[i++]);
	free(commands);
}

void	free_all(char **cmd, char **envp, char *path)
{
	free_split(cmd);
	free_split(envp);
	free(path);
}

int	count_ac(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	last_child_no_mid(char *argv, t_fds *data, int *pipe)
{
	int		pid;
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (!cmd)
		failed_malloc(data, 1);
	path = find_correct_bin(cmd, data, 1);
	if (!path)
		command_not_found(cmd, data, 1);
	pid = fork();
	if (pid == -1)
		fork_error(cmd, path, data, 1);
	if (pid == 0)
	{
		dup2(pipe[0], 0);
		dup2(data->fd[1], 1);
		close_pipefd(data->pipe1);
		execute_command(cmd, path, data, 1);
	}
	close_fd_pipe(data->pipe1, data->fd);
	free_split(data->envp);
	free_split(cmd);
	free(path);
}
