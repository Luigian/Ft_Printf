/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_round.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:50:56 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/24 11:40:54 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	copy_rounded(t_cs *cs, char *pt)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < (int)ft_strlen(cs->bef))
		cs->bef[i++] = pt[j++];
	i = 0;
	if (*cs->ptr == 'e')
	{
		while (i < (cs->preci - ((int)ft_strlen(cs->bef) - 1)))
			cs->aft[i++] = pt[j++];
	}
	else
	{
		while (i < cs->preci)
			cs->aft[i++] = pt[j++];
	}
}

int		round_recursive(char *pt, int len)
{
	if (pt[len] == '9')
	{
		pt[len] = '0';
		round_recursive(pt, len - 1);
	}
	else
		++(pt[len]);
	return (0);
}

int		round_all_nines(t_cs *cs, char *pt, int len)
{
	int		i;
	char 	*del;

	i = 0;
	del = NULL;
	while (i < len && pt[i] == '9')
		++i;
	if (i == len && pt[i] > '4')
	{
		del = cs->bef;
		cs->bef = ft_memset(ft_strnew(ft_strlen(cs->bef) + 1), '0',\
				ft_strlen(cs->bef) + 1);
		cs->bef[0] = '1';
		free(del);
		i = 0;
		if (*cs->ptr == 'e')
			while (i < (cs->preci - (int)(ft_strlen(cs->bef) - 1)))
				cs->aft[i++] = '0';
		else
			while (i < cs->preci)
				cs->aft[i++] = '0';
		return (1);
	}
	return (0);
}

int		round_float(t_cs *cs)
{
	char 	*pt;
	int		len;

	pt = ft_strjoin(cs->bef, cs->aft);
	if (*cs->ptr == 'e')
		len = 1 + cs->preci;
	else
		len = ft_strlen(cs->bef) + cs->preci;
	if (round_all_nines(cs, pt, len))
	{
		cs->g ? --cs->preci : 0;
		free (pt);
		return (2);
	}
	if (pt[len] > '4')
	{
		round_recursive(pt, len - 1);
		copy_rounded(cs, pt);
		free (pt);
		return (1);
	}
	free (pt);
	return (0);
}
