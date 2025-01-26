/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:09:09 by jtran             #+#    #+#             */
/*   Updated: 2024/10/31 11:09:13 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	chr;

	p = (unsigned char *) ptr;
	chr = (unsigned char) c;
	while (n--)
	{
		if (*p == chr)
			return (p);
		p++;
	}
	return (NULL);
}
