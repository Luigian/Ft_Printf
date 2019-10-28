/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:19:00 by lusanche          #+#    #+#             */
/*   Updated: 2019/10/27 21:40:27 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>

typedef struct		s_cs
{
	unsigned int	hash;
	unsigned int	zero;
	unsigned int	minus;
	unsigned int	space;
	unsigned int	plus;
	unsigned int	minwid;
	int				preci;
	unsigned int	len;
	unsigned int	ext;
	unsigned char	type;
	unsigned char	scape;
	unsigned char	other;
	const char		*ptr;
}					t_cs;

int			ft_printf(const char *fmt, ...);
int			print_argument(va_list ap, t_cs *cs);

t_cs		*create_object(const char *fmt);
void		reset_object(t_cs *cs);

int			store_format_specifications(t_cs *cs);
int			store_flag(t_cs *cs);
int			store_decimal(t_cs *cs);
int			store_length(t_cs *cs);

int			is_type_specificator(char c);
int			is_scape_specificator(char c);
int			is_flag(char c);
int			is_decimal(char c);
int			is_length(char c);

int			print_type(va_list ap, t_cs *cs);
char		*get_string(va_list ap, t_cs *cs);


#endif
