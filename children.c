#include "pipex.h"

void	fork_error(char **cmd, char *path, int *pipefd, int *fd)
{
	close_fd_pipe(pipefd, fd);
	free_split(cmd);
	free(path);
	perror("Error\n");
	exit(EXIT_FAILURE);
}

void	first_child(char *argv, int *pipefd, int *fd)
{
	int pid;
	char **cmd;
	char *path;

	cmd = ft_split(argv, ' ');
	if(!cmd)
		failed_malloc(pipefd, fd);
	path = ft_strjoin("/bin/", cmd[0]);
	if(!path)
		path_failed_malloc(cmd, pipefd, fd);
	pid = fork();
	if(pid == -1)
		fork_error(cmd, path, pipefd, fd);
	if (pid == 0)
	{
		dup2(fd[0], 0);
		dup2(pipefd[1], 1);
		close_pipefd(pipefd);
		execute_command(cmd, path, fd);
	}
	free_split(cmd);
	free(path);
}

int	loop_mid(char **argv, int *pipe1, int *fd, int ac)
{
	int	i;
	int pipe2[2];
	int *cur_pipe;
	int *newpipe;

	i = 3;
	newpipe = pipe2;
	cur_pipe = pipe1;
	while(i < ac - 2)
	{
		if(i > 3)
		{
			pipe1 = cur_pipe;
			cur_pipe = newpipe;
			newpipe = pipe1;
		}
		if(pipe(newpipe) == -1)
			pipe_failed(cur_pipe, fd);	
		mid_child(argv[i], cur_pipe, newpipe, fd);
		i++;
		close_pipefd(cur_pipe);
	}
	if(i > 3)
		last_child(argv[ac - 2], newpipe, fd);
	else
		last_child(argv[ac - 2], pipe1, fd);
    return(i);
}

void	mid_child(char *argv, int *pipe1, int *pipe2, int *fd)
{
	int pid;
	char **cmd;
	char *path;

	cmd = ft_split(argv, ' ');
	if(!cmd)
		failed_malloc(pipe1, pipe2);
	path = ft_strjoin("/bin/", cmd[0]);
	if(!path)
		path_failed_malloc(cmd, pipe1, pipe2);
	pid = fork();
	if(pid == -1)
		fork_error(cmd, path, pipe1, pipe2);
	if(pid == 0)
	{
		dup2(pipe1[0], 0);
		dup2(pipe2[1], 1);
		close_fd_pipe(pipe1, pipe2);
		execute_command(cmd, path, fd);
	}
	free_split(cmd);
	free(path);
}

void	last_child(char *argv, int *pipefd, int *fd)
{
	int pid;
	char **cmd;
	char *path;
	
	cmd = ft_split(argv, ' ');
	if(!cmd)
		failed_malloc(pipefd, fd);
	path = ft_strjoin("/bin/", cmd[0]);
	if(!path)
		path_failed_malloc(cmd, pipefd, fd);
	pid = fork();
	if(pid == -1)
		fork_error(cmd, path, pipefd, fd);
	if (pid == 0)
	{
		dup2(pipefd[0], 0);
		dup2(fd[1], 1);
		close_pipefd(pipefd);
		execute_command(cmd, path, fd);
	}
	close_fd_pipe(pipefd, fd);
	free_split(cmd);
	free(path);
}
