/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper_01.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 10:15:02 by lusanche          #+#    #+#             */
/*   Updated: 2019/10/26 21:52:49 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		store_length_value(t_cs *cs)
{
	if (*(cs->ptr) == 'h')
	{
		cs->len = 2;
		if (*(cs->ptr + 1) == 'h')
		{
			cs->len = 1;
			++(cs->ptr);
		}
	}
	else if (*(cs->ptr) == 'l')
	{
		cs->len = 3;
		if (*(cs->ptr + 1) == 'l')
		{
			cs->len = 4;
			++(cs->ptr);
		}
	}
	else
		cs->ext = 1;
	++(cs->ptr);
	return (0);
}

int		store_decimal_value(t_cs *cs)
{
	if (*(cs->ptr) == '.')
	{
		++(cs->ptr);
		if (!(ft_isdigit(*(cs->ptr))))
			cs->preci = -1;
		else
			cs->preci = ft_atoi(cs->ptr);
	}
	else
		cs->minwid = ft_atoi(cs->ptr);
	while (ft_isdigit(*(cs->ptr)))
		++(cs->ptr);
	return (0);
}

int		store_flag_value(t_cs *cs)
{
	char	c;
	
	c = *(cs->ptr);
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
	++(cs->ptr);
	return (0);
}
