/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:05:42 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/23 12:48:08 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_char_null(char *str)
{
	while (*str)
	{
		if (*str == '^')
		{
			ft_putchar(0);
			str += 2;
		}
		else
		{
			ft_putchar(*str);
			++str;
		}
	}
}

char	*ft_strjoin_2(char *a, char *b, int code)
{
	char	*new;

	new = ft_strjoin(a, b);
	free(b);
	if (code == 2)
		free(a);
	return (new);
}

void	fill_fun_pointer_array(funPointer fpa[])
{
	int		i;

	i = 0;
	while (i < 128)
		fpa[i++] = &print_other;
	fpa['c'] = &print_char;
	fpa['s'] = &print_string;
	fpa['p'] = &print_pointer;
	fpa['d'] = &print_decimal;
	fpa['i'] = &print_decimal;
	fpa['o'] = &print_octal;
	fpa['u'] = &print_unsigned;
	fpa['U'] = &print_unsigned;
	fpa['x'] = &print_hexa;
	fpa['X'] = &print_hexa;
	fpa['f'] = &print_float;
	fpa['e'] = &print_float;
	fpa['g'] = &print_float;
	fpa['b'] = &print_binary;
	fpa['k'] = &print_date;
}

int		is_arg_index(char *str)
{
	while (ft_isdigit(*str))
		++str;
	if (*str == '$')
		return (1);
	return (0);
}
