/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:27:18 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/25 20:43:35 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_thelper(char *str, char *nw, int inc, int len)
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

int		pf_increment(char *str, int *dot)
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

char	*pf_thousands(char *str)
{
	int		dot;
	int		inc;
	int		len;
	char	*new;

	dot = 0;
	inc = pf_increment(str, &dot);
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
		return (pf_thelper(str, new, inc, len));
	}
	return (str);
}

char	*pf_binary(t_ptf *p)
{
	unsigned long long	ulonlon;
	int					bits;
	char				*str;
	int					i;

	p->pre = -1;
	p->f[' '] = 0;
	p->f['+'] = 0;
	ulonlon = va_arg(p->ap, unsigned long long);
	bits = 32;
	if (p->len == 1)
		bits = 8;
	else if (p->len == 2)
		bits = 16;
	else if (p->len == 3 || p->len == 4)
		bits = 64;
	str = ft_strnew(bits);
	i = 0;
	while (bits--)
		str[i++] = (ulonlon >> bits & 1) + 48;
	str = pf_precision(str, p);
	str = pf_widmin(str, p);
	ft_putstr(str);
	return (str);
}
