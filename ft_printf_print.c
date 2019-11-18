/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:25:58 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/18 11:55:23 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_bits(unsigned long long ulonlon, int bits)
{
	char	*result;
	char	c;
	int		i;

	result = ft_strnew(bits);
	i = 0;
	while (bits--)
	{
		c = (ulonlon >> bits & 1) + 48;
		result[i] = c;
		++i;
	}
	return (result);
}
		
char	*ft_date_format(t_tm *tm)
{
	char 	*date;
	char 	*temp;
	char 	*del;
	
	date = ft_strcpy(ft_strnew(25), "-0.-0.T0.:0.:0.+00:00");
	temp = ft_itoa(tm->second);
	if (tm->second > 9)
	{
		date[13] = temp[0];
		date[14] = temp[1];
	}
	else
		date[14] = temp[0];
	free(temp);
	temp = ft_itoa(tm->minute);
	if (tm->minute > 9)
	{
		date[10] = temp[0];
		date[11] = temp[1];
	}
	else
		date[11] = temp[0];
	free(temp);
	temp = ft_itoa(tm->hour);
	if (tm->hour > 9)
	{
		date[7] = temp[0];
		date[8] = temp[1];
	}
	else
		date[8] = temp[0];
	free(temp);
	temp = ft_itoa(tm->day);
	if (tm->day > 9)
	{
		date[4] = temp[0];
		date[5] = temp[1];
	}
	else
		date[5] = temp[0];
	free(temp);
	temp = ft_itoa(tm->month);
	if (tm->month > 9)
	{
		date[1] = temp[0];
		date[2] = temp[1];
	}
	else
		date[2] = temp[0];
	free(temp);
	temp = ft_itoa(tm->year);
	del = date;
	date = ft_strjoin(temp, del);
	free(del);
	free(temp);
	free(tm);
	return (date);
}


char	*get_date_positive(long long lonlon, t_tm *tm, int *dim)
{
	int		i;
	
	tm->year = 1970; 
	tm->month = 1;
   	tm->day = 1;
	tm->hour = 0; 
	tm->minute = 0; 
	tm->second = 0;
	i = 0;
	tm->second = lonlon % 60;
	tm->minute = (lonlon % (60 * 60)) / 60;
	tm->hour = (lonlon % (60 * 60 * 24)) / (60 * 60);
	while (lonlon >= 86400)
	{
		++tm->day;
		if (tm->day == dim[i] + 1)
		{
			tm->day = 1;
			++tm->month;
			++i;
			if (tm->month == 12 + 1)
			{
				tm->month = 1;
				++tm->year;
				if (tm->year % 4 == 0 && (tm->year % 100 != 0\
					|| tm->year % 400 == 0))
					dim[1] = 29;
				else
					dim[1] = 28;
				i = 0;
			}
		}
		lonlon -= 86400;
	}
	return (ft_date_format(tm));
}

char	*get_date_negative(long long lonlon, t_tm *tm, int *dim)
{
	int		i;
	
	tm->year = 1969; 
	tm->month = 12;
   	tm->day = dim[11];
	tm->hour = 24; 
	tm->minute = 60; 
	tm->second = 60;
	lonlon *= -1;
	tm->second -= (lonlon % 60);
	tm->minute -= ((lonlon % (60 * 60)) / 60);
	tm->hour -= ((lonlon % (60 * 60 * 24)) / (60 * 60));
	if (tm->second == 60)
		tm->second = 0;
	if (tm->second)
		tm->minute -= 1;
	if (tm->minute == 60)
		tm->minute = 0;
	if (tm->second || tm->minute)
		tm->hour -= 1;
	if (tm->hour == 24)
		tm->hour = 0;

	i = 11;
	while (lonlon > 86400)
	{
		--tm->day;
		if (tm->day == 0)
		{
			if (i)
				--i;
			else
				i = 11;	
			tm->day = dim[i];
			--tm->month;
			if (tm->month == 0)
			{
				tm->month = 12;
				--tm->year;
				if (tm->year % 4 == 0 && (tm->year % 100 != 0\
					|| tm->year % 400 == 0))
					dim[1] = 29;
				else
					dim[1] = 28;
			}
		}
		lonlon -= 86400;
	}
	return (ft_date_format(tm));
}

