/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:15:58 by jtran             #+#    #+#             */
/*   Updated: 2024/11/26 16:30:24 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	dutty_loop(int divider, int n, int *count, int fd)
{
	int	check;

	while (divider > 0)
	{
		check = ft_putc(n / divider + '0', fd);
		if (check == -1)
		{
			(*count) = check;
			break ;
		}
		n %= divider;
		divider /= 10;
		(*count)++;
	}
}

int	ft_putnbr(int n, int fd)
{
	int	divider;
	int	count;

	count = 0;
	divider = 1;
	if (n == -2147483648)
	{
		count = write(fd, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		ft_putc('-', fd);
		n *= (-1);
		count++;
	}
	while (n / divider > 9)
		divider *= 10;
	dutty_loop(divider, n, &count, fd);
	return (count);
}
