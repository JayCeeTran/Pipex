/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:36:15 by jtran             #+#    #+#             */
/*   Updated: 2024/11/12 15:40:44 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_ch(const char *str, int c)
{
	int	charcount;

	charcount = 0;
	while (*str != '\0')
	{
		if ((unsigned char) *str == (unsigned char) c)
			charcount++;
		str++;
	}
	return (charcount);
}

char	*ft_strrchr(const char *str, int chr)
{
	int	pos_of_last_ch;
	int	i;

	i = 0;
	pos_of_last_ch = count_ch(str, chr);
	if (chr == '\0')
		return ((char *) &str[ft_strlen(str)]);
	if (pos_of_last_ch == 0)
		return (NULL);
	while (str[i] != '\0')
	{
		if ((unsigned char) str[i] == (unsigned char) chr)
			pos_of_last_ch--;
		if (pos_of_last_ch == 0)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
