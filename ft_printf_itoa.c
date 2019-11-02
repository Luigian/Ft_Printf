/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:34:58 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/01 21:02:12 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(long long n, int base, t_cs *cs)
{
	int			len;
	long long	nbr;
	char		*str;
	char		*base_string = "0123456789abcdef";

	if (*cs->ptr == 'X')
		base_string = "0123456789ABCDEF";
	if (n == 0)
		return ("0");
	len = 0;
	nbr = n;
	while (nbr)
	{
		nbr /= base;
		len += 1;
	}
	nbr = n;
	if (nbr < 0)
	{
		if (base == 10)
			len += 1;
		nbr *= -1;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (nbr)
	{
		str[--len] = base_string[nbr % base];
		nbr /= base;
	}
	if (n < 0 && base == 10)
		str[0] = '-';
	return (str);
}

char	*ft_itoa_float(double n, t_cs *cs)
{
	int		i;
	int		d;
	char	*s;
	char	*t;
	char	*j;
	int		sign;

	i = 0;
	d = 1;
	sign = 0;
	if (n < 0)
	{
		n *= -1;
		sign = 1;
	}
	while (n > d)
	{
		++i;
		d *= 10;
	}
	d = 0;
	while (d < cs->preci)
	{
		n *= 10;
		++d;
	}
	s = ft_itoa_base((long long)n, 10, cs);
	if (cs->preci == 0 && cs->hash == 0)
	{
		if (sign)
		{
			t = ft_memset(ft_strnew(1), '-', 1);
			j = ft_strjoin(t, s);
			free(t);
			free(s);	
			return (j);
		}
		else
			return (s);
	}
	t = ft_strnew(ft_strlen(s + i) + 1);
	t[0] = '.';
	ft_strcpy(t + 1, s + i);
	s[i] = '\0';
	if (i == 0)
	{
		free(s);
		s = "0";
	}
	j = ft_strjoin(s, t);
	i != 0 ? free(s) : 0;
	free(t);
	if (sign)
	{
		t = ft_memset(ft_strnew(1), '-', 1);
		s = ft_strjoin(t, j);
		free(t);
		free(j);	
		return (s);
	}		
	return (j);
}
