/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:34:58 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/03 20:14:52 by lusanche         ###   ########.fr       */
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
		return (ft_memset(ft_strnew(1), '0', 1));
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

int		round_all_nines(t_cs *cs, char *join, int len)
{
	int		i;
	int		nine;
	char 	*del;
	
	i = 0;
	nine = 0;
	del = NULL;
	while (i < len && join[i++] == '9')
		++nine;
	if (nine == len && join[i] > '4')
	{
		del = cs->bef;
		cs->bef = ft_memset(ft_strnew(ft_strlen(cs->bef) + 1), '0',\
				ft_strlen(cs->bef) + 1);
		cs->bef[0] = '1';
		free(del);
		i = 0;
		while (i < cs->preci)
			cs->aft[i++] = '0';
		return (1);
	}
	return (0);
}

int		rounding(char *join, int p_len)
{
	if (join[p_len] == '9')
	{
		join[p_len] = '0';
		rounding(join, p_len - 1);
	}
	else
		++(join[p_len]);
	return (0);
}

int		round_float(t_cs *cs)
{
	char 	*join;
	int		len;
	int		i;
	int		j;

	join = ft_strjoin(cs->bef, cs->aft);
	len = ft_strlen(cs->bef) + cs->preci;
	if (round_all_nines(cs, join, len))
	{
		free (join);
		return (2);
	}
	if (join[len] > '4')
	{
		rounding(join, len - 1);
		i = 0;
		j = 0;
		while (i < (int)ft_strlen(cs->bef))
			cs->bef[i++] = join[j++];
		i = 0;
		while (i < cs->preci)
			cs->aft[i++] = join[j++];
		free (join);
		return (1);
	}
	free (join);
	return (0);
}
		
char	*add_minus(char *str)
{
	char	*tmp;
	char	*ret;
	
	tmp = ft_memset(ft_strnew(1), '-', 1);
	ret = ft_strjoin(tmp, str);
	free(tmp);
	free(str);	
	return (ret);
}

char	*ft_itoa_float(long double n, t_cs *cs)
{
	char					*tm;
	char					*pt;
	int						sign;
	long double				af;

//	printf("real: %.100Lf\n", n);
	sign = n < 0 ? 1 : 0;
	n *= n < 0 ? -1 : 1;
	cs->bef = ft_itoa_unsigned((unsigned long long)n);
	af = n - (unsigned long long)n;
	pt = "";
	while (af > 0)
	{
		af *= 10;
		tm = ft_itoa(af);
		cs->aft = ft_strjoin(pt, tm);
		free(tm);
	   	*pt ? free(pt) : 0;
		pt = cs->aft;	
		af -= (unsigned long long)af;
	}
//	printf("bef = %s\n---------------\n", cs->bef);
//	printf("aft = %s\n---------------\n", cs->aft);
	if ((int)ft_strlen(cs->aft) > cs->preci)
		round_float(cs);
	if (cs->preci == 0 && cs->hash == 0)
	{
		free(cs->aft);
		sign ? cs->bef = add_minus(cs->bef) : 0;
		return (cs->bef);
	}
	else if (cs->preci == 0 && cs->hash)
	{
		tm = ft_strjoin(cs->bef, ".");
		free(cs->aft);
		free(cs->bef);
		sign ? tm = add_minus(tm) : 0;
		return (tm);
	}
	pt = ft_strncpy_zero(ft_strnew(cs->preci), cs->aft, cs->preci);
	free(cs->aft);
	cs->aft = ft_strjoin(".", pt);
	tm = ft_strjoin(cs->bef, cs->aft);
	free(pt);
	free(cs->bef);
	free(cs->aft);
	sign ? tm = add_minus(tm) : 0;
//	printf("result = %s\n---------------\n", tm);
	return (tm);
}


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
