/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:05:54 by jtran             #+#    #+#             */
/*   Updated: 2024/11/12 15:37:28 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int search_str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((unsigned char) str[i] == ((unsigned char) search_str))
			return ((char *)&str[i]);
		i++;
	}
	if (search_str == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
