/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:05:42 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/26 12:47:23 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_months(int dim[])
{
	dim[0] = 31;
	dim[1] = 28;
	dim[2] = 31;
	dim[3] = 30;
	dim[4] = 31;
	dim[5] = 30;
	dim[6] = 31;
	dim[7] = 31;
	dim[8] = 30;
	dim[9] = 31;
	dim[10] = 30;
	dim[11] = 31;
}

void	pf_putchar(char *str)
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

char	*pf_strjoin(char *a, char *b, int code)
{
	char	*new;

	new = ft_strjoin(a, b);
	if (code == 1 || code == 3)
		free(a);
	if (code == 2 || code == 3)
		free(b);
	return (new);
}

int		pf_argindex(char *str)
{
	while (ft_isdigit(*str))
		++str;
	if (*str == '$')
		return (1);
	return (0);
}
