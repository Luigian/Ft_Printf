/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:19:36 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/16 20:20:11 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		store_format_specifications(va_list ap, va_list bp, t_cs *cs)
{
	while (1)
	{
		if (is_flag(*cs->ptr))
			store_flag(cs);
		else if (is_decimal(*cs->ptr))
			store_decimal(ap, bp, cs);
		else if (is_length(*cs->ptr))
			store_length(cs);
		else
			break;
	}
	if (*cs->ptr == 'd' || *cs->ptr == 'i')
		cs->flag['#'] = 0;
	else if (*cs->ptr == 'u' || *cs->ptr == 'U')
	{
		cs->flag['#'] = 0;
		cs->flag[' '] = 0;
		cs->flag['+'] = 0;
		if (*cs->ptr == 'U')
			cs->len = 3;
	}
	else if (*cs->ptr == 'o' || *cs->ptr == 'x' || *cs->ptr == 'X')
	{
		cs->flag[' '] = 0;
		cs->flag['+'] = 0;
	}
	else if (*cs->ptr == 's')
	{
		cs->flag['#'] = 0;
		cs->flag[' '] = 0;
		cs->flag['+'] = 0;
	}
	else if (*cs->ptr == 'p')
	{
		cs->flag[' '] = 0;
		cs->flag['+'] = 0;
		cs->flag['#'] = 1;
	}
	else if (*cs->ptr == 'f' || *cs->ptr == 'e' || *cs->ptr == 'g')
	{
		if (cs->preci == -1)
			cs->preci = 6;
		if (*cs->ptr == 'g' && cs->preci == 0)
			cs->preci = 1;
	}
	else if (*cs->ptr == 'b')
	{
		cs->flag['#'] = 0;
		cs->flag[' '] = 0;
		cs->flag['+'] = 0;
		cs->preci = -1;
		cs->flag['\''] = 0;
	}
	else if (*cs->ptr == 'k')
	{
		cs->flag['#'] = 0;
		cs->flag[' '] = 0;
		cs->flag['+'] = 0;
		cs->flag['\''] = 0;
		cs->preci = -1;
		cs->flag['0'] = 0;
	}
	else if (*cs->ptr)  // c || % || any other
	{
		cs->flag['#'] = 0;
		cs->flag[' '] = 0;
		cs->flag['+'] = 0;
		cs->preci = -1;
	}
	return (0);
}
