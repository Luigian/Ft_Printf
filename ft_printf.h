/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:19:00 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/19 19:21:05 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

typedef struct		s_cs
{
	int				flag[128]; 
	int				base[128]; 
	int				minwid;
	int				preci;
	unsigned int	len;
	unsigned int	ext;
	unsigned char	type;
	char			*ptr;
	const char		*begin;
	char			*bef;
	char			*aft;
	int				ret;
	int				exp;
	unsigned int	g;
	char			*temp;
	unsigned int	arg;
	va_list			ap;
	va_list			bp;
}					t_cs;

typedef struct		s_tm
{
	int				year;
	int				month;
	int				day;
	int				hour;
	int				minute;
	int				second;
}					t_tm;

typedef char *(*funPointer)(t_cs *);

// master 
int			ft_printf(const char *fmt, ...);
void		print_argument(t_cs *cs);
void		init_struct(const char *fmt, t_cs *cs);
void		reset_object(t_cs *cs);
int			close_program(int code, t_cs cs);

// store 
void		store_format_specifications(t_cs *cs);
void		store_length(t_cs *cs);
void		store_precision_minwid(t_cs *cs);
void		precision_as_argument(t_cs *cs);
void		minwid_as_argument(t_cs *cs);
int			is_arg_index(char *str);
void		store_adjustments(t_cs *cs);

// print 
void		print_type(t_cs *cs);
void		fill_fun_pointer_array(funPointer fpa[]);
char		*print_other(t_cs *cs);
char		*print_date(t_cs *cs);
char		*print_binary(t_cs *cs);
char		*print_float(t_cs *cs);
char		*print_pointer(t_cs *cs);
char		*print_string(t_cs *cs);
char		*print_char(t_cs *cs);
char		*print_base_unsigned(t_cs *cs);
char		*print_decimal(t_cs *cs);


char		*hash(char *str, t_cs *cs);
char		*precision(char *str, t_cs *cs);
char		*minimum_and_minus(char *str, t_cs *cs);
char		*plus_and_space(char *str, t_cs *cs);
char		*zero(char *str, t_cs *cs);
char		*ft_itoa_base(long long n, int base, t_cs *cs);
char		*ft_itoa_base_uns(unsigned long long n, int base, t_cs *cs);
char		*ft_itoa_float(long double n, t_cs *cs);
char		*ft_itoa_extended(long double n, t_cs *cs);
char		*ft_itoa_unsigned(unsigned long long n);
#endif
