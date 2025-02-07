/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:02:20 by jtran             #+#    #+#             */
/*   Updated: 2025/02/04 09:02:23 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **commands)
{
	int	i;

	i = 0;
	if (!commands)
		return ;
	while (commands[i])
		free(commands[i++]);
	free(commands);
}

void	free_all(char **cmd, char **envp, char *path)
{
	free_split(cmd);
	free_split(envp);
	free(path);
}
