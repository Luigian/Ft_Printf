/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_identify.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 10:02:57 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/06 12:16:34 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_scape_specificator(char c)
{
	return (c == '\a' || c == '\b' || c == '\f' || c == '\n' || c == '\r'\
		   	|| c == '\t' || c == '\v' || c == '\'' || c == '\\');
}

int		is_type_specificator(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'\
		   	|| c == 'o'	|| c == 'u' || c == 'x' || c == 'X' || c == 'f'\
			|| c == '%' || c == 'U');
}

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
	return (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+');
}

int		is_other_flag(char c)
{
	return (c == 't' || c == 'q' || c == 'a'\
			|| c == 'A' || c == 'e' || c == 'E' || c == 'F'\
			|| c == 'g' || c == 'G' || c == 'v' || c == 'D'\
			|| c == 'O' || c == 'S');
}

int		is_other_char(char c)
{
	return (!is_type_specificator(c) && !is_length(c) && !is_decimal(c)\
			&& !is_flag(c) && !is_other_flag(c) && ft_isprint(c));
}
