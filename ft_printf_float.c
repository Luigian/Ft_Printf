/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:54:13 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/24 11:40:51 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_float(long double n, t_cs *cs)
{
	long double				af;
	char					*pt;
	char					*tm;

	cs->bef = ft_itoa_base_uns((unsigned long long)n, 10, cs);
	af = n - (unsigned long long)n;
	if (af == 0)
		cs->aft = ft_memset(ft_strnew(1), '0', 1);
	pt = "";
	while (af > 0)
	{
		af *= 10;
		tm = ft_itoa(af);
		cs->aft = ft_strjoin_2(pt, tm, 2);
		*pt ? free(pt) : 0;
		pt = cs->aft;
		af -= (unsigned long long)af;
	}
	if ((int)ft_strlen(cs->aft) > cs->preci && !(*cs->ptr == 'e'))
		round_float(cs);
}

void	get_after_max_ull(long double n, t_cs *cs)
{
	long double				af;
	char					*pt;
	char					*tm;

	af = n;
	while (af >= 100000000000000000)
	{
		++cs->exp;
		af /= 10;
	}
	af *= 100;
	cs->exp -= 2;
	pt = ft_itoa_base_uns((unsigned long long)af, 10, cs);
	tm = ft_memset(ft_strnew(cs->exp), '0', cs->exp);
	cs->exp = 0;
	cs->bef = ft_strjoin_2(pt, tm, 3);
	cs->aft = ft_memset(ft_strnew(1), '0', 1);
}

int		change_ptr_content(long double n, t_cs *cs)
{
	while (n > 0 && n < 1)
	{
		--cs->exp;
		n *= 10;
	}
	while (n >= 10)
	{
		++cs->exp;
		n /= 10;
	}
	if (cs->exp < -4 || cs->exp >= cs->preci)
	{
		cs->temp = cs->ptr;
		cs->ptr = "e";
		--cs->preci;
	}
	else
	{
		cs->temp = cs->ptr;
		cs->ptr = "f";
		cs->preci = cs->preci - (cs->exp + 1);
	}
	cs->g = 1;
	cs->exp = 0;
	return (0);
}

char	*prepare_float(long double n, t_cs *cs)
{
	if (!(n == 0 || n > 0 || n < 0))
	{
		cs->flag['0'] = 0;
		cs->flag[' '] = 0;
		cs->flag['+'] = 0;
		cs->preci = -1;
		return(ft_strcpy(ft_strnew(3), "nan"));
	}
	cs->sign = n < 0 ? 1 : 0;
	n *= n < 0 ? -1 : 1;
	if (*cs->ptr == 'g')
		change_ptr_content(n, cs);
	while (*cs->ptr == 'e' && n && n < 1)
	{
		n *= 10;
		++cs->exp;
	}
	if (n > 1 && (unsigned long long)n == 0)
		get_after_max_ull(n, cs);
	else
		get_float(n, cs);
	return (NULL);
}
