/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:18:19 by lusanche          #+#    #+#             */
/*   Updated: 2019/10/19 09:18:10 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_print_argument(va_list ap, const char *fmt)
{
	char	c;
	char	*s;
	int		d;
	
	if (*fmt == 'c')
	{
		c = va_arg(ap, int);
		ft_putchar(c);
	}
	else if (*fmt == 's')
	{
		s = va_arg(ap, char *);
		ft_putstr(s);
	}
	else if (*fmt == 'd')
	{
		d = va_arg(ap, int);
		ft_putnbr(d);
	}
	return (0);
}
	
int		ft_printf(const char *fmt, ...)
{
	int			ret;
	va_list		ap;
	
	ret = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			++fmt;
			ft_print_argument(ap, fmt);
		}	
		else
		{
			ft_putchar(*fmt);
			++ret;
		}
		++fmt;
	}
	va_end(ap);
	return (ret);
}
