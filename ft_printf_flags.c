/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:06:19 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/25 20:53:34 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_widmin(char *str, t_ptf *p)
{
	char	*new;
	char	*ret;
	int		len;

	if ((len = p->wid - ft_strlen(str)) > 0)
	{
		new = ft_memset(ft_strnew(len), ' ', len);
		if (p->f['-'])
			ret = pf_strjoin(str, new, 3);
		else
			ret = pf_strjoin(new, str, 3);
		return (ret);
	}
	return (str);
}

char	*pf_pluspace(char *str, t_ptf *p)
{
	char	*new;

	if ((p->f['+'] || p->f[' ']) && str[0] != '-')
	{
		if (p->f['+'])
			new = ft_memset(ft_strnew(1), '+', 1);
		else
			new = ft_memset(ft_strnew(1), ' ', 1);
		new = pf_strjoin(new, str, 3);
		return (new);
	}
	return (str);
}

char	*pf_zero(char *str, t_ptf *p)
{
	char	*new;
	int		len;

	len = 0;
	if (str[0] != '-')
		len = 0 - (p->f['+'] || p->f[' ']);
	if (p->f['#'] && (*p->ptr == 'x' || *p->ptr == 'X'\
		|| *p->ptr == 'p'))
		len -= 2;
	if ((len = len + p->wid - ft_strlen(str)) > 0)
	{
		new = ft_memset(ft_strnew(len), '0', len);
		if (str[0] == '-')
		{
			str[0] = '0';
			new[0] = '-';
		}
		new = pf_strjoin(new, str, 3);
		return (new);
	}
	return (str);
}

char	*pf_precision(char *str, t_ptf *p)
{
	char	*new;
	int		len;

	if (p->pre < 0 && p->f['0'] && !p->f['-'])
		str = pf_zero(str, p);
	else if (!p->pre && ft_strlen(str) == 1 && str[0] == '0')
	{
		if (*p->ptr == 'p')
			str[0] = '\0';
		else if (!p->f['#'])
			str[0] = '\0';
	}
	else if ((len = p->pre - ft_strlen(str) + (str[0] == '-')) > 0)
	{
		if (str[0] == '-')
		{
			str[0] = '0';
			new = ft_memset(ft_strnew(len + 1), '0', len);
			new[0] = '-';
		}
		else
			new = ft_memset(ft_strnew(len), '0', len);
		str = pf_strjoin(new, str, 3);
	}
	return (str);
}
