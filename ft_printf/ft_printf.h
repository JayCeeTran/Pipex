/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:23:24 by jtran             #+#    #+#             */
/*   Updated: 2024/11/25 15:23:27 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putc(char c, int fd);
int	ft_put_us_hex(unsigned int n, char *basel, int c);
int	ft_put_p(unsigned long long n);
int	ft_putnbr(int n, int fd);
int	ft_putstr_f(void *s, int fd);
int	ft_putstr(char *s, int fd);
int	ft_printf(const char *s, ...);

#endif
