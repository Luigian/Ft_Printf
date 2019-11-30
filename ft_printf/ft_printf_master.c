/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_master.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:18:19 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/29 22:24:34 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_funfill(t_fpa fun[])
{
	int		i;

	i = 0;
	while (i < 128)
		fun[i++] = &pf_other;
	fun['c'] = &pf_char;
	fun['s'] = &pf_string;
	fun['p'] = &pf_pointer;
	fun['d'] = &pf_decimal;
	fun['i'] = &pf_decimal;
	fun['o'] = &pf_octal;
	fun['u'] = &pf_unsigned;
	fun['U'] = &pf_unsigned;
	fun['x'] = &pf_hexa;
	fun['X'] = &pf_hexa;
	fun['f'] = &pf_float;
	fun['e'] = &pf_float;
	fun['g'] = &pf_float;
	fun['b'] = &pf_binary;
	fun['k'] = &pf_time;
}

void	pf_reset(t_ptf *p)
{
	ft_memset(p->f, 0, 128 * sizeof(int));
	p->wid = 0;
	p->pre = -1;
	p->len = 0;
	p->ext = 0;
	p->bef = NULL;
	p->aft = NULL;
	p->exp = 0;
	p->g = 0;
	p->tmp = NULL;
	p->arg = 0;
	p->sgn = 0;
}

void	pf_init(const char *fmt, t_ptf *p)
{
	p->beg = (char *)fmt;
	p->ptr = (char *)fmt;
	p->bef = NULL;
	p->aft = NULL;
	p->ret = 0;
	pf_reset(p);
}

void	pf_print(t_ptf *p)
{
	t_fpa	fun[128];
	char	*str;

	pf_reset(p);
	pf_store(p);
	if (p->arg)
	{
		va_copy(p->tp, p->bp);
		while (--p->arg)
			va_arg(p->tp, void*);
		va_end(p->ap);
		va_copy(p->ap, p->tp);
		va_end(p->tp);
	}
	if (*p->ptr)
	{
		pf_funfill(fun);
		str = fun[(int)*p->ptr](p);
		p->ret += ft_strlen(str);
		free(str);
		++p->ptr;
	}
}

int		ft_printf(const char *fmt, ...)
{
	t_ptf	p;

	if (!fmt)
		return (-1);
	va_start(p.ap, fmt);
	va_copy(p.bp, p.ap);
	pf_init(fmt, &p);
	while (*p.ptr)
	{
		if (*p.ptr == '%')
		{
			++p.ptr;
			pf_print(&p);
		}
		else
		{
			ft_putchar(*p.ptr);
			++p.ptr;
			++p.ret;
		}
	}
	va_end(p.ap);
	va_end(p.bp);
	return (p.ret);
}
