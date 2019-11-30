/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:19:00 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/29 09:24:05 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_ptf
{
	int			f[128];
	int			wid;
	int			pre;
	int			len;
	int			ext;
	char		*ptr;
	char		*beg;
	char		*bef;
	char		*aft;
	int			ret;
	int			exp;
	int			g;
	char		*tmp;
	int			arg;
	va_list		ap;
	va_list		bp;
	va_list		tp;
	int			sgn;
}				t_ptf;

typedef struct	s_tms
{
	int			yr;
	int			mth;
	int			day;
	int			hr;
	int			min;
	int			sec;
}				t_tms;

typedef char	*(*t_fpa)(t_ptf *p);

/*
** ft_printf_master.c
*/

int				ft_printf(const char *fmt, ...);
void			pf_init(const char *fmt, t_ptf *p);
void			pf_reset(t_ptf *p);
void			pf_print(t_ptf *p);
void			pf_funfill(t_fpa fun[]);

/*
** ft_printf_store.c
*/

void			pf_store(t_ptf *p);
void			pf_widarg(t_ptf *p);
void			pf_prewid(t_ptf *p);
void			pf_prearg(t_ptf *p);
void			pf_length(t_ptf *p);

/*
** ft_printf_cspd.c
*/

char			*pf_other(t_ptf *p);
char			*pf_char(t_ptf *p);
char			*pf_string(t_ptf *p);
char			*pf_pointer(t_ptf *p);
char			*pf_decimal(t_ptf *p);

/*
** ft_printf_ouxf.c
*/

char			*pf_octal(t_ptf *p);
char			*pf_unsigned(t_ptf *p);
char			*pf_hexa(t_ptf *p);
char			*pf_float(t_ptf *p);

/*
** ft_printf_flags.c
*/

char			*pf_precision(char *str, t_ptf *p);
char			*pf_zero(char *str, t_ptf *p);
char			*pf_pluspace(char *str, t_ptf *p);
char			*pf_widmin(char *str, t_ptf *p);

/*
** ft_printf_tools.c
*/

int				pf_argindex(char *str);
char			*pf_strjoin(char *a, char *b, int code);
void			pf_putchar(char *str);
void			pf_months(int dim[]);

/*
** ft_printf_itoa.c
*/

char			*pf_itoab(long long n, int base, t_ptf *p);
char			*pf_ibhelper(long long nbr, int len, t_ptf *p, int base);
char			*pf_itoabuns(unsigned long long n, int base, t_ptf *p);
char			*pf_itoaf(long double n, t_ptf *p);

/*
** ft_printf_float.c
*/

char			*pf_prefloat(long double n, t_ptf *p);
int				pf_ptrchange(long double n, t_ptf *p);
void			pf_postull(long double n, t_ptf *p);
void			pf_getfloat(long double n, t_ptf *p);

/*
** ft_printf_round.c
*/

int				pf_roundfloat(t_ptf *p);
int				pf_roundnine(t_ptf *p, char *pt, int len);
int				pf_roundrecursion(char *pt, int len);
void			pf_copyround(t_ptf *p, char *pt);

/*
** ft_printf_exponent.c
*/

void			pf_getexp(t_ptf *p);
char			*pf_strncpy(char *dst, const char *src, size_t n);
void			pf_exphelper(t_ptf *p, char *b, int trz, int len);
char			*pf_precizero(t_ptf *p, char *tm);
int				pf_trimzeros(char *str, int len, char c);

/*
** ft_printf_bonus.c
*/

char			*pf_binary(t_ptf *p);
char			*pf_thousands(char *str);
int				pf_increment(char *str, int *dot);
char			*pf_thelper(char *str, char *nw, int inc, int len);

/*
** ft_printf_time.c
*/

char			*pf_time(t_ptf *p);
void			pf_tinit(t_tms *t, int dim[], char c);
void			pf_tineg(long long lonlon, t_tms *t, int *dim, int i);
void			pf_tipos(long long lonlon, t_tms *t, int *dim, int i);
char			*pf_tifor(t_tms *t);

#endif
