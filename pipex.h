/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:01:11 by jtran             #+#    #+#             */
/*   Updated: 2025/02/07 09:17:49 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_data
{
	int		fd[2];
	int		pipe[2];
	char	**env;
	pid_t	pid1;
	pid_t	pid2;
	int		status;
}			t_data;

void		store_ac_env_to_struct(t_data *data, char **env);
int			space_only_commands(char *av);
char		*find_correct_bin(t_data *data, char **cmd);
char		*path_as_command(t_data *data, char **cmd);
void		execute_command(t_data *data, char **cmd, char *path, char **ev);
int			validate_outfile(char *av);
int			validate_infile(char *av);
void		child1(t_data *data, char **av, char **ev);
void		child2(t_data *data, char **av, char **ev);
/**
***		ERROR MESSAGES!!!
**/
void		execute_permission(t_data *data, char **cmd, char *path);
void		fork_error(t_data *data);
void		pipe_failed(char **env);
void		too_few_arguments(void);
void		failed_malloc(t_data *data);
void		command_not_found(t_data *data, char **cmd, char *av);
void		no_such_file_infile(char *argv);
void		permission_denied(char *argv);
/**
***		CLOSING AND FREEING!!!
**/
void		close_fds(int *fd);
void		close_fd_pipe(int *pipefd, int *fd);
void		free_split(char **commands);
void		free_all(char **cmd, char **envp, char *path);
void		create_out_exit(t_data *data, char *av, int exitcode);
void		free_close_exit(t_data *data, char **cmd, char *path);
void		free_exit(t_data *data);

#endif
