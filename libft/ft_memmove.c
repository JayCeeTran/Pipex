/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:21:14 by jtran             #+#    #+#             */
/*   Updated: 2024/11/08 14:21:14 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destptr;
	const unsigned char	*srcptr;
	int					i;

	i = 0;
	destptr = (unsigned char *)dest;
	srcptr = (const unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (n == 0)
		return (dest);
	if (dest > src)
	{
		while (n)
		{
			destptr[n - 1] = srcptr[n - 1];
			n--;
		}
	}
	while (n--)
	{
		destptr[i] = srcptr[i];
		i++;
	}
	return (dest);
}
