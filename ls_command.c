#include "pipex.h"

void    exec_ls(char **av, t_fds *data, int i);

void	command_ls(char **av, int ac, t_fds *data)
{
	int i;

	i = 2;
	while(av[i] && i < ac - 1)
	{
		if(ft_strncmp("ls", av[i], 2) == 0 && ft_strlen(av[i]) == 2)
		{
			if(access(".", R_OK) == 0)
				data->fd[0] = open(".", O_RDONLY);
			exec_ls(av, data, i);
		}
		i++;
	}
}

void	exec_ls(char **av, t_fds *data, int i)
{
	int pid;
	char **cmd;
	char *path;

	cmd = ft_split(av[i], ' ');
	if(!cmd)
		failed_malloc(data, 0);
	path = find_correct_bin(cmd, data, 0);
	if(!path)
		command_not_found(cmd, data, 0);
	pid = fork();
	if(pid == -1)
		fork_error(cmd, path, data, 0);
	if(pid == 0)
	{
		dup2(data->fd[0], 0);
		dup2(data->fd[1], 1);
		execute_command(cmd, path, data, 0);
	}
	free_all(cmd, data->envp, path);
	close_fds(data->fd);
	wait(NULL);
	exit(0);
}

int	is_there_ls(char **av, int ac, t_fds *data)
{
	int i;

	i = 2;
	while(av[i] && i < ac - 1)
	{
		if(ft_strncmp("ls", av[i], 2) == 0 && ft_strlen(av[i]) == 2)
		{
			if(access(".", R_OK) == 0)
				data->fd[0] = open(".", O_RDONLY);
			return(1);
		}
		i++;
	}
	return(0);
}
