/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:02:54 by jtran             #+#    #+#             */
/*   Updated: 2025/02/04 09:02:57 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork_error(char **cmd, char *path, t_fds *data, int child)
{
	which_fd_to_close(child, data);
	free_split(cmd);
	free_split(data->envp);
	free(path);
	perror("Error\n");
	exit(EXIT_FAILURE);
}

void	first_child(char *argv, t_fds *data)
{
	int		pid;
	char	**cmd;
	char	*path_exe;

	cmd = ft_split(argv, ' ');
	if (!cmd)
		failed_malloc(data, 1);
	path_exe = find_correct_bin(cmd, data, 1);
	if (!path_exe)
		command_not_found(cmd, data, 1);
	pid = fork();
	if (pid == -1)
		fork_error(cmd, path_exe, data, 1);
	if (pid == 0)
	{
		dup2(data->fd[0], 0);
		dup2(data->pipe1[1], 1);
		close_pipefd(data->pipe1);
		execute_command(cmd, path_exe, data, 1);
	}
	free_split(cmd);
	free(path_exe);
}

int	loop_mid(char **argv, t_fds *data, int ac)
{
	int			i;
	t_pointers	pipes;

	i = 3;
	pipes.newpipe = data->pipe2;
	pipes.cur_pipe = data->pipe1;
	while (i < ac - 2)
	{
		if (i > 3)
		{
			pipes.temp = pipes.cur_pipe;
			pipes.cur_pipe = pipes.newpipe;
			pipes.newpipe = pipes.temp;
		}
		if (pipe(pipes.newpipe) == -1)
			pipe_failed(pipes.cur_pipe, data->fd, data->envp);
		mid_child(argv[i], data, &pipes);
		i++;
	}
	if (i > 3)
		last_child(argv[ac - 2], data, pipes.newpipe);
	else
		last_child_no_mid(argv[ac - 2], data, pipes.cur_pipe);
	return (i);
}

void	mid_child(char *argv, t_fds *data, t_pointers *pipe)
{
	int		pid;
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (!cmd)
		failed_malloc(data, 2);
	path = find_correct_bin(cmd, data, 2);
	if (!path)
		command_not_found(cmd, data, 2);
	pid = fork();
	if (pid == -1)
		fork_error(cmd, path, data, 2);
	if (pid == 0)
	{
		dup2(pipe->cur_pipe[0], 0);
		dup2(pipe->newpipe[1], 1);
		close_fd_pipe(data->pipe1, data->pipe2);
		execute_command(cmd, path, data, 2);
	}
	close_pipefd(pipe->cur_pipe);
	free_split(cmd);
	free(path);
}

void	last_child(char *argv, t_fds *data, int *pipe)
{
	int		pid;
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (!cmd)
		failed_malloc(data, 2);
	path = find_correct_bin(cmd, data, 2);
	if (!path)
		command_not_found(cmd, data, 2);
	pid = fork();
	if (pid == -1)
		fork_error(cmd, path, data, 2);
	if (pid == 0)
	{
		dup2(pipe[0], 0);
		dup2(data->fd[1], 1);
		close_fd_pipe(data->pipe2, data->pipe1);
		execute_command(cmd, path, data, 2);
	}
	close_fd_pipe(data->pipe2, data->fd);
	close_pipefd(data->pipe1);
	free_all(cmd, data->envp, path);
}
