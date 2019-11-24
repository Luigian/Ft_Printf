/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:06:19 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/24 11:41:19 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*minimum_and_minus(char *str, t_cs *cs)
{
	char	*new;
	char	*ret;
	int		len;

	if ((len = cs->minwid - ft_strlen(str)) > 0)
	{
		new = ft_memset(ft_strnew(len), ' ', len);
		if (cs->flag['-'])
			ret = ft_strjoin_2(str, new, 3);
		else
			ret = ft_strjoin_2(new, str, 3);
		return (ret);
	}
	return (str);
}

char	*plus_and_space(char *str, t_cs *cs)
{
	char	*new;

	if ((cs->flag['+'] || cs->flag[' ']) && str[0] != '-')
	{
		if (cs->flag['+'])
			new = ft_memset(ft_strnew(1), '+', 1);
		else
			new = ft_memset(ft_strnew(1), ' ', 1);
		new = ft_strjoin_2(new, str, 3);
		return (new);
	}
	return (str);
}
			
char	*zero(char *str, t_cs *cs)
{
	char	*new;
	int		len;
		
	len = 0;
	if (str[0] != '-')
		len = 0 - (cs->flag['+'] || cs->flag[' ']); 
	if (cs->flag['#'] && (*cs->ptr == 'x' || *cs->ptr == 'X'\
		|| *cs->ptr == 'p'))
		len -= 2; 
	if ((len = len + cs->minwid - ft_strlen(str)) > 0)
	{
		new = ft_memset(ft_strnew(len), '0', len);
		if (str[0] == '-')
		{
			str[0] = '0';
			new[0] = '-';
		}
		new = ft_strjoin_2(new, str, 3);
		return (new);
	}
	return (str);
}

char	*precision(char *str, t_cs *cs)
{
	char	*new;
	int		len;

	if (cs->preci < 0 && cs->flag['0'] && !cs->flag['-'])
		str = zero(str, cs);
	else if (!cs->preci && ft_strlen(str) == 1 && str[0] == '0')
	{
		if (*cs->ptr == 'p')
			str[0] = '\0';
		else if (!cs->flag['#'])
			str[0] = '\0';
	}
	else if ((len = cs->preci - ft_strlen(str) + (str[0] == '-')) > 0)
	{
		if (str[0] == '-')
		{
			str[0] = '0';
			new = ft_memset(ft_strnew(len + 1), '0', len);
			new[0] = '-';
		}
		else
			new = ft_memset(ft_strnew(len), '0', len);
		str = ft_strjoin_2(new, str, 3);
	}
	return (str);
}
