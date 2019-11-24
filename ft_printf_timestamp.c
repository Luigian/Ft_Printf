/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_timestamp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:06:53 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/23 20:11:51 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
















void	get_date_positive(long long lonlon, t_tm *tm, int *dim, int i)
{
	tm->second = lonlon % 60;
	tm->minute = (lonlon % (60 * 60)) / 60;
	tm->hour = (lonlon % (60 * 60 * 24)) / (60 * 60);
	while (lonlon >= 86400)
	{
		if (++tm->day == dim[i] + 1)
		{
			tm->day = 1;
			++i;
			if (++tm->month == 12 + 1)
			{
				tm->month = 1;
				dim[1] = ++tm->year % 4 == 0 && (tm->year % 100 != 0\
					|| tm->year % 400 == 0) ? 29 : 28;
				i = 0;
			}
		}
		lonlon -= 86400;
	}
}


void	get_date_negative(long long lonlon, t_tm *tm, int *dim, int i)
{
	tm->second -= (lonlon % 60);
	tm->minute -= ((lonlon % (60 * 60)) / 60);
	tm->hour -= ((lonlon % (60 * 60 * 24)) / (60 * 60));
	tm->second == 60 ? tm->second = 0 : 0;
	tm->second ? tm->minute -= 1 : 0;
	tm->minute == 60 ? tm->minute = 0 : 0;
	tm->second || tm->minute ? tm->hour -= 1 : 0;
	tm->hour == 24 ? tm->hour = 0 : 0;
	i = 11;
	while (lonlon > 86400)
	{
		if (--tm->day == 0)
		{
			i = i ? i - 1 : 11;
			tm->day = dim[i];
			if (--tm->month == 0)
			{
				tm->month = 12;
				dim[1] = --tm->year % 4 == 0 && (tm->year % 100 != 0\
				|| tm->year % 400 == 0) ? 29 : 28;
			}
		}
		lonlon -= 86400;
	}
}


void	init_time(t_tm *tm, int dim[], char c)
{
	if (c == '-')
	{
		tm->year = 1969;
		tm->month = 12;
   		tm->day = dim[11];
		tm->hour = 24;
		tm->minute = 60;
		tm->second = 60;
	}
	else
	{
		tm->year = 1970;
		tm->month = 1;
	   	tm->day = 1;
		tm->hour = 0;
		tm->minute = 0;
		tm->second = 0;
	}
}

char	*print_date(t_cs *cs)
{
	long long	lonlon;
	char		*str;
	t_tm		tm;
	int			dim[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int			i;

	i = 0;
	lonlon = va_arg(cs->ap, long long);
	if (lonlon < 0)
	{
		init_time(&tm, dim, '-');
		get_date_negative(lonlon * -1 , &tm, dim, i);
	}
	else
	{
		init_time(&tm, dim, '+');
		get_date_positive(lonlon, &tm, dim, i);
	}
	str = ft_date_format(&tm);
	str = minimum_and_minus(str, cs);
	ft_putstr(str);
	return (str);
}
