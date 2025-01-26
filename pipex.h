#ifndef PIPEX_H
# define PIPEX_H


# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>

void	free_split(char **argv);
void	invalid_argument(void);
void	failed_malloc(int *pipefd, int *fd);
void    path_failed_malloc(char **cmd, int *pipefd, int *fd);
void	fd_open_fail(int *fd);
void	pipe_failed(int *fd);
void	close_fds(int *fd);
void	close_pipefd(int *pipefd);
void	close_fd_pipe(int *pipefd, int *fd);
int		even(int n);
void	first_child(char *argv, int *pipefd, int *fd);
void	mid_child(char *argv, int *pipe1, int *pipe2);	
void	last_child(char *argv, int *pipefd, int *fd);
int		loop_mid(char **argv, int *pipe1, int *fd, int ac);
#endif
