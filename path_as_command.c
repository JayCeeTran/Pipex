/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_as_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:17:37 by jtran             #+#    #+#             */
/*   Updated: 2025/02/07 09:17:41 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_as_command(t_data *data, char **cmd)
{
	if (access(cmd[0], F_OK) == 0)
	{
		if (access(cmd[0], X_OK) == 0)
			return (cmd[0]);
		else
			execute_permission(data, cmd, NULL);
	}
	return (NULL);
}
