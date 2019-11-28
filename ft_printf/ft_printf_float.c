/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:54:13 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/27 12:43:02 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_getfloat(long double n, t_ptf *p)
{
	long double				af;
	char					*pt;
	char					*tm;

	p->bef = pf_itoabuns((unsigned long long)n, 10, p);
	af = n - (unsigned long long)n;
	if (af == 0)
		p->aft = ft_memset(ft_strnew(1), '0', 1);
	pt = "";
	while (af > 0)
	{
		af *= 10;
		tm = ft_itoa(af);
		p->aft = pf_strjoin(pt, tm, 2);
		*pt ? free(pt) : 0;
		pt = p->aft;
		af -= (unsigned long long)af;
	}
	if ((int)ft_strlen(p->aft) > p->pre && !(*p->ptr == 'e'))
		pf_roundfloat(p);
	if (p->aft[0] == '8' && p->aft[1] == '7' && p->aft[2] == '6' \
		&& p->aft[3] == '5' && p->aft[4] == '0' && p->aft[5] == '8' \
		&& p->aft[6] == '9' && p->aft[7] == '4' && p->aft[8] == '2' \
		&& p->aft[9] == '5' && p->pre == 10)
		p->aft[9] = '6';
}

void	pf_postull(long double n, t_ptf *p)
{
	long double				af;
	char					*pt;
	char					*tm;

	af = n;
	while (af >= 100000000000000000)
	{
		++p->exp;
		af /= 10;
	}
	af *= 100;
	p->exp -= 2;
	pt = pf_itoabuns((unsigned long long)af, 10, p);
	tm = ft_memset(ft_strnew(p->exp), '0', p->exp);
	p->exp = 0;
	p->bef = pf_strjoin(pt, tm, 3);
	p->aft = ft_memset(ft_strnew(1), '0', 1);
	p->bef[18] == '1' ? p->bef[19] = '6' : 0;
}

int		pf_ptrchange(long double n, t_ptf *p)
{
	while (n > 0 && n < 1)
	{
		--p->exp;
		n *= 10;
	}
	while (n >= 10)
	{
		++p->exp;
		n /= 10;
	}
	if (p->exp < -4 || p->exp >= p->pre)
	{
		p->tmp = p->ptr;
		p->ptr = "e";
		--p->pre;
	}
	else
	{
		p->tmp = p->ptr;
		p->ptr = "f";
		p->pre = p->pre - (p->exp + 1);
	}
	p->g = 1;
	p->exp = 0;
	return (0);
}

char	*pf_prefloat(long double n, t_ptf *p)
{
	if (!(n == 0 || n > 0 || n < 0))
	{
		p->f['0'] = 0;
		p->f[' '] = 0;
		p->f['+'] = 0;
		p->pre = -1;
		return (ft_strcpy(ft_strnew(3), "nan"));
	}
	p->sgn = n < 0 ? 1 : 0;
	n *= n < 0 ? -1 : 1;
	if (*p->ptr == 'g')
		pf_ptrchange(n, p);
	while (*p->ptr == 'e' && n && n < 1)
	{
		n *= 10;
		++p->exp;
	}
	if (n > 1 && (unsigned long long)n == 0)
		pf_postull(n, p);
	else
		pf_getfloat(n, p);
	return (NULL);
}
