/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:37:23 by jtran             #+#    #+#             */
/*   Updated: 2024/11/27 15:29:57 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_symbol(const char **s, va_list args)
{
	if (**s == 'c')
		return (ft_putc(va_arg(args, int), 1));
	else if (**s == 's')
		return (ft_putstr_f(va_arg(args, void *), 1));
	else if (**s == 'p')
		return (ft_put_p(va_arg(args, unsigned long long)));
	else if (**s == 'i' || **s == 'd')
		return (ft_putnbr(va_arg(args, int), 1));
	else if (**s == 'u')
		return (ft_put_us_hex(va_arg(args, unsigned int), "0123456789", 'u'));
	else if (**s == 'x')
		return (ft_put_us_hex(va_arg(args, unsigned int), "0123456789abcdef",
				'x'));
	else if (**s == 'X')
		return (ft_put_us_hex(va_arg(args, unsigned int), "0123456789ABCDEF",
				'X'));
	if (**s == '%')
		return (write(1, "%", 1));
	return (-1);
}

static int	dutty_check(int *count, int check)
{
	if (check == -1)
		return (-1);
	(*count) += check;
	return (1);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	int		check;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			check = check_symbol(&s, args);
			if (dutty_check(&count, check) == -1)
				return (-1);
		}
		else
		{
			if (write(1, &*s, 1) == -1)
				return (-1);
			count ++;
		}
		s++;
	}
	va_end(args);
	return (count);
}
