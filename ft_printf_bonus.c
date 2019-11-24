/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:27:18 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/23 21:32:49 by lusanche         ###   ########.fr       */
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
/*
char	*ft_date_format(t_tm *tm)
{
	char 	*date;
	char 	*temp;
	char 	*del;

//	date = ft_strcpy(ft_strnew(25), "-0.-0.T0.:0.:0.+00:00");
	date = ft_itoa(tm->second);
	date = tm->second < 10 ? ft_strjoin_2("0", tm->second, 2) : 0;
	date = ft_strjoin_2(":", tm->second, 2);
	temp  = tm->minute < 10 ? ft_strjoin("0", ft_itoa(tm->minute), 2) : ft_itoa(tm->minute;
	 
	date = ft_strjoin(
	
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
	return (date);
}*/

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
	return (date);
}

/*
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
}*/