/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:34:58 by lusanche          #+#    #+#             */
/*   Updated: 2019/10/29 20:59:04 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbrlen_long(long long n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	(n < 0) ? (++len) : 0;
	while (n != 0)
	{
		++len;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa_long(long long n)
{
	int		i;
	int		len;
	char	*str;

	i = 1;
	len = ft_nbrlen_long(n);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[len - i++] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}

char	*ft_itoa_base(long long n, int base)
{
	int			len;
	long long	nbr;
	char		*str;
	char		*base_string = "0123456789abcdef";

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





















/*
int		ft_nbrlen_long_un(unsigned long long n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
//	(n < 0) ? (++len) : 0;
	while (n != 0)
	{
		++len;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa_long_un(unsigned long long n)
{
	int		i;
	int		len;
	char	*str;

	i = 1;
	len = ft_nbrlen_long_un(n);
	if (!(str = ft_strnew(len)))
		return (NULL);
//	if (n < 0)
//	{
//		str[0] = '-';
//		n *= -1;
//	}
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[len - i++] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}*/
