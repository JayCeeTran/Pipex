/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:30:17 by jtran             #+#    #+#             */
/*   Updated: 2024/11/06 14:30:17 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *search, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!search[i])
		return ((char *)str);
	if ((!str || !search) && n == 0)
		return (0);
	while (str[i] && i < n)
	{
		j = 0;
		while (search[j] && (i + j) < n)
		{
			if (str[i + j] == search[j])
				j++;
			else
				break ;
		}
		if (search[j] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
