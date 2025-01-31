#include "pipex.h"

void	close_fds(int *fd)
{
	if(fd)
	{	
		close(fd[0]);
		close(fd[1]);
	}
}

void	close_pipefd(int *pipefd)
{
	if(pipefd)
	{
		close(pipefd[0]);
		close(pipefd[1]);
	}
}

void	close_fd_pipe(int *pipefd, int *fd)
{
	close_pipefd(pipefd);
	close_fds(fd);
}

void	pipe_failed(int *pipe1, int *fd, char **envp)
{
	close_pipefd(pipe1);
	close_fds(fd);
	free_split(envp);
	perror("Error\nPipe failed\n");
	exit(EXIT_FAILURE);
}

void	fd_open_fail(int *fd)
{
	close_fds(fd);
	exit(0);
}
