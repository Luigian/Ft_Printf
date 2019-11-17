/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_identify.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 10:02:57 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/16 16:37:32 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
int		is_type_specificator(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'\
		   	|| c == 'o'	|| c == 'u' || c == 'x' || c == 'X' || c == 'f'\
			|| c == '%' || c == 'U' || c == 'e' || c == 'g' || c == 'b'\
			|| c == 'k');
}*/

int		is_length(char c)
{
	return (c == 'h' || c == 'l' || c == 'L' || c == 'j' || c == 'z');
}

int		is_decimal(char c)
{
	return (ft_isdigit(c) || c == '.' || c == '*');
}

int		is_flag(char c)
{
	return (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+'\
			|| c == '\'');
}
