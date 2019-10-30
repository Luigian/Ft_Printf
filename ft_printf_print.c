/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:25:58 by lusanche          #+#    #+#             */
/*   Updated: 2019/10/29 21:46:08 by lusanche         ###   ########.fr       */
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
			return (ft_itoa_base(va_arg(ap, int), 10));
		else if (cs->len == 3)
			return (ft_itoa_base(va_arg(ap, long), 10));
		else if (cs->len == 4)
			return (ft_itoa_base(va_arg(ap, long long), 10));
	}
	if (*cs->ptr == 'u')
	{
		if (cs->len < 3)
			return (ft_itoa_base(va_arg(ap, unsigned int), 10));
		else if (cs->len == 3)
			return (ft_itoa_base(va_arg(ap, unsigned long), 10));
		else if (cs->len == 4)
			return (ft_itoa_base(va_arg(ap, unsigned long long), 10));
	}
	if (*cs->ptr == 'o')
	{
		if (cs->len < 3)
			return (ft_itoa_base(va_arg(ap, unsigned int), 8));
		else if (cs->len == 3)
			return (ft_itoa_base(va_arg(ap, unsigned long), 8));
		else if (cs->len == 4)
			return (ft_itoa_base(va_arg(ap, unsigned long long), 8));
	}
	if (*cs->ptr == 'x'/* || *cs->ptr == 'X'*/)
	{
		if (cs->len < 3)
			return (ft_itoa_base(va_arg(ap, unsigned int), 16));
		else if (cs->len == 3)
			return (ft_itoa_base(va_arg(ap, unsigned long), 16));
		else if (cs->len == 4)
			return (ft_itoa_base(va_arg(ap, unsigned long long), 16));
	}
	return("[error]");
}

int		print_type(va_list ap, t_cs *cs)
{
	char	*str;

	str = get_string(ap, cs);
//	printf("break01\n");
	*cs->ptr == 'o' ? str = hash(str, cs) : 0;
	str = precision(str, cs);
	*cs->ptr == 'x' ? str = hash(str, cs) : 0;
	str = plus_and_space(str, cs);
	str = minimum_and_minus(str, cs);
	ft_putstr(str);
	free(str);
	return (0);
}
