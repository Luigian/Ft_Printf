/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_cspdi.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:25:58 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/24 11:41:14 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_decimal(t_cs *cs)
{
	long long	lonlon;
	char	 	*str;

	cs->flag['#'] = 0;	
	lonlon = va_arg(cs->ap, long long);
	if (cs->len == 1)
		str = ft_itoa_base((char)lonlon, 10, cs);
	else if (cs->len == 2)
		str = ft_itoa_base((short)lonlon, 10, cs);
	else if (cs->len == 3)
		str = ft_itoa_base((long)lonlon, 10, cs);
	else if (cs->len == 4)
		str = ft_itoa_base(lonlon, 10, cs);
	else 
		str = ft_itoa_base((int)lonlon, 10, cs);
	str = precision(str, cs);
	str = plus_and_space(str, cs);
	str = minimum_and_minus(str, cs);
	if (cs->flag['\''])
		str = thousands_separation(str);
	ft_putstr(str);
	return (str);
}

char	*print_pointer(t_cs *cs)
{
	char	*str;
	
	cs->flag[' '] = 0;	
	cs->flag['+'] = 0;	
	cs->flag['#'] = 1;	
	str = ft_itoa_base((long long)va_arg(cs->ap, void *), 16, cs);
	str = precision(str, cs);
	str = ft_strjoin_2("0x", str, 2);
	str = minimum_and_minus(str, cs);
	ft_putstr(str);
	return (str);
}

char	*print_string(t_cs *cs)
{
	char 	*s;
	char 	*str;
	char 	*new;

	cs->flag[' '] = 0;	
	cs->flag['+'] = 0;	
	s = va_arg(cs->ap, char *);
	if (!s)
		str = ft_strcpy(ft_strnew(6), "(null)");
	else
		str = ft_strjoin("", s);
	if (cs->preci < 0)
		str = precision(str, cs);
	else
	{
		new = ft_strncpy(ft_strnew(cs->preci), str, cs->preci);
		if (cs->flag['0'] && !cs->flag['-'])
			new = zero(new, cs);
		free(str);
		str = new;
	}
	str = minimum_and_minus(str, cs);
	ft_putstr(str);
	return (str);
}

char	*print_char(t_cs *cs)
{
	char	 c;
	char	*str;
	
	cs->preci = -1;
	cs->flag[' '] = 0;	
	cs->flag['+'] = 0;	
	c = va_arg(cs->ap, unsigned int);
	if (c == 0)
	{
		cs->minwid += 1;
		str = ft_strcpy(ft_strnew(2), "^@");
		str = precision(str, cs);
		str = minimum_and_minus(str, cs);
		put_char_null(str);
		cs->ret -= 1;
		return (str);
	}
	str = ft_memset(ft_strnew(1), c, 1);
	str = precision(str, cs);
	str = minimum_and_minus(str, cs);
	ft_putstr(str);
	return (str);
}	

char	*print_other(t_cs *cs)
{
	char	 c;
	char	*str;

	cs->preci = -1;
	cs->flag[' '] = 0;	
	cs->flag['+'] = 0;	
	c = *cs->ptr;
	str = ft_memset(ft_strnew(1), c, 1);
	str = precision(str, cs);
	str = minimum_and_minus(str, cs);
	ft_putstr(str);
	return (str);
}
