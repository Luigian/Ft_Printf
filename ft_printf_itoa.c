/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:34:58 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/23 12:47:12 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base_uns(unsigned long long n, int base, t_cs *cs)
{
	int					len;
	unsigned long long	nbr;
	char				*str;
	char				*bastr;

	bastr = *cs->ptr == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
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
	str = ft_strnew(len);
	while (nbr)
	{
		str[--len] = bastr[nbr % base];
		nbr /= base;
	}
	return (str);
}

/////////////////////////////////////////////////////////////////////

char	*itoa_helper(long long nbr, int len, t_cs *cs, int base)
{
	unsigned long long	unlon;
	char				*str;
	char				*bastr;

	unlon = (unsigned long long)nbr;
	str = ft_strnew(len);
	bastr = *cs->ptr == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	while (unlon)
	{
		str[--len] = bastr[unlon % base];
		unlon /= base;
	}
	return (str);
}
			
char	*ft_itoa_base(long long n, int base, t_cs *cs)
{
	int					len;
	long long			nbr;
	char				*str;

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
	str = itoa_helper(nbr, len, cs, base);
	if (n < 0 && base == 10)
		str[0] = '-';
	return (str);
}

/////////////////////////////////////////////////////////////////////////


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

///////////////////////////////////////////////////////////////////////

int		round_all_nines(t_cs *cs, char *join, int len)
{
	int		i;
//	int		nine;
	char 	*del;
	
	i = 0;
//	nine = 0;
	del = NULL;
	while (i < len && join[i/*++*/] == '9')
//		++nine;
		++i;
	if (/*nine*/i == len && join[i] > '4')
	{
		del = cs->bef;
		cs->bef = ft_memset(ft_strnew(ft_strlen(cs->bef) + 1), '0',\
				ft_strlen(cs->bef) + 1);
		cs->bef[0] = '1';
		free(del);
		i = 0;
		if (*cs->ptr == 'e')
			while (i < (cs->preci - (int)(ft_strlen(cs->bef) - 1)))
				cs->aft[i++] = '0';
		else
			while (i < cs->preci)
				cs->aft[i++] = '0';
		return (1);
	}
	return (0);
}

////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////

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
		
/////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////

int		turnback_ptr_content(t_cs *cs)
{
	cs->ptr = cs->temp;
	return (0);
}

////////////////////////////////////////////////////////////////

		

int		trim_trailing_zeros(char *str, int len)
{
	while (str[--len] == '0')
		str[len] = '\0';
	if (str[len] == '.')
		str[len] = '\0';
	return (0);
}

///////////////////////////////////////////////////////////////



char	*preci_zero(t_cs *cs, char *tm)
{
	if (cs->preci == 0 && cs->flag['#'] == 0)
	{
		if (*cs->ptr == 'e')
		{
			tm = ft_strjoin_2(cs->bef, cs->aft, 2);
			cs->sign ? tm = add_minus(tm) : 0;
			if (cs->g)
				turnback_ptr_content(cs);
			return (tm);
		}
		free(cs->aft);
		cs->sign ? cs->bef = add_minus(cs->bef) : 0;
		cs->g ? turnback_ptr_content(cs) : 0;
		return (cs->bef);
	}
	else if (cs->preci == 0 && cs->flag['#'] && !(*cs->ptr == 'e'))
	{
		tm = ft_strjoin(cs->bef, ".");
		free(cs->aft);
		free(cs->bef);
		cs->sign ? tm = add_minus(tm) : 0;
		cs->g ?	turnback_ptr_content(cs) : 0;
		return (tm);
	}
	return (NULL);
}





///////////////////////////////////////////////////////////////////

