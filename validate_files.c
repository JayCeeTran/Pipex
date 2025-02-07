#include "pipex.h"

int	validate_infile(char *av)
{
	int fd;

    if (access(av, R_OK) == -1)
    {
        if (errno == ENOENT)
            no_such_file_infile(av);
        else if (errno == EACCES)
            permission_denied(av);
        return (-1);
    }
    else
        fd = open(av, O_RDONLY);
    return (fd);
}

int validate_outfile(t_data *data, char *av)
{
	int fd;

    if (access(av, W_OK) == -1)
    {
        if (errno == ENOENT)
        {
			fd = open(av, O_CREAT | O_WRONLY | O_EXCL, 0664);
			if(fd == -1)
				perror("Error\n");
            return (fd);
        }
        else if (errno == EACCES)
        {
            permission_denied(av);
            data->permission = 1;
			return(-1);
        }
    }
    fd = open(av, O_WRONLY | O_TRUNC);
	if(fd == -1)
		perror("Error\n");
    return (fd);
}
