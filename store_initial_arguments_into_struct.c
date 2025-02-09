/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_initial_arguments_into_struct.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:37:59 by jtran             #+#    #+#             */
/*   Updated: 2025/02/07 08:37:59 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	find_path(t_data *data, char **env);

void	store_ac_env_to_struct(t_data *data, char **env)
{
	find_path(data, env);
}

void	find_path(t_data *data, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
		{
			data->env = ft_split(env[i] + 5, ':');
			if (!data->env)
			{
				write(2, "Error\nFailed to malloc envp\n", 28);
				exit(EXIT_FAILURE);
			}
			break ;
		}
		i++;
	}
	if (!env[i])
	{
		write(2, "Error\nNo envp found\n", 20);
		exit(EXIT_FAILURE);
	}
}
