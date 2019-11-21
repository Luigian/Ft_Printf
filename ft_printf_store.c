/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_store.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 10:15:02 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/21 10:55:39 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	store_adjustments(t_cs *cs)
{
	if (ft_chrstr(*cs->ptr, "diuUsbk"))
		cs->flag['#'] = 0;
	if (!(ft_chrstr(*cs->ptr, "difeg")))
	{
		cs->flag[' '] = 0;
		cs->flag['+'] = 0;
	}
	if (*cs->ptr == 'U')
		cs->len = 3;
	if (*cs->ptr == 'p')
		cs->flag['#'] = 1;
	if (ft_chrstr(*cs->ptr, "feg") && cs->preci == -1)
		cs->preci = 6;
	if (*cs->ptr == 'g' && cs->preci == 0)
		cs->preci = 1;
	if (!(ft_chrstr(*cs->ptr, "diuUf")))
		cs->flag['\''] = 0;
	if (*cs->ptr == 'k')
		cs->flag['0'] = 0;
	if (!(ft_chrstr(*cs->ptr, "diuUoxXspfeg")))
		cs->preci = -1;
}

int		is_arg_index(char *str)
{
	while (ft_isdigit(*str))
		++str;
	if (*str == '$')
		return (1);
	return (0);
}

void	minwid_as_argument(t_cs *cs)
{
	va_list		tp;
	
	if (is_arg_index(cs->ptr + 1))
	{
		cs->arg = ft_atoi(cs->ptr + 1);
		va_copy(tp, cs->bp);
		while (--cs->arg)
			va_arg(tp, void*);
		cs->minwid = va_arg(tp, int);
		va_end(tp);
		cs->arg = 0;
		++cs->ptr;
		while (ft_isdigit(*cs->ptr))
			++cs->ptr;
	}
	else
		cs->minwid = va_arg(cs->ap, int);
	if (cs->minwid < 0)
	{
		cs->flag['-'] = 1;
		cs->minwid *= -1;
	}
}

void		precision_as_argument(t_cs *cs)
{
	va_list		tp;
	
	if (is_arg_index(cs->ptr + 1))
	{
		cs->arg = ft_atoi(cs->ptr + 1);
		va_copy(tp, cs->bp);
		while (--cs->arg)
			va_arg(tp, void*);
		cs->preci = va_arg(tp, int);
		va_end(tp);
		cs->arg = 0;
		++cs->ptr;
		while (ft_isdigit(*cs->ptr))
			++cs->ptr;
	}
	else
		cs->preci = va_arg(cs->ap, int);
	if (cs->preci < 0)
		cs->preci = -1;
}

void	store_precision_minwid(t_cs *cs)
{
	if (*cs->ptr == '.')
	{
		if (*(++cs->ptr) == '*')
			precision_as_argument(cs);
		else
		{
			cs->preci = 0;
			if (ft_isdigit(*cs->ptr))
				cs->preci = ft_atoi(cs->ptr);
			while (ft_isdigit(*cs->ptr))
				++cs->ptr;
			--cs->ptr;
		}
	}
	else
	{
		if (is_arg_index(cs->ptr))
			cs->arg = ft_atoi(cs->ptr);
		else
			cs->minwid = ft_atoi(cs->ptr);
		while (ft_isdigit(*cs->ptr))
			++cs->ptr;
		!cs->arg ? --cs->ptr : 0;
	}
}

void	store_length(t_cs *cs)
{
	if (*cs->ptr == 'h' && cs->len < 2)
	{
		cs->len = 2;
		if (*(cs->ptr + 1) == 'h')
		{
			cs->len = 1;
			++cs->ptr;
		}
	}
	else if (*cs->ptr == 'l' && cs->len < 4)
	{
		cs->len = 3;
		if (*(cs->ptr + 1) == 'l')
		{
			cs->len = 4;
			++cs->ptr;
		}
	}
	else if (*cs->ptr == 'j')
		cs->len = 3;
	else if (*cs->ptr == 'z')
		cs->len = 4;
	else if (*cs->ptr == 'L')
		cs->ext = 1;
}

void		store_format_specifications(t_cs *cs)
{
	while (1)
	{
		if (ft_chrstr(*cs->ptr, "#0- +\'"))
			cs->flag[(int)*cs->ptr] = 1;
		else if (ft_chrstr(*cs->ptr, "123456789.*"))
		{
			if (*cs->ptr == '*')
				minwid_as_argument(cs);
			else	
				store_precision_minwid(cs);
		}
		else if (ft_chrstr(*cs->ptr, "hlLjz"))
			store_length(cs);
		else
			break;
		++cs->ptr;
	}
	store_adjustments(cs);
}
