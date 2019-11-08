/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:25:58 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/08 11:52:14 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_string(va_list ap, t_cs *cs)
{
	char *str;
	char c;
	char	ch;
	short	sh;
	unsigned char	uch;
	unsigned short	ush;
	
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
		if (cs->len == 0)
			return (ft_itoa_base(va_arg(ap, int), 10, cs));
		else if (cs->len == 3)
			return (ft_itoa_base(va_arg(ap, long), 10, cs));
		else if (cs->len == 4)
			return (ft_itoa_base(va_arg(ap, long long), 10, cs));
	}
	if (*cs->ptr == 'u' || *cs->ptr == 'U')
	{
		if (cs->len == 1)
		{
			uch = (unsigned char)va_arg(ap, unsigned int);
			return (ft_itoa_base_uns(uch, 10, cs));
		}	
		if (cs->len == 2)
		{
			ush = (unsigned short)va_arg(ap, unsigned int);
			return (ft_itoa_base_uns(ush, 10, cs));
		}
		if (cs->len == 0)
			return (ft_itoa_base_uns(va_arg(ap, unsigned int), 10, cs));
		else if (cs->len == 3)
			return (ft_itoa_base_uns(va_arg(ap, unsigned long), 10, cs));
		else if (cs->len == 4)
			return (ft_itoa_base_uns(va_arg(ap, unsigned long long), 10, cs));
	}
	if (*cs->ptr == 'o')
	{
		if (cs->len == 1)
		{
			uch = (unsigned char)va_arg(ap, unsigned int);
			return (ft_itoa_base_uns(uch, 8, cs));
		}	
		if (cs->len == 2)
		{
			ush = (unsigned short)va_arg(ap, unsigned int);
			return (ft_itoa_base_uns(ush, 8, cs));
		}
		if (cs->len == 0)
			return (ft_itoa_base_uns(va_arg(ap, unsigned int), 8, cs));
		else if (cs->len == 3)
			return (ft_itoa_base_uns(va_arg(ap, unsigned long), 8, cs));
		else if (cs->len == 4)
			return (ft_itoa_base_uns(va_arg(ap, unsigned long long), 8, cs));
	}
	if (*cs->ptr == 'x' || *cs->ptr == 'X')
	{
		if (cs->len == 1)
		{
			uch = (unsigned char)va_arg(ap, unsigned int);
			return (ft_itoa_base_uns(uch, 16, cs));
		}	
		if (cs->len == 2)
		{
			ush = (unsigned short)va_arg(ap, unsigned int);
			return (ft_itoa_base_uns(ush, 16, cs));
		}
		if (cs->len == 0)
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
			cs->type = 0;
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
	if (*cs->ptr == 'f' || *cs->ptr == 'e' || *cs->ptr == 'g')
	{
		if (cs->ext)
			return (ft_itoa_float(va_arg(ap, long double), cs));
		else
			return (ft_itoa_float(va_arg(ap, double), cs));
	}
	c = *cs->ptr;
	return (ft_memset(ft_strnew(1), c, 1));
}

void	ft_putstr_null(char *str)
{
	while (*str)
	{
		while (*str && *str != '^')
		{
			ft_putchar(*str);
			++str;
		}
		if (*str == '^')
		{
			ft_putchar(0);
			str += 2;
		}
	}
}

int		print_type(va_list ap, t_cs *cs)
{
	char	*str;

	
//	printf("%c\n", *cs->ptr);
	str = get_string(ap, cs);
//	printf("%c\n", *cs->ptr);
	*cs->ptr == 'o' ? str = hash(str, cs) : 0;
	str = precision(str, cs);
	*cs->ptr == 'x' || *cs->ptr == 'X' ||\
		*cs->ptr == 'p' ? str = hash(str, cs) : 0;
	str = plus_and_space(str, cs);
	str = minimum_and_minus(str, cs);
	if (!cs->type)
		ft_putstr_null(str);
	else
		ft_putstr(str);
	cs->ret += ft_strlen(str);
	free(str);
	return (0);
}
