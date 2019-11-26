/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_round.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:50:56 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/25 20:58:03 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_copyround(t_ptf *p, char *pt)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < (int)ft_strlen(p->bef))
		p->bef[i++] = pt[j++];
	i = 0;
	if (*p->ptr == 'e')
	{
		while (i < (p->pre - ((int)ft_strlen(p->bef) - 1)))
			p->aft[i++] = pt[j++];
	}
	else
	{
		while (i < p->pre)
			p->aft[i++] = pt[j++];
	}
}

int		pf_roundrecursion(char *pt, int len)
{
	if (pt[len] == '9')
	{
		pt[len] = '0';
		pf_roundrecursion(pt, len - 1);
	}
	else
		++(pt[len]);
	return (0);
}

int		pf_roundnine(t_ptf *p, char *pt, int len)
{
	int		i;
	char	*del;

	i = 0;
	del = NULL;
	while (i < len && pt[i] == '9')
		++i;
	if (i == len && pt[i] > '4')
	{
		del = p->bef;
		p->bef = ft_memset(ft_strnew(ft_strlen(p->bef) + 1), '0',\
				ft_strlen(p->bef) + 1);
		p->bef[0] = '1';
		free(del);
		i = 0;
		if (*p->ptr == 'e')
			while (i < (p->pre - (int)(ft_strlen(p->bef) - 1)))
				p->aft[i++] = '0';
		else
			while (i < p->pre)
				p->aft[i++] = '0';
		return (1);
	}
	return (0);
}

int		pf_roundfloat(t_ptf *p)
{
	char	*pt;
	int		len;

	pt = ft_strjoin(p->bef, p->aft);
	if (*p->ptr == 'e')
		len = 1 + p->pre;
	else
		len = ft_strlen(p->bef) + p->pre;
	if (pf_roundnine(p, pt, len))
	{
		p->g ? --p->pre : 0;
		free(pt);
		return (2);
	}
	if (pt[len] > '4')
	{
		pf_roundrecursion(pt, len - 1);
		pf_copyround(p, pt);
		free(pt);
		return (1);
	}
	free(pt);
	return (0);
}
