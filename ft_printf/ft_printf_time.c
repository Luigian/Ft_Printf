/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:06:53 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/26 20:59:22 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_tifor(t_tms *t)
{
	char	*date;
	char	*temp;

	date = t->sec < 10 ? pf_strjoin("0", ft_itoa(t->sec), 2)\
		: ft_itoa(t->sec);
	date = pf_strjoin(":", date, 2);
	temp = t->min < 10 ? pf_strjoin("0", ft_itoa(t->min), 2)\
		: ft_itoa(t->min);
	date = pf_strjoin(temp, date, 3);
	date = pf_strjoin(":", date, 2);
	temp = t->hr < 10 ? pf_strjoin("0", ft_itoa(t->hr), 2)\
		: ft_itoa(t->hr);
	date = pf_strjoin(temp, date, 3);
	date = pf_strjoin("T", date, 2);
	temp = t->day < 10 ? pf_strjoin("0", ft_itoa(t->day), 2)\
		: ft_itoa(t->day);
	date = pf_strjoin(temp, date, 3);
	date = pf_strjoin("-", date, 2);
	temp = t->mth < 10 ? pf_strjoin("0", ft_itoa(t->mth), 2)\
		: ft_itoa(t->mth);
	date = pf_strjoin(temp, date, 3);
	date = pf_strjoin("-", date, 2);
	temp = ft_itoa(t->yr);
	date = pf_strjoin(temp, date, 3);
	return (pf_strjoin(date, "+00:00", 1));
}

void	pf_tipos(long long lonlon, t_tms *t, int *dim, int i)
{
	t->sec = lonlon % 60;
	t->min = (lonlon % (60 * 60)) / 60;
	t->hr = (lonlon % (60 * 60 * 24)) / (60 * 60);
	while (lonlon >= 86400)
	{
		if (++t->day == dim[i] + 1)
		{
			t->day = 1;
			++i;
			if (++t->mth == 12 + 1)
			{
				t->mth = 1;
				dim[1] = ++t->yr % 4 == 0 && (t->yr % 100 != 0\
					|| t->yr % 400 == 0) ? 29 : 28;
				i = 0;
			}
		}
		lonlon -= 86400;
	}
}

void	pf_tineg(long long lonlon, t_tms *t, int *dim, int i)
{
	t->sec -= (lonlon % 60);
	t->min -= ((lonlon % (60 * 60)) / 60);
	t->hr -= ((lonlon % (60 * 60 * 24)) / (60 * 60));
	t->sec == 60 ? t->sec = 0 : 0;
	t->sec ? t->min -= 1 : 0;
	t->min == 60 ? t->min = 0 : 0;
	t->sec || t->min ? t->hr -= 1 : 0;
	t->hr == 24 ? t->hr = 0 : 0;
	i = 11;
	while (lonlon > 86400)
	{
		if (--t->day == 0)
		{
			i = i ? i - 1 : 11;
			t->day = dim[i];
			if (--t->mth == 0)
			{
				t->mth = 12;
				dim[1] = --t->yr % 4 == 0 && (t->yr % 100 != 0\
				|| t->yr % 400 == 0) ? 29 : 28;
			}
		}
		lonlon -= 86400;
	}
}

void	pf_tinit(t_tms *t, int dim[], char c)
{
	if (c == '-')
	{
		t->yr = 1969;
		t->mth = 12;
		t->day = dim[11];
		t->hr = 24;
		t->min = 60;
		t->sec = 60;
	}
	else
	{
		t->yr = 1970;
		t->mth = 1;
		t->day = 1;
		t->hr = 0;
		t->min = 0;
		t->sec = 0;
	}
}

char	*pf_time(t_ptf *p)
{
	long long	lonlon;
	char		*str;
	t_tms		t;
	int			dim[12];
	int			i;

	pf_months(dim);
	i = 0;
	lonlon = va_arg(p->ap, long long);
	if (lonlon < 0)
	{
		pf_tinit(&t, dim, '-');
		pf_tineg(lonlon * -1, &t, dim, i);
	}
	else
	{
		pf_tinit(&t, dim, '+');
		pf_tipos(lonlon, &t, dim, i);
	}
	str = pf_tifor(&t);
	str = pf_widmin(str, p);
	ft_putstr(str);
	return (str);
}
