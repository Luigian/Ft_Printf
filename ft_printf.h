/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:19:00 by lusanche          #+#    #+#             */
/*   Updated: 2019/10/25 21:58:43 by lusanche         ###   ########.fr       */
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
	unsigned int	minusSym;
	unsigned int	space;
	unsigned int	plusSym;
	unsigned int	miniWid;
	unsigned int	precis;
	unsigned int	lenMod;
	unsigned int	extPre;
	unsigned char	typeCon;
	unsigned char	scapeSec;
	unsigned char	otherChar;
}					t_cs;

int		ft_printf(const char *fmt, ...);
int		ft_print_argument(va_list ap, const char *fmt);
t_cs	create_cs_object(void);
int		store_conv_specs(const char *fmt, t_cs conSpec);
int		is_format_specificator(char c);
int		is_type_of_conversion(char c);

#endif
