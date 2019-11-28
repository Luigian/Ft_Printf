/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:34:58 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/25 20:55:47 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_itoaf(long double n, t_ptf *p)
{
	char					*tm;
	char					*pt;

	if ((pt = pf_prefloat(n, p)))
		return (pt);
	if (*p->ptr == 'e')
		pf_getexp(p);
	tm = NULL;
	if (p->pre == 0)
		if ((pt = pf_precizero(p, tm)))
			return (pt);
	if (*p->ptr == 'e')
		pt = ft_strdup(p->aft);
	else
		pt = pf_strncpy(ft_strnew(p->pre), p->aft, p->pre);
	free(p->aft);
	p->aft = pf_strjoin(".", pt, 2);
	tm = pf_strjoin(p->bef, p->aft, 3);
	if (p->g && *p->ptr == 'f' && !p->f['#'])
		pf_trimzeros(tm, (int)ft_strlen(tm), 'f');
	p->sgn ? tm = pf_strjoin("-", tm, 2) : 0;
	p->g ? p->ptr = p->tmp : 0;
	return (tm);
}

char	*pf_itoabuns(unsigned long long n, int base, t_ptf *p)
{
	int					len;
	unsigned long long	nbr;
	char				*str;
	char				*bastr;

	bastr = *p->ptr == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	if (n == 0)
		return (ft_memset(ft_strnew(1), '0', 1));
	len = 0;
	nbr = n;
	while (nbr)
	{
		nbr /= base;
		len += 1;
	}
	nbr = n;
	str = ft_strnew(len);
	while (nbr)
	{
		str[--len] = bastr[nbr % base];
		nbr /= base;
	}
	return (str);
}

char	*pf_ibhelper(long long nbr, int len, t_ptf *p, int base)
{
	unsigned long long	unlon;
	char				*str;
	char				*bastr;

	unlon = (unsigned long long)nbr;
	str = ft_strnew(len);
	bastr = *p->ptr == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	while (unlon)
	{
		str[--len] = bastr[unlon % base];
		unlon /= base;
	}
	return (str);
}

char	*pf_itoab(long long n, int base, t_ptf *p)
{
	int					len;
	long long			nbr;
	char				*str;

	if (n == 0)
		return (ft_memset(ft_strnew(1), '0', 1));
	len = 0;
	nbr = n;
	while (nbr)
	{
		nbr /= base;
		len += 1;
	}
	nbr = n;
	if (nbr < 0)
	{
		if (base == 10)
			len += 1;
		nbr *= -1;
	}
	str = pf_ibhelper(nbr, len, p, base);
	if (n < 0 && base == 10)
		str[0] = '-';
	return (str);
}
