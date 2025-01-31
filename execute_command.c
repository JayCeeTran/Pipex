#include "pipex.h"

void	execute_command(char **cmd, char *path, t_fds *data, int child)
{
	execve(path, cmd, NULL);
	write(2, "Second argument of path is invalid\n", 35);
	which_fd_to_close(child, data);
	free_split(cmd);
	free(path);
	exit(EXIT_SUCCESS);
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
