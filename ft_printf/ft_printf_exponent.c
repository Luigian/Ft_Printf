/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_exponent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:43:41 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/25 20:50:17 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_trimzeros(char *str, int len, char c)
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

char	*pf_precizero(t_ptf *p, char *tm)
{
	if (p->pre == 0 && p->f['#'] == 0)
	{
		if (*p->ptr == 'e')
		{
			tm = pf_strjoin(p->bef, p->aft, 3);
			p->sgn ? tm = pf_strjoin("-", tm, 2) : 0;
			if (p->g)
				p->ptr = p->tmp;
			return (tm);
		}
		free(p->aft);
		p->sgn ? p->bef = pf_strjoin("-", p->bef, 2) : 0;
		p->g ? p->ptr = p->tmp : 0;
		return (p->bef);
	}
	else if (p->pre == 0 && p->f['#'] && !(*p->ptr == 'e'))
	{
		tm = pf_strjoin(p->bef, ".", 1);
		free(p->aft);
		p->sgn ? tm = pf_strjoin("-", tm, 2) : 0;
		p->g ? p->ptr = p->tmp : 0;
		return (tm);
	}
	return (NULL);
}

void	pf_exhelper(t_ptf *p, char *b, int trz, int len)
{
	char	*num;
	char	*j;
	char	*a;

	if (len < 10)
	{
		b[p->pre - trz + 2] = '0';
		b[p->pre - trz + 3] = len + '0';
		b[p->pre - trz + 4] = '\0';
	}
	else
	{
		num = ft_itoa(len);
		j = pf_strjoin(b, num, 3);
		b = j;
	}
	a = ft_strncpy(ft_strnew(1), p->bef, 1);
	free(p->bef);
	free(p->aft);
	p->bef = a;
	p->aft = b;
}

char	*pf_strncpy(char *dst, const char *src, size_t n)
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

void	pf_getexp(t_ptf *p)
{
	char	*b;
	int		trz;
	int		len;

	pf_roundfloat(p);
	b = NULL;
	b = ft_strncpy(ft_strnew(p->pre + 4), p->bef + 1, p->pre);
	if ((p->pre - (int)ft_strlen(p->bef + 1)) > 0)
		pf_strncpy(b + ft_strlen(p->bef + 1), p->aft,\
			p->pre - ft_strlen(p->bef + 1));
	trz = 0;
	if (p->g)
		trz = pf_trimzeros(b, p->pre, 'e');
	b[p->pre - trz] = 'e';
	len = ft_strlen(p->bef) - 1 - p->exp;
	b[p->pre - trz + 1] = len >= 0 ? '+' : '-';
	len *= len >= 0 ? 1 : -1;
	b[p->pre - trz + 2] = '\0';
	pf_exhelper(p, b, trz, len);
}
