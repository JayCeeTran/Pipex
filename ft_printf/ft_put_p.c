/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:37:43 by jtran             #+#    #+#             */
/*   Updated: 2024/11/26 16:01:07 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_p(unsigned long long n)
{
	unsigned long long	divider;
	int					count;
	int					check;

	count = 0;
	if (n == 0)
		return (write(1, "(nil)", 5));
	divider = 1;
	while (n / divider >= 16)
		divider *= 16;
	write(1, "0x", 2);
	count += 2;
	while (divider > 0)
	{
		if (n / divider <= 9)
			check = ft_putc(n / divider + 48, 1);
		else if (n / divider > 9)
			check = ft_putc(n / divider - 10 + 'a', 1);
		if (check == -1)
			return (count);
		n %= divider;
		divider /= 16;
		count++;
	}
	return (count);
}
