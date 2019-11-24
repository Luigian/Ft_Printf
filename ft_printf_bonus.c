/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:27:18 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/24 11:41:00 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fill_helper(char *str, char *nw, int inc, int len)
{
	int		i;

	while (inc)
	{
		i = 0;
		while (i < 3)
		{
			nw[len] = str[len - inc];
			--len;
			++i;
		}
		nw[len] = ',';
		--inc;
		--len;
	}
	while (len)
	{
		nw[len] = str[len - inc];
		--len;
	}
	nw[len] = str[len - inc];
	free(str);
	return (nw);
}

int		increment(char *str, int *dot)
{
	int		count;
	int		inc;
	
	count = 0;
	while (*str && *str != '.' && (!ft_isdigit(*str) || *str == '0'))
		++str;
	while (ft_isdigit(*str))
	{
		++count;
		++str;
	}
	if (*str == '.')
		*dot = 1;
	inc = 0;
	if (count > 3)
	{
		if (count % 3 != 0)
			inc = count / 3;
		else
			inc = (count / 3) - 1;
	}
	return (inc);
}

char	*thousands_separation(char *str)
{
	int		dot;
	int		inc;
	int		len;
	char	*new;

	dot = 0;
	inc = increment(str, &dot);
	len = ft_strlen(str) + inc;
	if (inc)
	{
		new = ft_strnew(len);
		if (dot)
		{
			--len;
			while (str[len - inc] != '.')
			{
				new[len] = str[len - inc];
				--len;
			}
			new[len] = str[len - inc];
		}
		--len;
		return (fill_helper(str, new, inc, len));
	}
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
