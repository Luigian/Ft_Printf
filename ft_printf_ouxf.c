/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ouxf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:11:33 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/25 16:25:00 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_float(t_ptf *p)
{
	char	*str;

	if (*p->ptr == 'e' || *p->ptr == 'g')
		p->f['\''] = 0;
	if (p->pre == -1)
		p->pre = 6;
	if (*p->ptr == 'g' && p->pre == 0)
		p->pre = 1;
	if (p->ext)
		str = pf_itoaf(va_arg(p->ap, long double), p);
	else
		str = pf_itoaf(va_arg(p->ap, double), p);
	if (p->f['0'] && !p->f['-'])
		str = pf_zero(str, p);
	str = pf_pluspace(str, p);
	str = pf_widmin(str, p);
	if (p->f['\''])
		str = pf_thousands(str);
	ft_putstr(str);
	return (str);
}

char	*pf_hexa(t_ptf *p)
{
	unsigned long long	ulonlon;
	char				*str;

	p->f[' '] = 0;
	p->f['+'] = 0;
	if ((ulonlon = va_arg(p->ap, unsigned long long)) == 0)
		p->f['#'] = 0;
	if (p->len == 1)
		str = pf_itoabuns((unsigned char)ulonlon, 16, p);
	else if (p->len == 2)
		str = pf_itoabuns((unsigned short)ulonlon, 16, p);
	else if (p->len == 3)
		str = pf_itoabuns((unsigned long)ulonlon, 16, p);
	else if (p->len == 4)
		str = pf_itoabuns(ulonlon, 16, p);
	else
		str = pf_itoabuns((unsigned int)ulonlon, 16, p);
	str = pf_precision(str, p);
	if (p->f['#'] && *p->ptr == 'x')
		str = pf_strjoin("0x", str, 2);
	else if (p->f['#'] && *p->ptr == 'X')
		str = pf_strjoin("0X", str, 2);
	str = pf_widmin(str, p);
	ft_putstr(str);
	return (str);
}

char	*pf_unsigned(t_ptf *p)
{
	unsigned long long	ulonlon;
	char				*str;

	p->f[' '] = 0;
	p->f['+'] = 0;
	p->f['#'] = 0;
	if (*p->ptr == 'U')
		p->len = 3;
	ulonlon = va_arg(p->ap, unsigned long long);
	if (p->len == 1)
		str = pf_itoabuns((unsigned char)ulonlon, 10, p);
	else if (p->len == 2)
		str = pf_itoabuns((unsigned short)ulonlon, 10, p);
	else if (p->len == 3)
		str = pf_itoabuns((unsigned long)ulonlon, 10, p);
	else if (p->len == 4)
		str = pf_itoabuns(ulonlon, 10, p);
	else
		str = pf_itoabuns((unsigned int)ulonlon, 10, p);
	str = pf_precision(str, p);
	str = pf_widmin(str, p);
	if (p->f['\''])
		str = pf_thousands(str);
	ft_putstr(str);
	return (str);
}

char	*pf_octal(t_ptf *p)
{
	unsigned long long	ulonlon;
	char				*str;

	p->f[' '] = 0;
	p->f['+'] = 0;
	ulonlon = va_arg(p->ap, unsigned long long);
	if (p->len == 0)
		str = pf_itoabuns((unsigned int)ulonlon, 8, p);
	else if (p->len == 1)
		str = pf_itoabuns((unsigned char)ulonlon, 8, p);
	else if (p->len == 2)
		str = pf_itoabuns((unsigned short)ulonlon, 8, p);
	else if (p->len == 3)
		str = pf_itoabuns((unsigned long)ulonlon, 8, p);
	else if (p->len == 4)
		str = pf_itoabuns(ulonlon, 8, p);
	if (p->f['#'] && str[0] != '0')
		str = pf_strjoin("0", str, 2);
	str = pf_precision(str, p);
	str = pf_widmin(str, p);
	ft_putstr(str);
	return (str);
}
