/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:34:58 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/11 11:29:08 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(long long n, int base, t_cs *cs)
{
	int					len;
	long long			nbr;
	unsigned long long	unlon;
	char				*str;
	char				*base_string = "0123456789abcdef";

	if (*cs->ptr == 'X')
		base_string = "0123456789ABCDEF";
	if (n == 0)
		return (ft_memset(ft_strnew(1), '0', 1));
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
	unlon = (unsigned long long)nbr;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (unlon)
	{
		str[--len] = base_string[unlon % base];
		unlon /= base;
	}
	if (n < 0 && base == 10)
		str[0] = '-';
	return (str);
}

char	*ft_itoa_base_uns(unsigned long long n, int base, t_cs *cs)
{
	int					len;
	unsigned long long	nbr;
	char				*str;
	char				*base_string = "0123456789abcdef";

	if (*cs->ptr == 'X')
		base_string = "0123456789ABCDEF";
	if (n == 0)
	{
		*cs->ptr != 'o' ? cs->hash = 0 : 0;
		return (ft_memset(ft_strnew(1), '0', 1));
	}
	len = 0;
	nbr = n;
	while (nbr)
	{
		nbr /= base;
		len += 1;
	}
	nbr = n;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (nbr)
	{
		str[--len] = base_string[nbr % base];
		nbr /= base;
	}
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
		if (*cs->ptr == 'e')
		{
			while (i < (cs->preci - (int)(ft_strlen(cs->bef) - 1)))
				cs->aft[i++] = '0';
		}
		else
		{
			while (i < cs->preci)
				cs->aft[i++] = '0';
		}
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
	if (*cs->ptr == 'e')
		len = 1 + cs->preci;
	else
		len = ft_strlen(cs->bef) + cs->preci;
	if (round_all_nines(cs, join, len))
	{
		cs->g ? --cs->preci : 0;
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
		if (*cs->ptr == 'e')
		{
			while (i < (cs->preci - ((int)ft_strlen(cs->bef) - 1)))
				cs->aft[i++] = join[j++];
		}
		else
		{
			while (i < cs->preci)
				cs->aft[i++] = join[j++];
		}
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

int		trim_trailing_zeros_e(char *str, int len)
{
	int		counter;

	counter = 0;
	while (str[--len] == '0')
	{
		str[len] = '\0';
		++counter;
	}
	return (counter);
}

int		get_exp_format(t_cs *cs)
{
	char	*a;
	char	*b;
	int		len;
	char	*num;
	char	*j;
	int		trz;;

	
	round_float(cs);
	a = ft_strncpy(ft_strnew(1), cs->bef, 1);
	b = NULL;
	b = ft_strncpy(ft_strnew(cs->preci + 4), cs->bef + 1, cs->preci);
	if ((cs->preci - (int)ft_strlen(cs->bef + 1)) > 0)
		ft_strncpy_zero(b + ft_strlen(cs->bef + 1), cs->aft,\
			cs->preci - ft_strlen(cs->bef + 1));
	trz = 0;
	if (cs->g)
		trz	= trim_trailing_zeros_e(b, cs->preci); 
	b[cs->preci - trz] = 'e';
	len = ft_strlen(cs->bef) - 1 - cs->exp;
	b[cs->preci - trz + 1] = len >= 0 ? '+' : '-';
	len *= len >= 0 ? 1 : -1;
	b[cs->preci - trz + 2] = '\0';
	if (len < 10)
	{
		b[cs->preci - trz + 2] = '0';
		b[cs->preci - trz + 3] = len + '0';
		b[cs->preci - trz + 4] = '\0';
	}
	else
	{
		num = ft_itoa(len);
		j = ft_strjoin(b, num);
		free(num);
		free(b);
		b = j;
	}
	free (cs->bef);
	free (cs->aft);
	cs->bef = a;
	cs->aft = b;
	return (0);
}

int		turnback_ptr_content(t_cs *cs)
{
	cs->ptr = cs->temp;
	return (0);
}

int		change_ptr_content(t_cs *cs, long double n)
{
	char	*flags;
	int		exp;

	flags = "fe";
	exp = 0;
	while (n > 0 && n < 1)
	{
		--exp;
		n *= 10;
	}	
	while (n >= 10)
	{
		++exp;
		n /= 10;
	}
	if (exp < -4 || exp >= cs->preci)
	{
		cs->temp = cs->ptr;
		cs->ptr = flags + 1;
		--cs->preci;
	}
	else
	{
		cs->temp = cs->ptr;
		cs->ptr = flags;
		cs->preci = cs->preci - (exp + 1);
	}
	cs->g = 1;
	return (0);
}
		
int		trim_trailing_zeros(char *str, int len)
{
	while (str[--len] == '0')
		str[len] = '\0';
	if (str[len] == '.')
		str[len] = '\0';
	return (0);
}

char	*ft_itoa_float(long double n, t_cs *cs)
{
	char					*tm;
	char					*pt;
	int						sign;
	long double				af;

//	printf("real: %.30Lf\n", n);
	if (!(n == 0 || n > 0 || n < 0))
	{
		cs->zero = 0;
		cs->space = 0;
		cs->plus = 0;
		cs->preci = -1;
		return(ft_strcpy(ft_strnew(3), "nan"));
	}
	sign = n < 0 ? 1 : 0;
	n *= n < 0 ? -1 : 1;
	if (*cs->ptr == 'g')
		change_ptr_content(cs, n);				
	while (*cs->ptr == 'e' && n && n < 1)
	{
		n *= 10;
		++cs->exp;
	}	
	if (n > 1 && (unsigned long long)n == 0)
	{
		af = n;
		while (af >= 100000000000000000)
		{
			++cs->exp;
			af /= 10;
		}
		af *= 100;
		cs->exp -= 2;
		pt = ft_itoa_unsigned((unsigned long long)af);
		tm = ft_memset(ft_strnew(cs->exp), '0', cs->exp);
		cs->exp = 0;
		cs->bef = ft_strjoin(pt, tm);
		free(pt);
		free(tm);
		cs->aft = ft_memset(ft_strnew(1), '0', 1);
	}	
	else	
	{
		cs->bef = ft_itoa_unsigned((unsigned long long)n);
		af = n - (unsigned long long)n;
		if (af == 0)
			cs->aft = ft_memset(ft_strnew(1), '0', 1);
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
		if ((int)ft_strlen(cs->aft) > cs->preci && !(*cs->ptr == 'e'))
			round_float(cs);
	}
	if (*cs->ptr == 'e')
		get_exp_format(cs);
	if (cs->preci == 0 && cs->hash == 0)
	{
		if (*cs->ptr == 'e')
		{
			tm = ft_strjoin(cs->bef, cs->aft);
			free(cs->bef);
			free(cs->aft);
			sign ? tm = add_minus(tm) : 0;
			if (cs->g)
				turnback_ptr_content(cs);
			return (tm);
		}
		free(cs->aft);
		sign ? cs->bef = add_minus(cs->bef) : 0;
		if (cs->g)
			turnback_ptr_content(cs);
		return (cs->bef);
	}
	else if (cs->preci == 0 && cs->hash && !(*cs->ptr == 'e'))
	{
		tm = ft_strjoin(cs->bef, ".");
		free(cs->aft);
		free(cs->bef);
		sign ? tm = add_minus(tm) : 0;
		if (cs->g)
			turnback_ptr_content(cs);
		return (tm);
	}
	if (!(*cs->ptr == 'e'))
		pt = ft_strncpy_zero(ft_strnew(cs->preci), cs->aft, cs->preci);
	else
		pt = ft_strdup(cs->aft);
	free(cs->aft);
	cs->aft = ft_strjoin(".", pt);
	tm = ft_strjoin(cs->bef, cs->aft);
	free(pt);
	free(cs->bef);
	free(cs->aft);
	if (cs->g && *cs->ptr == 'f' && !cs->hash)
		trim_trailing_zeros(tm, (int)ft_strlen(tm));
	sign ? tm = add_minus(tm) : 0;
	if (cs->g)
		turnback_ptr_content(cs);
	return (tm);
}
