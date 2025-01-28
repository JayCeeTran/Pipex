#include "pipex.h"

void	execute_command(char **cmd, char *path, int *fd)
{
	execve(path, cmd, NULL);
	command_not_found(cmd[0]);
	free_split(cmd);
	free(path);
	close_fds(fd);
	exit(EXIT_FAILURE);
}

void	check_command_arguments(char **argv, int *fd, int ac)
{
	int i;
	int j;

	j = 0;
	i = 2;
	while(i < ac - 1)
	{
		while(argv[i][j] == ' ')
			j++;
		if(argv[i][j] == '\0')
		{
			close_fds(fd);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
