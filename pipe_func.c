#include "pipex.h"

int	redirect(int fd_in, int fd_out, t_cmds *cmds)
{
	int pipe_fd[2];

	if(pipe(pipe_fd) == -1)
	{
		perror("Error\n");
		return (-1);		
	}
	int pid = fork();
	if(pid == 0)
	{
		dup2(fd_in, 0);
		dup2(pipe_fd[1], 1);		
		close(pipe_fd[1]);
		close(pipe_fd[0]);
		execve(cmds->cmd1.path, cmds->cmd1.commands, NULL);
		exit(EXIT_FAILURE);
	}
	int pid2 = fork();
	if(pid2 == 0)
	{
		dup2(pipe_fd[0], 0);
		dup2(fd_out, 1);
		close(pipe_fd[1]);
		close(pipe_fd[0]);
		execve(cmds->cmd2.path, cmds->cmd2.commands, NULL);
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
	close(fd_in);
	close(fd_out);
	return(0);
}
