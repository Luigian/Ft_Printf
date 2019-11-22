/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_bk.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:18:02 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/21 21:17:01 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_date(t_cs *cs)
{
	long long		lonlon;
	char	*str;
	t_tm	tm;
	int		dim[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	lonlon = va_arg(cs->ap, long long);
	if (lonlon < 0)
		str = get_date_negative(lonlon, &tm, dim);
	else
		str = get_date_positive(lonlon, &tm, dim);
	str = minimum_and_minus(str, cs);
	ft_putstr(str);
	return (str);
}

char	*print_binary(t_cs *cs)
{
	unsigned long long	ulonlon;
	int					bits;
	char				*str;
	int					i;

	cs->preci = -1;
	cs->flag[' '] = 0;
	cs->flag['+'] = 0;
	ulonlon = va_arg(cs->ap, unsigned long long);
	bits = 32;
	if (cs->len == 1)
		bits = 8;
	else if (cs->len == 2)
		bits = 16;
	else if (cs->len == 3 || cs->len == 4)
		bits = 64;
	str = ft_strnew(bits);
	i = 0;
	while (bits--)
		str[i++] = (ulonlon >> bits & 1) + 48;
	str = precision(str, cs);
	str = minimum_and_minus(str, cs);
	ft_putstr(str);
	return (str);
}
