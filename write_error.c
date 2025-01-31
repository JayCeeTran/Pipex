#include "pipex.h"

void	ft_putstr_err(char *argv)
{
	while(*argv)
	{
		write(2, argv, 1);
		argv++;
	}
}

void write_bash(void)
{
	write(2, "-bash: ", 7);
}

void	permission_denied(char *argv)
{
	write_bash();
	ft_putstr_err(argv);
	write(2, ": Permission denied\n", 20);
}

void	no_such_file_infile(char *argv)
{
	write_bash();
	ft_putstr_err(argv);
	write(2, ": No such file or directory\n", 28);
}

void	command_not_found(char **cmd, t_fds *data, int child)
{
	which_fd_to_close(child, data);
	ft_putstr_err(cmd[0]);
	write(2, ": command not found\n", 20);
	free_split(cmd);
	free_split(data->envp);
	exit(127);
}
