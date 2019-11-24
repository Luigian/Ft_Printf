/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:34:58 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/23 18:14:49 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_float(long double n, t_cs *cs)
{
	char					*tm;
	char					*pt;
	
	if ((pt = prepare_float(n, cs)))
		return (pt);
	if (*cs->ptr == 'e')
		get_exp_format(cs);
	tm = NULL;
	if (cs->preci == 0)	
		if ((pt = preci_zero(cs, tm)))
			return (pt);
	if (*cs->ptr == 'e')
		pt = ft_strdup(cs->aft);
	else
		pt = ft_strncpy_zero(ft_strnew(cs->preci), cs->aft, cs->preci);
	free(cs->aft);
	cs->aft = ft_strjoin_2(".", pt, 2);
	tm = ft_strjoin_2(cs->bef, cs->aft, 3);
	if (cs->g && *cs->ptr == 'f' && !cs->flag['#'])
		trim_trailing_zeros(tm, (int)ft_strlen(tm), 'f');
	cs->sign ? tm = ft_strjoin_2("-", tm, 2): 0;
	cs->g ?	cs->ptr = cs->temp : 0;
	return (tm);
}

char	*ft_itoa_base_uns(unsigned long long n, int base, t_cs *cs)
{
	int					len;
	unsigned long long	nbr;
	char				*str;
	char				*bastr;

	bastr = *cs->ptr == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
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

char	*itoa_helper(long long nbr, int len, t_cs *cs, int base)
{
	unsigned long long	unlon;
	char				*str;
	char				*bastr;

	unlon = (unsigned long long)nbr;
	str = ft_strnew(len);
	bastr = *cs->ptr == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	while (unlon)
	{
		str[--len] = bastr[unlon % base];
		unlon /= base;
	}
	return (str);
}

char	*ft_itoa_base(long long n, int base, t_cs *cs)
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
	str = itoa_helper(nbr, len, cs, base);
	if (n < 0 && base == 10)
		str[0] = '-';
	return (str);
}
