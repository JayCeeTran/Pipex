/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:02:50 by jtran             #+#    #+#             */
/*   Updated: 2025/01/29 13:27:00 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    **find_path(char **env)
{
    int i;
    char **path;
    
    i = 0;
    while(env[i])
    {
        if(ft_strncmp("PATH=", env[i], 5) == 0)
        { 
              path = ft_split(env[i] + 5, ':');
              break;
        }    
        i++;
    }
    if(!env[i])
    {
        write(2, "Error\nNo path found\n", 20);
        exit(EXIT_FAILURE);
    }
    return(path);
}

/*void    execute_permission(char *path)
{
    if (access(path, X_OK) == -1)
    {
        free(path);
        write(2, "Permission denied\n", 18);
        exit(126);
    }
}   
void    no_exe_file(char *path)
{
    free(path);
    
}

char *find_correct_bin(char *av, char **path)
{
    char *path_exe;
    char *slash;
    int i;

    i = 0;
    while(path[i])
    {
        slash = ft_strjoin(path[i], "/");
        path_exe = ft_strjoin(slash, av);
        free(slash);
        if(access(path_exe, F_OK) == 0)
        {
            execute_permission(path_exe);
            return(path_exe);
        }
 
        
    }

}*/