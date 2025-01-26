/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:06:27 by jtran             #+#    #+#             */
/*   Updated: 2024/11/26 15:57:21 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_f(void *s, int fd)
{
	int		count;
	char	*c;
	int		check;

	check = 0;
	c = (char *)s;
	if (s == NULL)
	{
		check = write(1, "(null)", 6);
		return (check);
	}
	count = 0;
	while (*c)
	{
		check = write(fd, c, 1);
		if (check == -1)
			return (check);
		c++;
		count++;
	}
	return (count);
}
