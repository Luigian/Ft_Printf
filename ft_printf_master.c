/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_master.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:18:19 by lusanche          #+#    #+#             */
/*   Updated: 2019/10/26 21:55:56 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		store_conversion_specs(t_cs *cs)
{
	while (is_format_specificator(*(cs->ptr)))
	{
		if (is_flag_spec(*(cs->ptr)))
			store_flag_value(cs);
		else if (is_decimal_spec(*(cs->ptr)))
			store_decimal_value(cs);
		else if (is_length_spec(*(cs->ptr)))
			store_length_value(cs);
	}
	if (is_type_specificator(*(cs->ptr)))
		cs->type = *(cs->ptr);
	else if (is_scape_specificator(*(cs->ptr)))
		cs->scape = *(cs->ptr);
	else if (*(cs->ptr))
		cs->other = *(cs->ptr);
	else
		return (1);
	++(cs->ptr);
	return (0);
}

void	reset_object(t_cs *cs)
{
	cs->hash = 0;
	cs->zero = 0;
	cs->minus = 0;
	cs->space = 0;
	cs->plus = 0;
	cs->minwid = 0;
	cs->preci = 0;
	cs->len = 0;
	cs->ext = 0;
	cs->type = 0;
	cs->scape = 0;
	cs->other = 0;
}

t_cs	*create_object(const char *fmt)
{
	t_cs	*cs;

	if (!(cs = (t_cs *)malloc(sizeof(t_cs) * 1)))
		return (NULL);
/*	cs->hash = 0;
	cs->zero = 0;
	cs->minus = 0;
	cs->space = 0;
	cs->plus = 0;
	cs->minwid = 0;
	cs->preci = 0;
	cs->len = 0;
	cs->ext = 0;
	cs->type = 0;
	cs->scape = 0;
	cs->other = 0;
*/	cs->ptr = fmt;
	return (cs);
}

int		print_argument(/*va_list ap,*/ t_cs *cs)
{
	reset_object(cs);
	store_conversion_specs(cs);
	
	
	
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
	t_cs		*cs;
//	va_list		ap;
	int			ret;
	
	if (!(cs = create_object(fmt)))
		exit (-1);
//	va_start(ap, fmt);
	ret = 0;
	while (*(cs->ptr))
	{
		if (*(cs->ptr) == '%')
		{
			++(cs->ptr);
			print_argument(/*ap,*/ cs);
		}	
		else
		{
			ft_putchar(*(cs->ptr));
			++(cs->ptr);
			++ret;
		}
	}
	free(cs);
//	va_end(ap);
	return (ret);
}
