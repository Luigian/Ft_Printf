/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_ouxf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:11:33 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/23 18:16:00 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_float(t_cs *cs)
{
	char	*str;

	if (*cs->ptr == 'e' || *cs->ptr == 'g')
		cs->flag['\''] = 0;
	if (cs->preci == -1)
		cs->preci = 6;
	if (*cs->ptr == 'g' && cs->preci == 0)
		cs->preci = 1;
	if (cs->ext)
		str = ft_itoa_float(va_arg(cs->ap, long double), cs);
	else
		str = ft_itoa_float(va_arg(cs->ap, double), cs);
	if (cs->flag['0'] && !cs->flag['-'])
		str = zero(str, cs);
	str = plus_and_space(str, cs);
	str = minimum_and_minus(str, cs);
	if (cs->flag['\''])
		str = thousands_separation(str);
	ft_putstr(str);
	return (str);
}

char	*print_hexa(t_cs *cs)
{
	unsigned long long	ulonlon;
	char				*str;

	cs->flag[' '] = 0;
	cs->flag['+'] = 0;
	if ((ulonlon = va_arg(cs->ap, unsigned long long)) == 0)
		cs->flag['#'] = 0;
	if (cs->len == 1)
		str = ft_itoa_base_uns((unsigned char)ulonlon, 16, cs);
	else if (cs->len == 2)
		str = ft_itoa_base_uns((unsigned short)ulonlon, 16, cs);
	else if (cs->len == 3)
		str = ft_itoa_base_uns((unsigned long)ulonlon, 16, cs);
	else if (cs->len == 4)
		str = ft_itoa_base_uns(ulonlon, 16, cs);
	else
		str = ft_itoa_base_uns((unsigned int)ulonlon, 16, cs);
	str = precision(str, cs);
	if (cs->flag['#'] && *cs->ptr == 'x')
		str = ft_strjoin_2("0x", str, 2);
	else if (cs->flag['#'] && *cs->ptr == 'X')
		str = ft_strjoin_2("0X", str, 2);
	str = minimum_and_minus(str, cs);
	ft_putstr(str);
	return (str);
}

char	*print_unsigned(t_cs *cs)
{
	unsigned long long	ulonlon;
	char				*str;

	cs->flag[' '] = 0;
	cs->flag['+'] = 0;
	cs->flag['#'] = 0;
	if (*cs->ptr == 'U')
		cs->len = 3;
	ulonlon = va_arg(cs->ap, unsigned long long);
	if (cs->len == 1)
		str = ft_itoa_base_uns((unsigned char)ulonlon, 10, cs);
	else if (cs->len == 2)
		str = ft_itoa_base_uns((unsigned short)ulonlon, 10, cs);
	else if (cs->len == 3)
		str = ft_itoa_base_uns((unsigned long)ulonlon, 10, cs);
	else if (cs->len == 4)
		str = ft_itoa_base_uns(ulonlon, 10, cs);
	else
		str = ft_itoa_base_uns((unsigned int)ulonlon, 10, cs);
	str = precision(str, cs);
	str = minimum_and_minus(str, cs);
	if (cs->flag['\''])
		str = thousands_separation(str);
	ft_putstr(str);
	return (str);
}

char	*print_octal(t_cs *cs)
{
	unsigned long long	ulonlon;
	char				*str;

	cs->flag[' '] = 0;
	cs->flag['+'] = 0;
	ulonlon = va_arg(cs->ap, unsigned long long);
	if (cs->len == 0)
		str = ft_itoa_base_uns((unsigned int)ulonlon, 8, cs);
	else if (cs->len == 1)
		str = ft_itoa_base_uns((unsigned char)ulonlon, 8, cs);
	else if (cs->len == 2)
		str = ft_itoa_base_uns((unsigned short)ulonlon, 8, cs);
	else if (cs->len == 3)
		str = ft_itoa_base_uns((unsigned long)ulonlon, 8, cs);
	else if (cs->len == 4)
		str = ft_itoa_base_uns(ulonlon, 8, cs);
	if (cs->flag['#'] && str[0] != '0')
		str = ft_strjoin_2("0", str, 2);
	str = precision(str, cs);
	str = minimum_and_minus(str, cs);
	ft_putstr(str);
	return (str);
}
