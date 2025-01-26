/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:56:41 by jtran             #+#    #+#             */
/*   Updated: 2024/10/31 11:56:46 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	srclen;
	size_t	destlen;

	if ((!src || !dest) && n == 0)
		return (0);
	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
	i = destlen;
	if (n <= destlen)
		return (n + srclen);
	while (*src && i < (n - 1))
		dest[i++] = *src++;
	dest[i] = '\0';
	return (srclen + destlen);
}
