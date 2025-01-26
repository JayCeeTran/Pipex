#include "pipex.h"

void    failed_malloc(int *pipefd, int *fd)
{
    close_fd_pipe(pipefd, fd);
    write(2, "Failed to malloc command strings\n", 33);
    exit(EXIT_FAILURE);
}

void    path_failed_malloc(char **cmd, int *pipefd, int *fd)
{
    close_fd_pipe(pipefd, fd);
    free_split(cmd);
    write(2, "Failed to malloc path string\n", 29);
    exit(EXIT_FAILURE);
}

void    invalid_argument(void)
{
    errno = EINVAL;
    perror("Error\n");
    exit(1);
}
