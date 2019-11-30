/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_store.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 10:15:02 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/29 22:25:59 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_length(t_ptf *p)
{
	if (*p->ptr == 'h' && p->len < 2)
	{
		p->len = 2;
		if (*(p->ptr + 1) == 'h')
		{
			p->len = 1;
			++p->ptr;
		}
	}
	else if (*p->ptr == 'l' && p->len < 4)
	{
		p->len = 3;
		if (*(p->ptr + 1) == 'l')
		{
			p->len = 4;
			++p->ptr;
		}
	}
	else if (*p->ptr == 'j')
		p->len = 3;
	else if (*p->ptr == 'z')
		p->len = 4;
	else if (*p->ptr == 'L')
		p->ext = 1;
}

void	pf_prearg(t_ptf *p)
{
	if (pf_argindex(p->ptr + 1))
	{
		p->arg = ft_atoi(p->ptr + 1);
		va_copy(p->tp, p->bp);
		while (--p->arg)
			va_arg(p->tp, void*);
		p->pre = va_arg(p->tp, int);
		va_end(p->tp);
		p->arg = 0;
		++p->ptr;
		while (ft_isdigit(*p->ptr))
			++p->ptr;
	}
	else
		p->pre = va_arg(p->ap, int);
	if (p->pre < 0)
		p->pre = -1;
}

void	pf_prewid(t_ptf *p)
{
	if (*p->ptr == '.')
	{
		if (*(++p->ptr) == '*')
			pf_prearg(p);
		else
		{
			p->pre = 0;
			if (ft_isdigit(*p->ptr))
				p->pre = ft_atoi(p->ptr);
			while (ft_isdigit(*p->ptr))
				++p->ptr;
			--p->ptr;
		}
	}
	else
	{
		if (pf_argindex(p->ptr))
			p->arg = ft_atoi(p->ptr);
		else
			p->wid = ft_atoi(p->ptr);
		while (ft_isdigit(*p->ptr))
			++p->ptr;
		!p->arg ? --p->ptr : 0;
	}
}

void	pf_widarg(t_ptf *p)
{
	if (pf_argindex(p->ptr + 1))
	{
		p->arg = ft_atoi(p->ptr + 1);
		va_copy(p->tp, p->bp);
		while (--p->arg)
			va_arg(p->tp, void*);
		p->wid = va_arg(p->tp, int);
		va_end(p->tp);
		p->arg = 0;
		++p->ptr;
		while (ft_isdigit(*p->ptr))
			++p->ptr;
	}
	else
		p->wid = va_arg(p->ap, int);
	if (p->wid < 0)
	{
		p->f['-'] = 1;
		p->wid *= -1;
	}
}

void	pf_store(t_ptf *p)
{
	while (1)
	{
		if (ft_chrstr(*p->ptr, "#0- +\'"))
			p->f[(int)*p->ptr] = 1;
		else if (ft_chrstr(*p->ptr, "123456789.*"))
		{
			if (*p->ptr == '*')
				pf_widarg(p);
			else
				pf_prewid(p);
		}
		else if (ft_chrstr(*p->ptr, "hlLjz"))
			pf_length(p);
		else
			break ;
		++p->ptr;
	}
}
