/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:01:45 by jtran             #+#    #+#             */
/*   Updated: 2025/02/07 08:38:12 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putstr_err(char *av)
{
	while (*av)
	{
		write(2, av, 1);
		av++;
	}
}

void	write_bash(void)
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

void	command_not_found(t_data *data, char **cmd, char *av)
{
	ft_putstr_err(cmd[0]);
	write(2, ": command not found\n", 20);
	free_split(cmd);
	create_out_exit(data, av, 127);
}
