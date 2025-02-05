/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:02:54 by jtran             #+#    #+#             */
/*   Updated: 2025/02/05 12:12:49 by jtran            ###   ########.fr       */
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
	char	**cmd;
	char	*path_exe;

	cmd = ft_split(argv, ' ');
	if (!cmd)
		failed_malloc(data, 1);
	path_exe = find_correct_bin(cmd, data, 1);
	if (!path_exe)
		command_not_found(cmd, data, 1);
	data->pid = fork();
	if (data->pid == -1)
		fork_error(cmd, path_exe, data, 1);
	if (data->pid == 0)
	{
		if(data->fd[0] == -1)
		{
			free_all(cmd, data->envp, path_exe);
			exit(EXIT_FAILURE);
		}
		dup2(data->fd[0], 0);
		dup2(data->pipe1[1], 1);
		close_pipefd(data->pipe1);
		execute_command(cmd, path_exe, data, 1);
	}
	free_split(cmd);
	free(path_exe);
	waitpid(data->pid, NULL, 0);
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
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (!cmd)
		failed_malloc(data, 2);
	path = find_correct_bin(cmd, data, 2);
	if (!path)
		command_not_found(cmd, data, 2);
	data->pid = fork();
	if (data->pid == -1)
		fork_error(cmd, path, data, 2);
	if (data->pid == 0)
	{
		dup2(pipe->cur_pipe[0], 0);
		dup2(pipe->newpipe[1], 1);
		close_fd_pipe(data->pipe1, data->pipe2);
		execute_command(cmd, path, data, 2);
	}
	close_pipefd(pipe->cur_pipe);
	free_split(cmd);
	free(path);
	waitpid(data->pid, NULL, 0);
}

void	last_child(char *argv, t_fds *data, int *pipe)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (!cmd)
		failed_malloc(data, 2);
	path = find_correct_bin(cmd, data, 2);
	if (!path)
		command_not_found(cmd, data, 2);
	data->pid = fork();
	if (data->pid == -1)
		fork_error(cmd, path, data, 2);
	if (data->pid == 0)
	{
		dup2(pipe[0], 0);
		dup2(data->fd[1], 1);
		close_fd_pipe(data->pipe2, data->pipe1);
		execute_command(cmd, path, data, 2);
	}
	close_fd_pipe(data->pipe2, data->fd);
	close_pipefd(data->pipe1);
	free_all(cmd, data->envp, path);
	data->status = 0;
	waitpid(data->pid, &data->status, 0);
	if (WIFEXITED(data->status))
        exit(WIFEXITED(data->status));
}
