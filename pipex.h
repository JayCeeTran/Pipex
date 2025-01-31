#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>

typedef struct s_fds{
	int fd[2];
	int pipe1[2];
	int pipe2[2];
	char **envp;
} t_fds;

typedef struct s_pointers{
	int *cur_pipe;
	int *newpipe;
	int *temp;
} t_pointers ;

//int		count_ac(char **argv);
int is_there_ls(char **av, int ac, t_fds *data);
void	free_split(char **argv);
void	free_all(char **cmd, char **envp, char *path);
void	invalid_argument(void);
void	failed_malloc(t_fds *data, int child);
void	permission_denied(char *argv);
void	no_such_file_infile(char *argv);
void	command_not_found(char **cmd, t_fds *data, int child);
void	too_few_arguments(void);
void	check_command_arguments(char **argv, int *fd, int ac);
void	ft_putstr_err(char *argv);
void    path_failed_malloc(char **cmd, t_fds *data, int child);
void	fd_open_fail(int *fd);
void	pipe_failed(int *pipe1, int *fd, char **envp);
void    fork_error(char **cmd, char *path, t_fds *data, int child);

/**
***		CLOSING FDS FUNCTIONS
**/
void	which_fd_to_close(int child, t_fds *data);
void	close_fds(int *fd);
void	close_pipefd(int *pipefd);
void	close_fd_pipe(int *pipefd, int *fd);
char	*find_correct_bin(char **cmd, t_fds *data, int child);
void	execute_command(char **cmd, char *path, t_fds *data, int child);
/**
***		CHILDREN FUNCTIONS
**/
void	command_ls(char **av, int ac, t_fds *data);
void	first_child(char *argv, t_fds *data);
void	mid_child(char *argv, t_fds *data, t_pointers *pipe);	
void	last_child(char *argv, t_fds *data, int *pipe);
void	last_child_no_mid(char *argv, t_fds *data, int *pipe);
int		loop_mid(char **argv, t_fds *data, int ac);
void    find_path(char **env, t_fds *data);
#endif
