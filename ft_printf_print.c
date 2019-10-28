/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:25:58 by lusanche          #+#    #+#             */
/*   Updated: 2019/10/27 21:40:04 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
	



char	*precision(char *str, t_cs *cs)
{
	char	*new;
	char	*ret;
	int		len;

	if ((len = cs->preci - ft_strlen(str)) > 0)
	{
		new = ft_strnew(cs->preci - ft_strlen(str));
		new = ft_memset(new, '0', cs->preci - ft_strlen(str));
		ret = ft_strjoin(new, str);
		free(new);
		free(str);
		return (ret);
	}
	return (str);
}


char	*get_string(va_list ap, t_cs *cs)
{
	if (*cs->ptr == 'd')
		return (ft_itoa(va_arg(ap, int)));
	return("[error]");
}


int		print_type(va_list ap, t_cs *cs)
{
	char	*str;

	str = get_string(ap, cs);
	str = precision(str, cs);
	ft_putstr(str);
	free(str);
	return (0);
}
