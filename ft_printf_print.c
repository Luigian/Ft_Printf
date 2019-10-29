/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:25:58 by lusanche          #+#    #+#             */
/*   Updated: 2019/10/28 18:37:18 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_string(va_list ap, t_cs *cs)
{
	if (*cs->ptr == 'd' || *cs->ptr == 'i')
	{
		if (cs->len < 3)
			return (ft_itoa_long(va_arg(ap, int)));
		else if (cs->len == 3)
			return (ft_itoa_long(va_arg(ap, long)));
		else if (cs->len == 4)
			return (ft_itoa_long(va_arg(ap, long long)));
	}
	return("[error]");
}

int		print_type(va_list ap, t_cs *cs)
{
	char	*str;

	str = get_string(ap, cs);
	str = precision(str, cs);
	str = plus_and_space(str, cs);
	str = minimum_and_minus(str, cs);
	ft_putstr(str);
	free(str);
	return (0);
}
