/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_store.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 10:15:02 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/13 09:16:06 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		store_length(t_cs *cs)
{
	if (*cs->ptr == 'j')
		cs->len = 3;
	else if (*cs->ptr == 'z')
		cs->len = 4;
	else if (*cs->ptr == 'h' && cs->len < 2)
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
	else if (*cs->ptr == 'L')
		cs->ext = 1;
	++cs->ptr;
	return (0);
}

int		is_arg_index(char *str)
{
	while (ft_isdigit(*str))
		++str;
	if (*str == '$')
		return (1);
	else
		return (0);
}

int		store_decimal(va_list ap, va_list bp, t_cs *cs)
{
	va_list		tp;
	
	if (*cs->ptr == '*')
	{
		if (is_arg_index(cs->ptr + 1))
		{
			cs->arg = ft_atoi(cs->ptr + 1);
			va_copy(tp, bp);
			while (--cs->arg)
				va_arg(tp, void*);
			cs->minwid = va_arg(tp, int);
			if (cs->minwid < 0)
			{
				cs->minus = 1;
				cs->minwid *= -1;
			}
			va_end(tp);
			cs->arg = 0;
			++cs->ptr;
		}
		else
		{
			cs->minwid = va_arg(ap, int);
			if (cs->minwid < 0)
			{
				cs->minus = 1;
				cs->minwid *= -1;
			}
			++cs->ptr;
			return (0);
		}
	}
	else if (*cs->ptr == '.')
	{
		++cs->ptr;
		if (*cs->ptr == '*')
		{
			if (is_arg_index(cs->ptr + 1))
			{
				cs->arg = ft_atoi(cs->ptr + 1);
				va_copy(tp, bp);
				while (--cs->arg)
					va_arg(tp, void*);
				cs->preci = va_arg(tp, int);
				if (cs->preci < 0)
					cs->preci = -1;
				va_end(tp);
				cs->arg = 0;
				++cs->ptr;
			}
			else
			{
				cs->preci = va_arg(ap, int);
				if (cs->preci < 0)
					cs->preci = -1;
				++cs->ptr;
				return (0);
			}
		}
		else
		{
			if (!(ft_isdigit(*cs->ptr)))
				cs->preci = 0;
			else
				cs->preci = ft_atoi(cs->ptr);
		}
	}
	else
	{
		if (is_arg_index(cs->ptr))
			cs->arg = ft_atoi(cs->ptr);
		else
			cs->minwid = ft_atoi(cs->ptr);
	}
	while (ft_isdigit(*cs->ptr) || *cs->ptr == '$')
		++cs->ptr;
	return (0);
}

int		store_flag(t_cs *cs)
{
	char	c;
	
	c = *cs->ptr;
	if (c == '#')
		cs->hash = 1;
	else if (c == '0')
		cs->zero = 1;
	else if (c == '-')
		cs->minus = 1;
	else if (c == ' ')
		cs->space = 1;
	else if (c == '+')
		cs->plus = 1;
	else if (c == '\'')
		cs->apo = 1;
	++cs->ptr;
	return (0);
}
