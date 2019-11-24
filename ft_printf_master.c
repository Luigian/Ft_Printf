/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_master.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:18:19 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/23 18:15:34 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		close_program(int code, t_cs cs)
{
	va_end(cs.ap);
	va_end(cs.bp);
	if (code == -1)
	{
		write(1, "[SORRY] Not type of conversion provided.\n", 41);
		exit(code);
	}
	return (cs.ret);
}

void	reset_object(t_cs *cs)
{
	ft_memset(cs->flag, 0, 128 * sizeof(int));
	cs->minwid = 0;
	cs->preci = -1;
	cs->len = 0; 
	cs->ext = 0; 
	cs->bef = NULL;
	cs->aft = NULL;
	cs->exp = 0;
	cs->g = 0;
	cs->temp = NULL;
	cs->arg = 0;
	cs->sign = 0;
}

void	init_struct(const char *fmt, t_cs *cs)
{
	cs->begin = fmt;
	cs->ptr = (char *)fmt;
	cs->bef = NULL;
	cs->aft = NULL;
	cs->ret = 0;
	reset_object(cs);
}

void	print_argument(t_cs *cs)
{
	funPointer	fpa[128];
	char		*str;
	
	reset_object(cs);
	store_format_specifications(cs);
	if (cs->arg)
	{
		va_copy(cs->tp, cs->bp);
		while (--cs->arg)
			va_arg(cs->tp, void*);
		va_end(cs->ap);
		va_copy(cs->ap, cs->tp);
		va_end(cs->tp);
	}	
	if (*cs->ptr)
	{
		fill_fun_pointer_array(fpa);
		str = fpa[(int)*cs->ptr](cs);
		cs->ret += ft_strlen(str);
		free(str);
		++cs->ptr;
	}
}

int		ft_printf(const char *fmt, ...)
{
	t_cs		cs;
	
	va_start(cs.ap, fmt);
	va_copy(cs.bp, cs.ap);
	init_struct(fmt, &cs);
	while (*cs.ptr)
	{
		if (*cs.ptr == '%')
		{
			++cs.ptr;
			print_argument(&cs);
		}	
		else
		{
			ft_putchar(*cs.ptr);
			++cs.ptr;
			++cs.ret;
		}
	}
	return (close_program(0, cs));
}
