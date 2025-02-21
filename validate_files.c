/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:38:02 by jtran             #+#    #+#             */
/*   Updated: 2025/02/07 08:38:19 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	is_dir(char *av)
{
	write_bash();
	ft_putstr_err(av);
	write(2, ": Is a directory\n", 17);
}

int	validate_infile(char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		if(errno == EISDIR)
			is_dir(av);
		else if (av[0] == '\0')
		{
			no_such_file_infile(av);
			return(-1);
		}
		else if (errno == ENOENT)
			no_such_file_infile(av);
		else if (errno == EACCES)
			permission_denied(av);
		else
			perror("Error opening infile\n");
	}
	return (fd);
}

int	validate_outfile(char *av)
{
	int	fd;
	int i;

	i = 0;
	fd = open(av, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if(fd == -1)
	{
		while(i < 100000)
			i++;
		if(errno == EISDIR)
			is_dir(av);
		else if(errno == EACCES)
			permission_denied(av);
		else if(av[0] == '\0')
		{
			write(2, "-pipex: : No such file or directory\n", 36);
			return(-1);
		}
		else
			perror("Error opening outfile\n");
	}
	return(fd);
}
