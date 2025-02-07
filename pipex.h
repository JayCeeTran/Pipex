/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:01:11 by jtran             #+#    #+#             */
/*   Updated: 2025/02/05 13:47:09 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_data{
	int		fd[2];
	int		pipe[2];
	int		ac;
	char	**env;			
	pid_t	pid1;
	pid_t	pid2;
	int		status;
}			t_data;

void    store_ac_env_to_struct(t_data *data, int ac, char **env);
int    space_only_commands(char *av);
char    *find_correct_bin(t_data *data, char **cmd);
void    execute_command(t_data *data, char **cmd, char *path, int i);
int		validate_outfile(t_data *data, char *av);
int		validate_infile(char *av);
void    child1(t_data *data, char **av);
void    child2(t_data *data, char **av);
/**
***		ERROR MESSAGES!!!
**/
void    fork_error(t_data *data);
void    pipe_failed(char **env);
void	too_few_arguments(void);
void    failed_malloc(t_data *data);
void    command_not_found(t_data *data, char **cmd, char *av);
void    no_such_file_infile(char *argv);
void    permission_denied(char *argv);

/**
***		CLOSING AND FREEING!!!
**/
void	close_fds(int *fd);
void	close_fd_pipe(int *pipefd, int *fd);
void    free_split(char **commands);
void    free_all(char **cmd, char **envp, char *path);
void    create_out_exit(t_data *data, char *av, int exitcode);
void	free_close_exit(t_data *data, char **cmd, char *path);
void    free_exit(t_data *data);
/*int			is_there_ls(char **av, int ac, t_fds *data);
void		free_split(char **argv);
void		free_all(char **cmd, char **envp, char *path);
void		invalid_argument(void);
void		failed_malloc(t_fds *data, int child);
void		permission_denied(char *argv);
void		no_such_file_infile(char *argv);
void		command_not_found(char **cmd, t_fds *data, int child);
void		too_few_arguments(void);
void		check_command_arguments(char **argv, int *fd, int ac);
void		ft_putstr_err(char *argv);
void		path_failed_malloc(char **cmd, t_fds *data, int child);
void		fd_open_fail(int *fd);
void		fd_open_fail_out(int *fd);
void		pipe_failed(int *pipe1, int *fd, char **envp);
void		fork_error(char **cmd, char *path, t_fds *data, int child);
char		*find_correct_bin(char **cmd, t_fds *data, int child);
void		which_fd_to_close(int child, t_fds *data);
void		close_fds(int *fd);
void		close_pipefd(int *pipefd);
void		close_fd_pipe(int *pipefd, int *fd);
void		execute_command(char **cmd, char *path, t_fds *data, int child);
void		command_ls(char **av, int ac, t_fds *data);
void		first_child(char *argv, t_fds *data);
void		mid_child(char *argv, t_fds *data, t_pointers *pipe);
void		last_child(char *argv, t_fds *data, int *pipe);
void		last_child_no_mid(char *argv, t_fds *data, int *pipe);
int			loop_mid(char **argv, t_fds *data, int ac);
void		find_path(char **env, t_fds *data);
*/

#endif
