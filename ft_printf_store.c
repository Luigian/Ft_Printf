/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_store.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 10:15:02 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/06 11:41:40 by lusanche         ###   ########.fr       */
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

int		store_decimal(va_list ap, t_cs *cs)
{
	if (*cs->ptr == '*')
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
	else if (*cs->ptr == '.')
	{
		++cs->ptr;
		if (*cs->ptr == '*')
		{
			cs->preci = va_arg(ap, int);
			if (cs->preci < 0)
				cs->preci = -1;
			++cs->ptr;
			return (0);
		}
		if (!(ft_isdigit(*cs->ptr)))
			cs->preci = 0;
		else
			cs->preci = ft_atoi(cs->ptr);
	}
	else
		cs->minwid = ft_atoi(cs->ptr);
	while (ft_isdigit(*cs->ptr))
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
	++cs->ptr;
	return (0);
}
/*
int		store_decimal(t_cs *cs)
{
	if (*cs->ptr == '.')
	{
		++cs->ptr;
		if (!(ft_isdigit(*cs->ptr)))
			cs->preci = 0;
		else
			cs->preci = ft_atoi(cs->ptr);
	}
	else
		cs->minwid = ft_atoi(cs->ptr);
	while (ft_isdigit(*cs->ptr))
		++cs->ptr;
	return (0);
}*/
