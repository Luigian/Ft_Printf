/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 23:42:40 by lusanche          #+#    #+#             */
/*   Updated: 2019/11/26 21:40:52 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

int					ft_atoi(const char *str);
int					ft_chrstr(unsigned char c, const char *s);
int					ft_isdigit(int c);
int					ft_isspecial(int c);
char				*ft_itoa(int n);
void				*ft_memset(void *b, int c, size_t len);
int					ft_nbrlen(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *str);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strnew(size_t size);

#endif
