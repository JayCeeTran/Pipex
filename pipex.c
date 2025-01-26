#include "pipex.h"
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int	check_output_file(char *argv)
{
	int fd;

	if (access(argv, W_OK) == -1)
	{
		if(errno == ENOENT)
		{
			fd = open(argv, O_CREAT | O_WRONLY | O_EXCL, 0664);
			return(fd);
		}
		else if(errno == EACCES)
		{
			perror("Error\n");
			return(-1);
		}
	}
	fd = open(argv, O_WRONLY | O_TRUNC);
	return(fd);
}

int	check_input_file(char *argv)
{
	int fd;

	if(access(argv, R_OK) == -1)
	{
		perror("Error\n");
		exit(EXIT_FAILURE);
	}
	else
		fd = open(argv, O_RDONLY);
	return(fd);
}

int main(int argc, char **argv) 
{
	int fd[2];
	int	pipefd[2];
	int i;

	if (argc < 5)
		invalid_argument();
	fd[0] = check_input_file(argv[1]);
	fd[1] = check_output_file(argv[argc - 1]);
	if(fd[0] == -1 || fd[1] == -1)
		fd_open_fail(fd);
	if(pipe(pipefd) == -1)
		pipe_failed(fd);
	first_child(argv[2], pipefd, fd);
	i = loop_mid(argv, pipefd, fd, argc);
/*	if(even(i))
		last_child(argv[argc - 2], pipe2, pipefd, fd);
	else
		last_child(argv[argc - 2], pipefd, pipe2, fd);*/
	//close_fd_pipe(pipefd, fd);
	while(i >= 2)
	{
		wait(NULL);
		i--;
	}
    return 0;
}
