/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_master.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:18:19 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/16 20:09:05 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	print_error_and_exit(int code)
{
	if (code == -1)
	{
		write(1, "[SORRY] Not enough memory for malloc.\n", 38);
		exit(code);
	}
}

void	reset_object(t_cs *cs)
{
	
	int		i;

	i = 128;
	while (i--)
		cs->flag[i] = 0;

//	cs->flags['#'] = 0;
//	cs->flags['0'] = 0; 
//	cs->flags['-'] = 0;
//	cs->flags[' '] = 0;
//	cs->flags['+'] = 0;
//	cs->flags['\''] = 0;
//	cs->hash = 0; //
//	cs->zero = 0; //
//	cs->minus = 0; //
//	cs->space = 0; //
//	cs->plus = 0; //
	cs->minwid = 0;
	cs->preci = -1;
	cs->len = 0; 
	cs->ext = 0; 
	cs->type = '0';
	cs->bef = NULL;
	cs->aft = NULL;
	cs->exp = 0;
	cs->g = 0;
	cs->temp = NULL;
	cs->arg = 0;
//	cs->apo = 0; //
}

t_cs	*create_object(const char *fmt)
{
	t_cs	*cs;

	if (!(cs = (t_cs *)malloc(sizeof(t_cs) * 1)))
		print_error_and_exit(-1);
	reset_object(cs);
	cs->begin = fmt;
	cs->ptr = (char *)fmt;
	cs->bef = NULL;
	cs->aft = NULL;
	cs->ret = 0;
	return (cs);
}

void	print_argument(va_list ap, va_list bp, t_cs *cs)
{
	reset_object(cs);
	store_format_specifications(ap, bp, cs);
	if (*cs->ptr)
	{
		print_type(ap, bp, cs);
		++(cs->ptr);
	}
}

int		ft_printf(const char *fmt, ...)
{
	t_cs		*cs;
	va_list		ap;
	va_list		bp;
	
	cs = create_object(fmt);
	va_start(ap, fmt);
	va_copy(bp, ap);
	while (*cs->ptr)
	{
		if (*cs->ptr == '%')
		{
			++cs->ptr;
			print_argument(ap, bp, cs);
		}	
		else
		{
			ft_putchar(*cs->ptr);
			++cs->ptr;
			++cs->ret;
		}
	}
	free(cs);
	va_end(ap);
	va_end(bp);
	return (cs->ret);
}