void	exponent_helper(t_cs *cs, char *b, int trz, int len)
{
	char	*num;
	char	*j;
	char	*a;
	
	if (len < 10)
	{
		b[cs->preci - trz + 2] = '0';
		b[cs->preci - trz + 3] = len + '0';
		b[cs->preci - trz + 4] = '\0';
	}
	else
	{
		num = ft_itoa(len);
		j = ft_strjoin_2(b, num, 2);
		b = j;
	}
	a = ft_strncpy(ft_strnew(1), cs->bef, 1);
	free (cs->bef);
	free (cs->aft);
	cs->bef = a;
	cs->aft = b;
}

















void	get_exp_format(t_cs *cs)
{
	char	*b;
	int		trz;
	int		len;

	round_float(cs);
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
	exponent_helper(cs, b, trz, len); 	
}

////////////////////////////////////////////////////////////////////////

void	get_float(long double n, t_cs *cs)
{
	long double				af;
	char					*pt;
	char					*tm;
	
	cs->bef = ft_itoa_base_uns((unsigned long long)n, 10, cs);
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

void	get_after_max_ull(long double n, t_cs *cs)
{
	long double				af;
	char					*pt;
	char					*tm;
	
	af = n;
	while (af >= 100000000000000000)
	{
		++cs->exp;
		af /= 10;
	}
	af *= 100;
	cs->exp -= 2;
	pt = ft_itoa_base_uns((unsigned long long)af, 10, cs);
	tm = ft_memset(ft_strnew(cs->exp), '0', cs->exp);
	cs->exp = 0;
	cs->bef = ft_strjoin(pt, tm);
	free(pt);
	free(tm);
	cs->aft = ft_memset(ft_strnew(1), '0', 1);
}	

int		change_ptr_content(long double n, t_cs *cs)
{
	while (n > 0 && n < 1)
	{
		--cs->exp;
		n *= 10;
	}	
	while (n >= 10)
	{
		++cs->exp;
		n /= 10;
	}
	if (cs->exp < -4 || cs->exp >= cs->preci)
	{
		cs->temp = cs->ptr;
		cs->ptr = "e";
		--cs->preci;
	}
	else
	{
		cs->temp = cs->ptr;
		cs->ptr = "f";
		cs->preci = cs->preci - (cs->exp + 1);
	}
	cs->g = 1;
	cs->exp = 0;
	return (0);
}

char	*prepare_float(long double n, t_cs *cs)
{
	if (!(n == 0 || n > 0 || n < 0))
	{
		cs->flag['0'] = 0;
		cs->flag[' '] = 0;
		cs->flag['+'] = 0;
		cs->preci = -1;
		return(ft_strcpy(ft_strnew(3), "nan"));
	}
	cs->sign = n < 0 ? 1 : 0;
	n *= n < 0 ? -1 : 1;
	if (*cs->ptr == 'g')
		change_ptr_content(n, cs);				
	while (*cs->ptr == 'e' && n && n < 1)
	{
		n *= 10;
		++cs->exp;
	}	
	if (n > 1 && (unsigned long long)n == 0)
		get_after_max_ull(n, cs); 
	else	
		get_float(n, cs); 	
	return (NULL);
}

///////////////////////////////////////////////////////////////////////

char	*ft_itoa_float(long double n, t_cs *cs)
{
	char					*tm;
	char					*pt;
	
	if ((pt = prepare_float(n, cs)))
		return (pt);
	if (*cs->ptr == 'e')
		get_exp_format(cs);
	tm = NULL;
	if (cs->preci == 0)	
		if ((pt = preci_zero(cs, tm)))
			return (pt);
	if (*cs->ptr == 'e')
		pt = ft_strdup(cs->aft);
	else
		pt = ft_strncpy_zero(ft_strnew(cs->preci), cs->aft, cs->preci);
	free(cs->aft);
	cs->aft = ft_strjoin_2(".", pt, 1);
	tm = ft_strjoin_2(cs->bef, cs->aft, 2);
	if (cs->g && *cs->ptr == 'f' && !cs->flag['#'])
		trim_trailing_zeros(tm, (int)ft_strlen(tm));
	cs->sign ? tm = add_minus(tm) : 0;
	cs->g ?	turnback_ptr_content(cs) : 0;
	return (tm);
}
