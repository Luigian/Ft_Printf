/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:25:58 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/21 12:20:57 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
//	free(tm);
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























char	*do_o(t_cs *cs)
{
	unsigned long long	ulonlon;
	char				*str;

	ulonlon = va_arg(cs->ap, unsigned long long);
	if (cs->len == 0)
		str = ft_itoa_base_uns((unsigned int)ulonlon, 8, cs);
	else if (cs->len == 1)
		str = ft_itoa_base_uns((unsigned char)ulonlon, 8, cs);
	else if (cs->len == 2)
		str = ft_itoa_base_uns((unsigned short)ulonlon, 8, cs);
	else if (cs->len == 3)
		str = ft_itoa_base_uns((unsigned long)ulonlon, 8, cs);
	else if (cs->len == 4)
		str = ft_itoa_base_uns(ulonlon, 8, cs);
	if (cs->flag['#'] && str[0] != '0')
		str = ft_strjoin_2("0", str);
	str = precision(str, cs);
	str = plus_and_space(str, cs);
	str = minimum_and_minus(str, cs);
	ft_putstr(str);
	return (str);
}

char	*print_u(t_cs *cs)
{
	unsigned long long	ulonlon;
	char				*str;

	ulonlon = va_arg(cs->ap, unsigned long long);
	if (cs->len == 1)
		str = ft_itoa_base_uns((unsigned char)ulonlon, 10, cs);
	else if (cs->len == 2)
		str = ft_itoa_base_uns((unsigned short)ulonlon, 10, cs);
	else if (cs->len == 3)
		str = ft_itoa_base_uns((unsigned long)ulonlon, 10, cs);
	else if (cs->len == 4)
		str = ft_itoa_base_uns(ulonlon, 10, cs);
	else 
		str = ft_itoa_base_uns((unsigned int)ulonlon, 10, cs);
	str = precision(str, cs);
	str = plus_and_space(str, cs);
	str = minimum_and_minus(str, cs);
	if (cs->flag['\''])
		str = thousands_separation(str);
	ft_putstr(str);
	return (str);
}


char	*print_pointer(t_cs *cs)
{
	char	*str;
	
	str = ft_itoa_base((long long)va_arg(cs->ap, void *), 16, cs);
	str = precision(str, cs);
	str = ft_strjoin_2("0x", str);
	str = plus_and_space(str, cs);
	str = minimum_and_minus(str, cs);
	ft_putstr(str);
	return (str);

}

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


char	*print_string(t_cs *cs)
{
	char 	*s;
	char 	*str;
	char 	*new;

	s = va_arg(cs->ap, char *);
	if (!s)
		str = ft_strcpy(ft_strnew(6), "(null)");
	else
		str = ft_strjoin("", s);
	if (cs->preci < 0)
		str = precision(str, cs);
	else
	{
		new = ft_strncpy(ft_strnew(cs->preci), str, cs->preci);
		if (cs->flag['0'] && !cs->flag['-'])
			new = zero(new, cs);
		free(str);
		str = new;
	}
	str = plus_and_space(str, cs);
	str = minimum_and_minus(str, cs);
	ft_putstr(str);
	return (str);
}

char	*do_x(t_cs *cs)
{
	unsigned long long	ulonlon;
	char				*str;

	ulonlon = va_arg(cs->ap, unsigned long long);
	if (cs->len == 1)
		str = ft_itoa_base_uns((unsigned char)ulonlon, 16, cs);
	else if (cs->len == 2)
		str = ft_itoa_base_uns((unsigned short)ulonlon, 16, cs);
	else if (cs->len == 3)
		str = ft_itoa_base_uns((unsigned long)ulonlon, 16, cs);
	else if (cs->len == 4)
		str = ft_itoa_base_uns(ulonlon, 16, cs);
	else 
		str = ft_itoa_base_uns((unsigned int)ulonlon, 16, cs);
	str = precision(str, cs);
	if (cs->flag['#'] && *cs->ptr == 'x')
		str = ft_strjoin_2("0x", str);
	else if (cs->flag['#'] && *cs->ptr == 'X')
		str = ft_strjoin_2("0X", str);
	str = plus_and_space(str, cs);
	str = minimum_and_minus(str, cs);
	ft_putstr(str);
	return (str);
}

char	*print_decimal(t_cs *cs)
{
	long long	lonlon;
	char	 	*str;

	lonlon = va_arg(cs->ap, long long);
	if (cs->len == 1)
		str = ft_itoa_base((char)lonlon, 10, cs);
	else if (cs->len == 2)
		str = ft_itoa_base((short)lonlon, 10, cs);
	else if (cs->len == 3)
		str = ft_itoa_base((long)lonlon, 10, cs);
	else if (cs->len == 4)
		str = ft_itoa_base(lonlon, 10, cs);
	else 
		str = ft_itoa_base((int)lonlon, 10, cs);
	str = precision(str, cs);
	str = plus_and_space(str, cs);
	str = minimum_and_minus(str, cs);
	if (cs->flag['\''])
		str = thousands_separation(str);
	ft_putstr(str);
	return (str);
}

