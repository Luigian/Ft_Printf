/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:18:19 by lusanche          #+#    #+#             */
/*   Updated: 2019/10/25 21:58:35 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		is_scape_secuence(char c)
{
	return (c == '\a' || c == '\b' || c == '\f'\
			|| c == '\n' || c == '\r' || c == '\t'
			|| c == '\v' || c == '\'' || c == '\\');
}

int		is_type_of_conversion(char c)
{
	return (c == 'c' || c == 's' || c == 'p'\
			|| c == 'd' || c == 'i' || c == 'o'
			|| c == 'u' || c == 'x' || c == 'X'\
			|| c == 'f');
}
	
int		is_format_specificator(char c)
{
	return (c == '#' || c == '0' || c == '-'\
			|| c == ' ' || c == '+' || is_digit(c)\
			|| c == '.' || c == 'h' || c == 'l'\
			|| c == 'L');
}

int		store_conv_specs(fmt, conSpec)
{
	while (is_format_specificator(*fmt))
	{
	}
	if (is_type_of_conversion(*fmt))
	{
	}
	else if (is_scape_secuence(*fmt))
	{
	}
	else if (*fmt)
	{
	}
	else
		return (1);
	return (0);
}

t_cS	*create_cs_object(void)
{
	t_cs	*conSpec;

	if (!(conSpec = (t_cs *)malloc(sizeof(t_cs) * 1)))
		return (NULL);
	convSpec->hash = 0;
	convSpec->zero = 0;
	convSpec->minusSym = 0;
	convSpec->space = 0;
	convSpec->plusSym = 0;
	convSpec->miniWid = 0;
	convSpec->precis = 0;
	convSpec->lenMod = 0;
	convSpec->extPre = 0;
	convSpec->typeCon = 0;
	convSpec->scapeSec = 0;
	convSpec->otherChar = 0;
	return (conSpec);
}

int		ft_print_argument(va_list ap, const char *fmt)
{
	t_cs	conSpec;
	
	
	conSpec = create_cs_object();
	store_conv_specs(fmt, conSpec);
	
	
/*	
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
*/	
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
