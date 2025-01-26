/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:51:55 by jtran             #+#    #+#             */
/*   Updated: 2024/11/08 13:08:20 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int		i;
	long	num;

	i = 0;
	num = n;
	if (num <= 0)
		i++;
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long long	j;

	j = n;
	i = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (j < 0)
	{
		str[0] = '-';
		j = -j;
	}
	if (n == 0)
		str[0] = '0';
	while (j > 0)
	{
		str[i--] = (j % 10) + '0';
		j /= 10;
	}
	return (str);
}
