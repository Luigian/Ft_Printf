/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:19:00 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/12 13:09:14 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

typedef struct		s_cs
{
	unsigned int	hash;
	unsigned int	zero;
	unsigned int	minus;
	unsigned int	space;
	unsigned int	plus;
	int				minwid;
	int				preci;
	unsigned int	len;
	unsigned int	ext;
	unsigned char	type;
	unsigned char	scape;
	unsigned char	other;
	char			*ptr;
	const char		*begin;
	char			*bef;
	char			*aft;
	int				ret;
	int				exp;
	unsigned int	g;
	char			*temp;
	unsigned int	arg;
	unsigned int	apo;
}					t_cs;

int			ft_printf(const char *fmt, ...);
int			print_argument(va_list ap, va_list bp, t_cs *cs);

t_cs		*create_object(const char *fmt);
void		reset_object(t_cs *cs);

int			store_format_specifications(va_list ap, va_list bp, t_cs *cs);
int			store_flag(t_cs *cs);
int			store_decimal(va_list ap, va_list bp, t_cs *cs);
int			store_length(t_cs *cs);

int			is_type_specificator(char c);
int			is_scape_specificator(char c);
int			is_flag(char c);
int			is_decimal(char c);
int			is_length(char c);
int			is_other_flag(char c);
int			is_other_char(char c);

int			print_type(va_list ap, va_list bp, t_cs *cs);
char		*get_string(va_list ap, t_cs *cs);
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
