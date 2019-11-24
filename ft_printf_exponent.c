/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_exponent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:43:41 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/24 11:40:57 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		trim_trailing_zeros(char *str, int len, char c)
{
	int		counter;

	if (c == 'e')
	{
		counter = 0;
		while (str[--len] == '0')
		{
			str[len] = '\0';
			++counter;
		}
		return (counter);
	}
	while (str[--len] == '0')
		str[len] = '\0';
	if (str[len] == '.')
		str[len] = '\0';
	return (0);
}

char	*preci_zero(t_cs *cs, char *tm)
{
	if (cs->preci == 0 && cs->flag['#'] == 0)
	{
		if (*cs->ptr == 'e')
		{
			tm = ft_strjoin_2(cs->bef, cs->aft, 3);
			cs->sign ? tm = ft_strjoin_2("-", tm, 2): 0;
			if (cs->g)
				cs->ptr = cs->temp;
			return (tm);
		}
		free(cs->aft);
		cs->sign ? cs->bef = ft_strjoin_2("-", cs->bef, 2): 0;
		cs->g ?	cs->ptr = cs->temp : 0;
		return (cs->bef);
	}
	else if (cs->preci == 0 && cs->flag['#'] && !(*cs->ptr == 'e'))
	{
		tm = ft_strjoin_2(cs->bef, ".", 1);
		free(cs->aft);
		cs->sign ? tm = ft_strjoin_2("-", tm, 2): 0;
		cs->g ?	cs->ptr = cs->temp : 0;
		return (tm);
	}
	return (NULL);
}

void	exponent_helper(t_cs *cs, char *b, int trz, int len)
{
	char	*num;
	char	*j;
	char	*a;

	if (len < 10)
	{
		b[cs->preci - trz + 2] = '0';
		b[cs->preci - trz + 3] = len + '0';
		b[cs->preci - trz + 4] = '\0';
	}
	else
	{
		num = ft_itoa(len);
		j = ft_strjoin_2(b, num, 3);
		b = j;
	}
	a = ft_strncpy(ft_strnew(1), cs->bef, 1);
	free (cs->bef);
	free (cs->aft);
	cs->bef = a;
	cs->aft = b;
}

char	*ft_strncpy_zero(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dst[i] = '0';
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	get_exp_format(t_cs *cs)
{
	char	*b;
	int		trz;
	int		len;

	round_float(cs);
	b = NULL;
	b = ft_strncpy(ft_strnew(cs->preci + 4), cs->bef + 1, cs->preci);
	if ((cs->preci - (int)ft_strlen(cs->bef + 1)) > 0)
		ft_strncpy_zero(b + ft_strlen(cs->bef + 1), cs->aft,\
			cs->preci - ft_strlen(cs->bef + 1));
	trz = 0;
	if (cs->g)
		trz	= trim_trailing_zeros(b, cs->preci, 'e');
	b[cs->preci - trz] = 'e';
	len = ft_strlen(cs->bef) - 1 - cs->exp;
	b[cs->preci - trz + 1] = len >= 0 ? '+' : '-';
	len *= len >= 0 ? 1 : -1;
	b[cs->preci - trz + 2] = '\0';
	exponent_helper(cs, b, trz, len);
}
