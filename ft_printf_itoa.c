/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:34:58 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/02 21:51:17 by lusanche         ###   ########.fr       */
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

char	*ft_itoa_unsigned(unsigned long long n)
{
	int					len;
	unsigned long long	nbr;
	char				*str;

	if (n == 0)
		return ("0");
	len = 0;
	nbr = n;
	while (nbr)
	{
		nbr /= 10;
		len += 1;
	}
	nbr = n;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (nbr)
	{
		str[--len] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return (str);
}

char	*ft_strncpy_zero(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dst[i] = '0';
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_itoa_float(long double n, t_cs *cs)
{
	char					*tm;
	char					*pt;
	int						sign;
	char					*before;
	char					*after;
	long double				af;

	sign = 0;
	printf("---------------\nreal: %.100Lf\n", n);
		
	
	if (n < 0)
	{
		n *= -1;
		sign = 1;
	}
	before = ft_itoa_unsigned((unsigned long long)n);
//	return (before);
	af = n - (unsigned long long)n;
	pt = "";
	while (af > 0)
	{
		af *= 10;
		tm = ft_itoa(af);
		after = ft_strjoin(pt, tm);
		free(tm);
	   	*pt ? free(pt) : 0;
		pt = after;	
		af -= (unsigned long long)af;
	}
	printf("before = %s\n---------------\n", before);
	printf("after = %s\n---------------\n", after);
//	free(before);
//	return (pt);
	if (cs->preci == 0 && cs->hash == 0)
		after ? free(after) : 0;
	else
	{
		pt = ft_strjoin(before, ".");
		free(before);
	}
	if (cs->preci)
	{
		tm = ft_strncpy_zero(ft_strnew(cs->preci), after, cs->preci);
		if (after[cs->preci] && after[cs->preci] > '4')
//		{
//			if (tm[cs->preci] == '9')
//			{
//				tm[cs->preci] = '0';

			++(tm[cs->preci - 1]);
		free(after);
	   	before = ft_strjoin(pt, tm);
		free(tm);
		free(pt);
	}
	else
		free(after);		
	pt = before;
	printf("result = %s\n---------------\n", pt);
//	tm ? free(tm) : 0;
//	before ? free(before) : 0;
//	after ? free(after) : 0;
	return (pt);
}





/*
	printf("end = %.100Lf\n", n);
//	if (((unsigned long long)(n * 10) % 10) > 4)
//		++n;
//	s = ft_itoa_unsigned((unsigned long long)n);
	printf("string = %s\n---------------\n", s);
//	s = ft_itoa_base((unsigned long long)n, 10, cs);
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
	return ("hi");
}*/
/*
char	*ft_itoa_float(long double n, t_cs *cs)
{
	int						i;
	unsigned long long		d;
	char					*s;
	char					*t;
	char					*j;
	char					*f;
	int						sign;

	i = 0;
	d = 1;
	sign = 0;
	printf("---------------\nreal: %.100Lf\n", n);
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
	f = "";
	while (n > 0)
	{
		n *= 10;
		t = ft_itoa_unsigned((unsigned long long)n);
		n -= (unsigned long long)n;
		s = ft_strjoin(f, t);
		*t != '0' ? free(t) : 0;
	   	*f ? free(f) : 0;
		f = s;		
	}
	
	printf("end = %.100Lf\n", n);
//	if (((unsigned long long)(n * 10) % 10) > 4)
//		++n;
//	s = ft_itoa_unsigned((unsigned long long)n);
	printf("string = %s\n---------------\n", s);
//	s = ft_itoa_base((unsigned long long)n, 10, cs);
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
*/
char	*ft_itoa_extended(long double n, t_cs *cs)
{
	int						i;
	unsigned long long		d;
	char					*s;
	char					*t;
	char					*j;
	int						sign;

	i = 0;
	d = 1;
	sign = 0;
	printf("%Lf\n", n);
	if (n == -0)
		return (ft_strdup("-0.000000"));
	printf("paso\n");
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
	while ((int)d < cs->preci)
	{
		n *= 10;
		++d;
	}
//	printf("%lf\n", n);
	printf("%llu\n", (unsigned long long)n);
//	printf("%lld\n", (long long)n);
	
	s = ft_itoa_unsigned((unsigned long long)n);
	printf("%s\n", s);
//	s = ft_itoa_base((unsigned long long)n, 10, cs);
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
