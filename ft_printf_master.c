/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_master.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:18:19 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/11 20:24:41 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
/*
void	print_object(t_cs *cs)
{
	printf("hash: %u\n", cs->hash);
	printf("zero: %u\n", cs->zero);
	printf("minus: %u\n", cs->minus);
	printf("space: %u\n", cs->space);
	printf("plus: %u\n", cs->plus);
	printf("minwid: %u\n", cs->minwid);
	printf("preci: %d\n", cs->preci);
	printf("len: %u\n", cs->len);
	printf("ext: %d\n", cs->ext);
	printf("type: %c\n", cs->type);
	printf("scape: %d\n", cs->scape);
	printf("other: %c\n", cs->other);
	printf("ptr: %s", cs->ptr);
	printf("-----------\n");
}
*/
int		store_format_specifications(va_list ap, va_list bp, t_cs *cs)
{
	while (1)
	{
		if (is_flag(*cs->ptr))
			store_flag(cs);
		else if (is_decimal(*cs->ptr))
			store_decimal(ap, bp, cs);
		else if (is_length(*cs->ptr))
			store_length(cs);
		else if (is_other_flag(*cs->ptr))
			++cs->ptr;
		else
			break;
	}
	if (*cs->ptr == 'd')
		cs->hash = 0;
	if (*cs->ptr == 'u' || *cs->ptr == 'U')
	{
		cs->hash = 0;
		cs->space = 0;
		cs->plus = 0;
		if (*cs->ptr == 'U')
			cs->len = 3;
	}
	if (*cs->ptr == 'o' || *cs->ptr == 'x' || *cs->ptr == 'X')
	{
		cs->space = 0;
		cs->plus = 0;
	}
	if (*cs->ptr == 'c' || *cs->ptr == '%' || is_other_char(*cs->ptr))
	{
		cs->hash = 0;
		cs->space = 0;
		cs->plus = 0;
		cs->preci = -1;
	}
	if (*cs->ptr == 's')
	{
		cs->hash = 0;
		cs->space = 0;
		cs->plus = 0;
	}
	if (*cs->ptr == 'p')
	{
		cs->space = 0;
		cs->plus = 0;
		cs->hash = 1;
	}
	if (*cs->ptr == 'f' || *cs->ptr == 'e' || *cs->ptr == 'g')
	{
		if (cs->preci == -1)
			cs->preci = 6;
		if (*cs->ptr == 'g' && cs->preci == 0)
			cs->preci = 1;
	}
	return (0);
}

void	reset_object(t_cs *cs)
{
	cs->hash = 0;
	cs->zero = 0;
	cs->minus = 0;
	cs->space = 0;
	cs->plus = 0;
	cs->minwid = 0;
	cs->preci = -1;
	cs->len = 0;
	cs->ext = 0;
	cs->type = '0';
	cs->scape = 0;
	cs->other = '0';
	cs->bef = NULL;
	cs->aft = NULL;
	cs->exp = 0;
	cs->g = 0;
	cs->temp = NULL;
	cs->arg = 0;
}

t_cs	*create_object(const char *fmt)
{
	t_cs	*cs;

	if (!(cs = (t_cs *)malloc(sizeof(t_cs) * 1)))
		return (NULL);
	reset_object(cs);
	cs->begin = fmt;
	cs->ptr = (char *)fmt;
	cs->bef = NULL;
	cs->aft = NULL;
	cs->ret = 0;
	return (cs);
}

int		print_argument(va_list ap, va_list bp, t_cs *cs)
{
	reset_object(cs);
	store_format_specifications(ap, bp, cs);
	if (is_type_specificator(*cs->ptr))
		print_type(ap, bp, cs);
	else if (is_scape_specificator(*cs->ptr))
		cs->scape = *cs->ptr;
	else if (*cs->ptr)
	{
		print_type(ap, bp, cs);
//		cs->other = *cs->ptr;
	}
	else
		return (1);
	++(cs->ptr);
	return (0);
}
	
int		ft_printf(const char *fmt, ...)
{
	t_cs		*cs;
	va_list		ap;
	va_list		bp;
	
	if (!(cs = create_object(fmt)))
		exit (-1);
	va_start(ap, fmt);
	va_copy(bp, ap);
	while (*cs->ptr)
	{
		if (*cs->ptr == '%')
		{
			++cs->ptr;
			print_argument(ap, bp, cs);
		}	
		else
		{
			ft_putchar(*cs->ptr);
			++cs->ptr;
			++cs->ret;
		}
	}
	free(cs);
	va_end(ap);
	va_end(bp);
	return (cs->ret);
}
