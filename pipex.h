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
void	permission_denied(char *argv);
void	no_such_file_infile(char *argv);
void	command_not_found(char *argv);
void	too_few_arguments(void);
void	check_command_arguments(char **argv, int *fd, int ac);
void	ft_putstr_err(char *argv);
void    path_failed_malloc(char **cmd, int *pipefd, int *fd);
void	fd_open_fail(int *fd);
void	pipe_failed(int *pipe1, int *fd);
void	close_fds(int *fd);
void	close_pipefd(int *pipefd);
void	close_fd_pipe(int *pipefd, int *fd);
void	execute_command(char **cmd, char *path, int *fd);
void	first_child(char *argv, int *pipefd, int *fd, char **path);
void	mid_child(char *argv, int *pipe1, int *pipe2, int *fd);	
void	last_child(char *argv, int *pipefd, int *fd);
int		loop_mid(char **argv, int *pipe1, int *fd, int ac);

char    **find_path(char **env);
#endif