char	*print_float(t_cs *cs)
{
	char	*str;

	if (cs->ext)
		str = ft_itoa_float(va_arg(cs->ap, long double), cs);
	else
		str = ft_itoa_float(va_arg(cs->ap, double), cs);
	if (cs->flag['0'] && !cs->flag['-'])
		str = zero(str, cs);
	str = plus_and_space(str, cs);
	str = minimum_and_minus(str, cs);
	if (cs->flag['\''])
		str = thousands_separation(str);
	ft_putstr(str);
	return (str);
}

char	*print_binary(t_cs *cs)
{
	unsigned long long	ulonlon;
	int					bits;
	char				*str;
	int					i;

	ulonlon = va_arg(cs->ap, unsigned long long);
	bits = 32;	
	if (cs->len == 1)
		bits = 8;	
	else if (cs->len == 2)
		bits = 16;	
	else if (cs->len == 3 || cs->len == 4)
		bits = 64;	
	str = ft_strnew(bits);
	i = 0;
	while (bits--)
		str[i++] = (ulonlon >> bits & 1) + 48;
	str = precision(str, cs);
	str = plus_and_space(str, cs);
	str = minimum_and_minus(str, cs);
	ft_putstr(str);
	return (str);
}

char	*print_date(t_cs *cs)
{
	long long		lonlon;
	char	*str;
	t_tm	tm;
	int		dim[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	lonlon = va_arg(cs->ap, long long);
	if (lonlon < 0)
		str = get_date_negative(lonlon, &tm, dim);
	else
		str = get_date_positive(lonlon, &tm, dim);
	str = minimum_and_minus(str, cs);
	ft_putstr(str);
	return (str);
}

char	*print_char(t_cs *cs)
{
	char	 c;
	char	*str;
	
	c = va_arg(cs->ap, unsigned int);
	if (c == 0)
	{
		cs->minwid += 1;
		str = ft_strcpy(ft_strnew(2), "^@");
		str = precision(str, cs);
		str = minimum_and_minus(str, cs);
		put_char_null(str);
		cs->ret -= 1;
		return (str);
	}
	str = ft_memset(ft_strnew(1), c, 1);
	str = precision(str, cs);
	str = minimum_and_minus(str, cs);
	ft_putstr(str);
	return (str);
}	

char	*print_other(t_cs *cs)
{
	char	 c;
	char	*str;

	c = *cs->ptr;
	str = ft_memset(ft_strnew(1), c, 1);
	str = precision(str, cs);
	str = minimum_and_minus(str, cs);
	ft_putstr(str);
	return (str);
}



void	fill_fun_pointer_array(funPointer fpa[])
{
	int		i;

	i = 0;
	while (i < 128)
		fpa[i++] = &print_other;
//	fpa['d'] = &print_decimal;
//	fpa['i'] = &print_decimal;
//	fpa['u'] = &print_base_unsigned;
//	fpa['U'] = &print_base_unsigned;
//	fpa['o'] = &print_base_unsigned;
//	fpa['x'] = &print_base_unsigned;
//	fpa['X'] = &print_base_unsigned;
//	fpa['c'] = &print_char;
//	fpa['s'] = &print_string;	//     <------------------------
//	fpa['p'] = &print_pointer;
//	fpa['f'] = &print_float;
//	fpa['e'] = &print_float;
//	fpa['g'] = &print_float;
//	fpa['b'] = &print_binary;
//	fpa['k'] = &print_date;
}	

void		print_type(t_cs *cs)
{
	char		*str;
//	funPointer	fpa[128];
	
	if (*cs->ptr == 'o')
		str = do_o(cs);
	else if (*cs->ptr == 'x' || *cs->ptr == 'X')
		str = do_x(cs);
	else if (*cs->ptr == 'p')
		str = print_pointer(cs);
	else if (*cs->ptr == 'c')
		str = print_char(cs);
	else if (*cs->ptr == 's')
		str = print_string(cs);
	else if (*cs->ptr == 'u' || *cs->ptr == 'U')
		str = print_u(cs);
	else if (*cs->ptr == 'd' || *cs->ptr == 'i')
		str = print_decimal(cs);
	else if (*cs->ptr == 'f' || *cs->ptr == 'e' || *cs->ptr == 'g')
		str = print_float(cs);
	else if (*cs->ptr == 'b')
		str = print_binary(cs);
	else if (*cs->ptr == 'k')
		str = print_date(cs);
	else	
		str = print_other(cs);
//	else
//	{
//	fill_fun_pointer_array(fpa);
//	str = fpa[(int)*cs->ptr](cs);

//	str = precision(str, cs);
//	str = plus_and_space(str, cs);
//	str = minimum_and_minus(str, cs);
	
//	if (cs->flag['\''])
//		str = thousands_separation(str);

//	ft_putstr(str);
//	}

	cs->ret += ft_strlen(str);
	free(str);
	++cs->ptr;
	
}
