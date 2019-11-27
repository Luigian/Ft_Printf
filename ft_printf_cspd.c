/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cspd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:25:58 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/27 11:16:45 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_decimal(t_ptf *p)
{
	long long	lonlon;
	char		*str;

	p->f['#'] = 0;
	lonlon = va_arg(p->ap, long long);
	if (p->len == 1)
		str = pf_itoab((char)lonlon, 10, p);
	else if (p->len == 2)
		str = pf_itoab((short)lonlon, 10, p);
	else if (p->len == 3)
		str = pf_itoab((long)lonlon, 10, p);
	else if (p->len == 4)
		str = pf_itoab(lonlon, 10, p);
	else
		str = pf_itoab((int)lonlon, 10, p);
	str = pf_precision(str, p);
	str = pf_pluspace(str, p);
	str = pf_widmin(str, p);
	if (p->f['\''])
		str = pf_thousands(str);
	ft_putstr(str);
	return (str);
}

char	*pf_pointer(t_ptf *p)
{
	char	*str;

	p->f[' '] = 0;
	p->f['+'] = 0;
	p->f['#'] = 1;
	str = pf_itoab((long long)va_arg(p->ap, void *), 16, p);
	str = pf_precision(str, p);
	str = pf_strjoin("0x", str, 2);
	str = pf_widmin(str, p);
	ft_putstr(str);
	return (str);
}

char	*pf_string(t_ptf *p)
{
	char	*s;
	char	*str;
	char	*new;

	p->f[' '] = 0;
	p->f['+'] = 0;
	s = va_arg(p->ap, char *);
	if (!s)
		str = ft_strcpy(ft_strnew(6), "(null)");
	else
		str = ft_strjoin("", s);
	if (p->pre < 0)
		str = pf_precision(str, p);
	else
	{
		new = ft_strncpy(ft_strnew(p->pre), str, p->pre);
		if (p->f['0'] && !p->f['-'])
			new = pf_zero(new, p);
		free(str);
		str = new;
	}
	str = pf_widmin(str, p);
	ft_putstr(str);
	return (str);
}

char	*pf_char(t_ptf *p)
{
	char	c;
	char	*str;

	p->pre = -1;
	p->f[' '] = 0;
	p->f['+'] = 0;
	c = va_arg(p->ap, unsigned int);
	if (c == 0)
	{
		p->wid += 1;
		str = ft_strcpy(ft_strnew(2), "^@");
		str = pf_precision(str, p);
		str = pf_widmin(str, p);
		pf_putchar(str);
		p->ret -= 1;
		return (str);
	}
	str = ft_memset(ft_strnew(1), c, 1);
	str = pf_precision(str, p);
	str = pf_widmin(str, p);
	ft_putstr(str);
	return (str);
}

char	*pf_other(t_ptf *p)
{
	char	c;
	char	*str;

	p->pre = -1;
	p->f[' '] = 0;
	p->f['+'] = 0;
	c = *p->ptr;
	str = ft_memset(ft_strnew(1), c, 1);
	str = pf_precision(str, p);
	str = pf_widmin(str, p);
	ft_putstr(str);
	return (str);
}
