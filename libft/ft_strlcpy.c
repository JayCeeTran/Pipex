/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:11:47 by jtran             #+#    #+#             */
/*   Updated: 2024/10/31 12:11:49 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	int		srclen;

	srclen = ft_strlen(src);
	i = 0;
	if (n == 0)
		return (srclen);
	while (src[i] && i < (n - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (srclen);
}

/*int main(void)
{
    char    string[12] = "hellooo";
    char    dest[40];
    ft_strlcpy(dest, string, 40);
    printf("%s\n", dest);
    printf("%lu\n", ft_strlcpy(dest, string, 50));
}*/
