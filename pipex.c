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
			permission_denied(argv);
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
		if(errno == ENOENT)
			no_such_file_infile(argv);
		else if(errno == EACCES)
			permission_denied(argv);
		return(-1);
	}
	else
		fd = open(argv, O_RDONLY);
	return(fd);
}

int main(int argc, char **argv, char **env) 
{
	int fd[2];
	int	pipefd[2];
	int i;
	char **path;

	if (argc < 5)
		too_few_arguments();
	fd[0] = check_input_file(argv[1]);
	fd[1] = check_output_file(argv[argc - 1]);
	if(fd[1] == -1 || fd[0] == -1)
		fd_open_fail(fd);
	check_command_arguments(argv, fd, argc);
	path = find_path(env);
	if(pipe(pipefd) == -1)
		pipe_failed(NULL, fd);
	first_child(argv[2], pipefd, fd, path);
	i = loop_mid(argv, pipefd, fd, argc);
	while(i-- >= 2)
		wait(NULL);
    return 0;
}
