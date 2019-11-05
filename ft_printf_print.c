/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:25:58 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/04 21:44:35 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_string(va_list ap, t_cs *cs)
{
	char *str;
	char c;
	short	sh;
	char	ch;
	
	if (*cs->ptr == 'd' || *cs->ptr == 'i')
	{
		if (cs->len == 1)
		{
			ch = (char)va_arg(ap, int);
			return (ft_itoa_base(ch, 10, cs));
		}	
		if (cs->len == 2)
		{
			sh = (short)va_arg(ap, int);
			return (ft_itoa_base(sh, 10, cs));
		}
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
			return (ft_itoa_base_uns(va_arg(ap, unsigned int), 10, cs));
		else if (cs->len == 3)
			return (ft_itoa_base_uns(va_arg(ap, unsigned long), 10, cs));
		else if (cs->len == 4)
			return (ft_itoa_base_uns(va_arg(ap, unsigned long long), 10, cs));
	}
	if (*cs->ptr == 'o')
	{
		if (cs->len < 3)
			return (ft_itoa_base_uns(va_arg(ap, unsigned int), 8, cs));
		else if (cs->len == 3)
			return (ft_itoa_base_uns(va_arg(ap, unsigned long), 8, cs));
		else if (cs->len == 4)
			return (ft_itoa_base_uns(va_arg(ap, unsigned long long), 8, cs));
	}
	if (*cs->ptr == 'x' || *cs->ptr == 'X')
	{
		if (cs->len < 3)
			return (ft_itoa_base_uns(va_arg(ap, unsigned int), 16, cs));
		else if (cs->len == 3)
			return (ft_itoa_base_uns(va_arg(ap, unsigned long), 16, cs));
		else if (cs->len == 4)
			return (ft_itoa_base_uns(va_arg(ap, unsigned long long), 16, cs));
	}
	if (*cs->ptr == 'c')
	{
		c = va_arg(ap, unsigned int);
		if (c == 0)
		{	
			cs->minwid += 1;
			cs->ret -= 1;
			return (ft_strcpy(ft_strnew(2), "^@"));
		}
		else
			return (ft_memset(ft_strnew(1), c, 1));
	}	
	if (*cs->ptr == 's')
	{
		str = va_arg(ap, char *);
		if (!str)
			return (ft_strcpy(ft_strnew(6), "(null)"));
		return (ft_strjoin("", str));
	}
	if (*cs->ptr == 'p')
	{
		return (ft_itoa_base((long long)va_arg(ap, void *), 16, cs));
	}
	if (*cs->ptr == '%')
	{
		return (ft_memset(ft_strnew(1), '%', 1));
	}	
	if (*cs->ptr == 'f')
	{
		if (cs->ext)
			return (ft_itoa_float(va_arg(ap, long double), cs));
		else
			return (ft_itoa_float(va_arg(ap, double), cs));
	}
	return ("no type");
}

int		print_type(va_list ap, t_cs *cs)
{
	char	*str;

	
	str = get_string(ap, cs);
	*cs->ptr == 'o' ? str = hash(str, cs) : 0;
	str = precision(str, cs);
	*cs->ptr == 'x' || *cs->ptr == 'X' ||\
		*cs->ptr == 'p' ? str = hash(str, cs) : 0;
	str = plus_and_space(str, cs);
	str = minimum_and_minus(str, cs);
	ft_putstr(str);
	cs->ret += ft_strlen(str);
	free(str);
	return (0);
}
