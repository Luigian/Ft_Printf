/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_report.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:06:19 by lusanche          #+#    #+#             */
/*   Updated: 2019/10/29 22:04:36 by lusanche         ###   ########.fr       */
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
		if (cs->minus)
			ret = ft_strjoin(str, new);
		else
			ret = ft_strjoin(new, str);
		free(new);
		free(str);
		return (ret);
	}
	return (str);
}

char	*plus_and_space(char *str, t_cs *cs)
{
	char	*new;
	char	*ret;

	if ((cs->plus || cs->space) && str[0] != '-')
	{
		if (cs->plus)
			new = ft_memset(ft_strnew(1), '+', 1);
		else
			new = ft_memset(ft_strnew(1), ' ', 1);
		ret = ft_strjoin(new, str);
		free(new);
		free(str);
		return (ret);
	}
	return (str);
}
			
char	*zero(char *str, t_cs *cs)
{
	char	*new;
	char	*ret;
	int		len;
		
	len = 0;
	if (str[0] != '-')
		len = 0 - (cs->plus || cs->space); 
	if (cs->hash && *cs->ptr == 'x')
		len -= 2; 
	if ((len = len + cs->minwid - ft_strlen(str)) > 0)
	{
		new = ft_memset(ft_strnew(len), '0', len);
		if (str[0] == '-')
		{
			str[0] = '0';
			new[0] = '-';
		}
		ret = ft_strjoin(new, str);
		free(new);
		free(str);
		return (ret);
	}
	return (str);
}

char	*precision(char *str, t_cs *cs)
{
	char	*new;
	char	*ret;
	int		len;

	ret = str;
	if (cs->preci < 0)
	{
		if (cs->zero && !cs->minus)
			ret = zero(str, cs);
	}	
	else if ((len = cs->preci - ft_strlen(str)) > 0)
	{
		if (str[0] == '-')
		{
			str[0] = '0';
			new = ft_memset(ft_strnew(len + 1), '0', len + 1);
			new[0] = '-';
		}
		else
			new = ft_memset(ft_strnew(len), '0', len);
		ret = ft_strjoin(new, str);
		free(new);
		free(str);
	}
	return (ret);
}

char	*hash(char *str, t_cs *cs)
{
	char	*new;
	char	*ret;

	if (cs->hash)
	{
		if (*cs->ptr == 'x')
			new = "0x";
		else if (*cs->ptr == 'o')
			new = "0";
		ret = ft_strjoin(new, str);
		free(str);
		return (ret);
	}
	return (str);
}
