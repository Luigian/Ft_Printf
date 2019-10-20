/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 21:08:55 by lusanche          #+#    #+#             */
/*   Updated: 2019/10/19 22:10:43 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{

	void		*p = "pointer";
	char		ch = -128;
	short		sh = -32768;
	int			in = -2147483647;
	long		lo = -9223372036854775807;
	long long	lolo = -9223372036854775807;

	
//	ft_printf("hola\n%c\n%s\n%d\n", 'L', "como", 8 + 5);



//	c	
	printf("%c", 42);
	printf("\n");
///////////////////////////////////////////////////////////////////
//	s (14 characters)
	printf("%s", "silicon valley");
	printf("\n");
//	s with [minimum width]
	printf("%15s", "silicon valley");
	printf("\n");
//	s with [precision]
	printf("%.13s", "silicon valley");
	printf("\n");
//	s with [minimum width] and [precision]
	printf("%15.13s", "silicon valley");
	printf("\n");
//	s with [-] and [minimum width]
	printf("%-15s", "silicon valley");
	printf("\n");
//	s with [-] and [minimum width] and [precision]
	printf("%-15.13s", "silicon valley");
	printf("\n");
///////////////////////////////////////////////////////////////////
//	p	
	printf("%p", p);
	printf("\n");
///////////////////////////////////////////////////////////////////
//	d
	printf("%d", in); /// must be signed 'int' (-2,147,483,647, +2,147,483,647) 
	printf("\n");
//	d with [hh]
	printf("%hhd", ch);    /// must be declared as signed 'char' (−128, +127) 
	printf("\n");
//	d with [h]
	printf("%hd", sh);    /// must be declared as signed 'short' (−32,768, +32,767)
	printf("\n");
//	d with [l]
	printf("%ld", lo);    /// must be declared as signed 'long' (-9,223,372,036,854,775,807, +9,223,372,036,854,775,807)
	printf("\n");
//	d with [ll]
	printf("%lld", lolo);    /// must be declared as signed 'long long' (-9,223,372,036,854,775,807, +9,223,372,036,854,775,807)
	printf("\n");
/////////////////////////////////////
//	d with [minimum width]
	printf("%30d", -2147483647);
	printf("\n");
//	d with [0] and [minimum width]
	printf("%030d", -2147483647);
	printf("\n");
//	d with [-] and [minimum width]
	printf("%-30d", -2147483647);
	printf("\n");
//	d with [precision]                       //precision puts [0s]
	printf("%.20d", -2147483647);
	printf("\n");
//	d with [0] and [precision]               // [0] is ignored
	printf("%0.20d", -2147483647);
	printf("\n");
//	d with [minimum width] and [precision]
	printf("%40.30d", -2147483647);
	printf("\n");
//	d with [-] and [minimum width] and [precision]
	printf("%-40.30d", -2147483647);
	printf("\n");
//	d with [' ']
	printf("% d", 2147483647);                 //only for 'signed' positives
	printf("\n");
//	d with [+]
	printf("%+d", +2147483647);                 //for 'signed' pos, neg 
	printf("\n");
//	d with [+] and [minimum width]
	printf("%+30d", -2147483647);                  
	printf("\n");
//	d with [+] and [' '] and [minimum width]       //+ overrides a space
	printf("%+ 30d", -2147483647);                  
	printf("\n");
	





	return (0);
}
