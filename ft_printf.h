/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:19:00 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/21 21:16:31 by lusanche         ###   ########.fr       */
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
	int				minwid;
	int				preci;
	unsigned int	len;
	unsigned int	ext;
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
	va_list			tp;
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

// print_cspdi
char		*print_other(t_cs *cs);
char		*print_char(t_cs *cs);
char		*print_string(t_cs *cs);
char		*print_pointer(t_cs *cs);
char		*print_decimal(t_cs *cs);

// print_ouxf
char		*print_octal(t_cs *cs);
char		*print_unsigned(t_cs *cs);
char		*print_hexa(t_cs *cs);
char		*print_float(t_cs *cs);

// print_bk
char		*print_binary(t_cs *cs);
char		*print_date(t_cs *cs);

// flags
char		*precision(char *str, t_cs *cs);
char		*zero(char *str, t_cs *cs);
char		*plus_and_space(char *str, t_cs *cs);
char		*minimum_and_minus(char *str, t_cs *cs);

//tools
int			is_arg_index(char *str);
void		fill_fun_pointer_array(funPointer fpa[]);
char		*ft_strjoin_2(char *a, char *b, int code);
void		put_char_null(char *str);

//itoa
char		*ft_itoa_base(long long n, int base, t_cs *cs);
char		*ft_itoa_base_uns(unsigned long long n, int base, t_cs *cs);
char		*ft_itoa_float(long double n, t_cs *cs);
char		*ft_itoa_extended(long double n, t_cs *cs);
char		*ft_strncpy_zero(char *dst, const char *src, size_t n);
int			round_all_nines(t_cs *cs, char *join, int len);
int			rounding(char *join, int p_len);
int			round_float(t_cs *cs);
char		*add_minus(char *str);
int			trim_trailing_zeros_e(char *str, int len);
int			get_exp_format(t_cs *cs);
int			turnback_ptr_content(t_cs *cs);
int			change_ptr_content(t_cs *cs, long double n);
int			trim_trailing_zeros(char *str, int len);

//bonus
char		*get_date_negative(long long lonlon, t_tm *tm, int *dim);
char		*get_date_positive(long long lonlon, t_tm *tm, int *dim);
char		*ft_date_format(t_tm *tm);
char		*thousands_separation(char *str);



#endif