char	*ft_itodate(long long lonlon)
{
	t_tm	*tm;
	int		dim[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (!(tm = (t_tm *)malloc(sizeof(t_tm) * 1)))
		exit (-1);
	if (lonlon < 0)
		return (get_date_negative(lonlon, tm, dim));
	else
		return (get_date_positive(lonlon, tm, dim));
}

char	*get_string(va_list ap, t_cs *cs)
{
	char 				*str;
	char				 c;
	char				ch;
	short				sh;
	unsigned char		uch;
	unsigned short		ush;
	unsigned long long	ulonlon;
	long long			lonlon;
	
	if (*cs->ptr == 'd' || *cs->ptr == 'i')
	{
		if (cs->len == 1)
		{
			ch = (char)va_arg(ap, int);
			return (ft_itoa_base(ch, 10, cs));
		}	
		if (cs->len == 2)
		{
			sh = (short)va_arg(ap, int);
			return (ft_itoa_base(sh, 10, cs));
		}
		if (cs->len == 0)
			return (ft_itoa_base(va_arg(ap, int), 10, cs));
		else if (cs->len == 3)
			return (ft_itoa_base(va_arg(ap, long), 10, cs));
		else if (cs->len == 4)
			return (ft_itoa_base(va_arg(ap, long long), 10, cs));
	}
	if (*cs->ptr == 'u' || *cs->ptr == 'U')
	{
		if (cs->len == 1)
		{
			uch = (unsigned char)va_arg(ap, unsigned int);
			return (ft_itoa_base_uns(uch, 10, cs));
		}	
		if (cs->len == 2)
		{
			ush = (unsigned short)va_arg(ap, unsigned int);
			return (ft_itoa_base_uns(ush, 10, cs));
		}
		if (cs->len == 0)
			return (ft_itoa_base_uns(va_arg(ap, unsigned int), 10, cs));
		else if (cs->len == 3)
			return (ft_itoa_base_uns(va_arg(ap, unsigned long), 10, cs));
		else if (cs->len == 4)
			return (ft_itoa_base_uns(va_arg(ap, unsigned long long), 10, cs));
	}
	if (*cs->ptr == 'o')
	{
		if (cs->len == 1)
		{
			uch = (unsigned char)va_arg(ap, unsigned int);
			return (ft_itoa_base_uns(uch, 8, cs));
		}	
		if (cs->len == 2)
		{
			ush = (unsigned short)va_arg(ap, unsigned int);
			return (ft_itoa_base_uns(ush, 8, cs));
		}
		if (cs->len == 0)
			return (ft_itoa_base_uns(va_arg(ap, unsigned int), 8, cs));
		else if (cs->len == 3)
			return (ft_itoa_base_uns(va_arg(ap, unsigned long), 8, cs));
		else if (cs->len == 4)
			return (ft_itoa_base_uns(va_arg(ap, unsigned long long), 8, cs));
	}
	if (*cs->ptr == 'x' || *cs->ptr == 'X')
	{
		if (cs->len == 1)
		{
			uch = (unsigned char)va_arg(ap, unsigned int);
			return (ft_itoa_base_uns(uch, 16, cs));
		}	
		if (cs->len == 2)
		{
			ush = (unsigned short)va_arg(ap, unsigned int);
			return (ft_itoa_base_uns(ush, 16, cs));
		}
		if (cs->len == 0)
			return (ft_itoa_base_uns(va_arg(ap, unsigned int), 16, cs));
		else if (cs->len == 3)
			return (ft_itoa_base_uns(va_arg(ap, unsigned long), 16, cs));
		else if (cs->len == 4)
			return (ft_itoa_base_uns(va_arg(ap, unsigned long long), 16, cs));
	}
	if (*cs->ptr == 'c')
	{
		c = va_arg(ap, unsigned int);
		if (c == 0)
		{	
			cs->type = 0;
			cs->minwid += 1;
			cs->ret -= 1;
			return (ft_strcpy(ft_strnew(2), "^@"));
		}
		else
			return (ft_memset(ft_strnew(1), c, 1));
	}	
	if (*cs->ptr == 's')
	{
		str = va_arg(ap, char *);
		if (!str)
			return (ft_strcpy(ft_strnew(6), "(null)"));
		return (ft_strjoin("", str));
	}
	if (*cs->ptr == 'p')
	{
		return (ft_itoa_base((long long)va_arg(ap, void *), 16, cs));
	}
	if (*cs->ptr == '%')
	{
		return (ft_memset(ft_strnew(1), '%', 1));
	}	
	if (*cs->ptr == 'f' || *cs->ptr == 'e' || *cs->ptr == 'g')
	{
		if (cs->ext)
			return (ft_itoa_float(va_arg(ap, long double), cs));
		else
			return (ft_itoa_float(va_arg(ap, double), cs));
	}
	if (*cs->ptr == 'b')
	{
		ulonlon = va_arg(ap, unsigned long long);
		
		if (cs->len == 1)
			return (ft_print_bits(ulonlon, 8));
		else if (cs->len == 2)
			return (ft_print_bits(ulonlon, 16));
		else if (cs->len == 0)
			return (ft_print_bits(ulonlon, 32));
		else if (cs->len == 3 || cs->len == 4)
			return (ft_print_bits(ulonlon, 64));
	}
	if (*cs->ptr == 'k')
	{
		lonlon = va_arg(ap, long long);
		return (ft_itodate(lonlon));
	}
	c = *cs->ptr;
	return (ft_memset(ft_strnew(1), c, 1));
}

void	ft_putstr_null(char *str)
{
	while (*str)
	{
		while (*str && *str != '^')
		{
			ft_putchar(*str);
			++str;
		}
		if (*str == '^')
		{
			ft_putchar(0);
			str += 2;
		}
	}
}
		
char	*thousands_separation(char *str)
{
	char 	*result;
	int		increment;
	int		counter;
	int		dot;
	char	*new;
	int		len;
	int		i;

	result = str;
	increment = 0;
	counter = 0;
	dot = 0;
	while (*str && *str != '.' && (!ft_isdigit(*str) || *str == '0'))
		++str;
	while (ft_isdigit(*str))
	{
		++str;
		++counter;
	}
	if (*str == '.')
		dot = 1;
	if (counter > 3)
	{
		if (counter % 3 != 0)
			increment = counter / 3;
		else
			increment = (counter / 3) - 1;
	}
	len = ft_strlen(result) + increment;
	if (increment)
	{
		new = ft_strnew(len);
		if (dot)
		{
			--len;
			while (result[len - increment] != '.') 
			{
				new[len] = result[len - increment];
				--len;
			}
			new[len] = result[len - increment];
		}
		--len;
		while (increment)
		{
			i = 0;
			while (i < 3)
			{
				new[len] = result[len - increment];
				--len;
				++i;
			}
			new[len] = ',';
			--increment;
			--len;
		}
		while (len)
		{
			new[len] = result[len - increment];
			--len;
		}
		new[len] = result[len - increment];
		free(result);
		return (new);
	}
	return (result);
}

int		print_type(t_cs *cs, va_list ap, va_list bp)
{
	char		*str;
	va_list		tp;

	if (cs->arg)
	{
		va_copy(tp, bp);
		while (--cs->arg)
			va_arg(tp, void*);
		va_end(ap);
		va_copy(ap, tp);
		va_end(tp);
	}	
	str = get_string(ap, cs);
	*cs->ptr == 'o' ? str = hash(str, cs) : 0;
	str = precision(str, cs);
	*cs->ptr == 'x' || *cs->ptr == 'X' ||\
		*cs->ptr == 'p' ? str = hash(str, cs) : 0;
	str = plus_and_space(str, cs);
	str = minimum_and_minus(str, cs);
	if (cs->flag['\''] && (*cs->ptr == 'd' || *cs->ptr == 'i'\
		|| *cs->ptr == 'u' || *cs->ptr == 'f'))
		str = thousands_separation(str);
	if (!cs->type)
		ft_putstr_null(str);
	else
		ft_putstr(str);
	cs->ret += ft_strlen(str);
	free(str);
	++cs->ptr;
	return (0);
}
