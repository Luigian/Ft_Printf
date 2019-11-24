/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:05:42 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/24 12:42:53 by lusanche         ###   ########.fr       */
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
	if (code == 1 || code == 3)
		free(a);
	if (code == 2 || code == 3)
		free(b);
	return (new);
}

int		is_arg_index(char *str)
{
	while (ft_isdigit(*str))
		++str;
	if (*str == '$')
		return (1);
	return (0);
}
