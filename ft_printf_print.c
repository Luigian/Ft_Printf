/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:25:58 by lusanche          #+#    #+#             */
/*   Updated: 2019/10/31 21:03:22 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_string(va_list ap, t_cs *cs)
{
/*	if (*cs->ptr == 'd' || *cs->ptr == 'i')
	{
		if (cs->len < 3)
			return (ft_itoa_long(va_arg(ap, int)));
		else if (cs->len == 3)
			return (ft_itoa_long(va_arg(ap, long)));
		else if (cs->len == 4)
			return (ft_itoa_long(va_arg(ap, long long)));
	}
	if (*cs->ptr == 'u')
	{
		if (cs->len < 3)
			return (ft_itoa_long(va_arg(ap, unsigned int)));
		else if (cs->len == 3)
			return (ft_itoa_long(va_arg(ap, unsigned long)));
		else if (cs->len == 4)
			return (ft_itoa_long(va_arg(ap, unsigned long long)));
	}*/
	if (*cs->ptr == 'd' || *cs->ptr == 'i')
	{
		if (cs->len < 3)
			return (ft_itoa_base(va_arg(ap, int), 10, cs));
		else if (cs->len == 3)
			return (ft_itoa_base(va_arg(ap, long), 10, cs));
		else if (cs->len == 4)
			return (ft_itoa_base(va_arg(ap, long long), 10, cs));
	}
	if (*cs->ptr == 'u')
	{
		if (cs->len < 3)
			return (ft_itoa_base(va_arg(ap, unsigned int), 10, cs));
		else if (cs->len == 3)
			return (ft_itoa_base(va_arg(ap, unsigned long), 10, cs));
		else if (cs->len == 4)
			return (ft_itoa_base(va_arg(ap, unsigned long long), 10, cs));
	}
	if (*cs->ptr == 'o')
	{
		if (cs->len < 3)
			return (ft_itoa_base(va_arg(ap, unsigned int), 8, cs));
		else if (cs->len == 3)
			return (ft_itoa_base(va_arg(ap, unsigned long), 8, cs));
		else if (cs->len == 4)
			return (ft_itoa_base(va_arg(ap, unsigned long long), 8, cs));
	}
	if (*cs->ptr == 'x' || *cs->ptr == 'X')
	{
		if (cs->len < 3)
			return (ft_itoa_base(va_arg(ap, unsigned int), 16, cs));
		else if (cs->len == 3)
			return (ft_itoa_base(va_arg(ap, unsigned long), 16, cs));
		else if (cs->len == 4)
			return (ft_itoa_base(va_arg(ap, unsigned long long), 16, cs));
	}
	if (*cs->ptr == 'c')
	{
		return (ft_memset(ft_strnew(1), va_arg(ap, unsigned int), 1));
	}	
	if (*cs->ptr == 's')
	{
		return (ft_strjoin("", va_arg(ap, char *)));
	}
	if (*cs->ptr == 'p')
	{
		return (ft_itoa_base((long long)va_arg(ap, void *), 16, cs));
	}
	if (*cs->ptr == '%')
	{
		return (ft_memset(ft_strnew(1), '%', 1));
	}	
	return ("no type");
}

int		print_type(va_list ap, t_cs *cs)
{
	char	*str;

	str = get_string(ap, cs);
	*cs->ptr == 'o' ? str = hash(str, cs) : 0;
	str = precision(str, cs);
	*cs->ptr == 'x' || *cs->ptr == 'X' || *cs->ptr == 'p' ? str = hash(str, cs) : 0;
	str = plus_and_space(str, cs);
	str = minimum_and_minus(str, cs);
	ft_putstr(str);
	free(str);
	return (0);
}
