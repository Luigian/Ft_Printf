/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 21:08:55 by lusanche          #+#    #+#             */
/*   Updated: 2019/10/20 22:01:28 by lusanche         ###   ########.fr       */
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

/*
	printf("%#p\n", p);
	printf("%0p\n", p);
	printf("%-p\n", p);
	printf("% p\n", p);
	printf("%+p\n", p);
	printf("%10p\n", p);
	printf("%.5p\n", p);
	printf("%hp\n", p);
	printf("%hhp\n", p);
	printf("%lp\n", p);
	printf("%llp\n", p);
	printf("%Lp\n", p);
*/


//	c	
	printf("%c\n", 42);
//	c [minimum width]	
	printf("%20c\n", 42);
//	c [-] [minimum width]	
	printf("%-20c\n", 42);
printf("-------------------------------------------------------------------\n");
//	s
	printf("%s\n", "silicon valley");
//	s [precision]
	printf("%.13s\n", "silicon valley");
//	s [minimum width] [precision]
	printf("%15.13s\n", "silicon valley");
//	s [-] [minimum width] [precision]
	printf("%-15.13s\n", "silicon valley");
//	s [minimum width]
	printf("%15s\n", "silicon valley");
//	s [-] [minimum width]
	printf("%-15s\n", "silicon valley");
printf("-------------------------------------------------------------------\n");
//	p	
	printf("%p\n", p);
//	p [minimum width]	
	printf("%20p\n", p);
//	p [-] [minimum width]	
	printf("%-20p\n", p);
printf("-------------------------------------------------------------------\n");
//	d
	printf("%d\n", in);						// must be signed 'int' (-2,147,483,647, +2,147,483,647) 
//	d [hh]
	printf("%hhd\n", ch); 					// must be declared as signed 'char' (−128, +127) 
//	d [h]
	printf("%hd\n", sh);					// must be declared as signed 'short' (−32,768, +32,767)
//	d [l]
	printf("%ld\n", lo);					// must be declared as signed 'long' (-9,223,372,036,854,775,807, +9,223,372,036,854,775,807)
//	d [ll]
	printf("%lld\n", lolo);					// must be declared as signed 'long long' (-9,223,372,036,854,775,807, +9,223,372,036,854,775,807)

//	d [precision]  	                    	 //precision puts [0s]
	printf("%.30d\n", -2147483647);
//	d [minimum width] [precision]
	printf("%40.30d\n", 2147483647);
//	d [+] [minimum width] [precision]
	printf("%+40.30d\n", 2147483647);
//	d [' '] [minimum width] [precision]
	printf("% 40.30d\n", 2147483647);
	printf("%-40.30d\n", 2147483647);
	printf("%040.30d\n", 2147483647);
	printf("% +40.30d\n", 2147483647);
	printf("%- +40.30d\n", 2147483647);
	printf("%0+40.30d\n", 2147483647);
	printf("%- 40.30d\n", 2147483647);
	printf("%0 40.30d\n", 2147483647);
	printf("%40.30d\n", 2147483647);
	printf("%0-40.30d\n", 2147483647);
	printf("%-40.30d\n", 2147483647);
	printf("%- +40.30d\n", 2147483647);
	printf("%-+40.30d\n", 2147483647);
	printf("%0 +40.30d\n", 2147483647);
	printf("%+40.30d\n", 2147483647);
	printf("%0- +40.30d\n", 2147483647);
	printf("%0- +.30d\n", 2147483647);
	printf("%+.30d\n", 2147483647);
	printf("% +.30d\n", 2147483647);
	printf("%-+.30d\n", 2147483647);
	printf("%0+.30d\n", 2147483647);
	printf("%- +.30d\n", 2147483647);
	printf("%0- +.30d\n", 2147483647);
	printf("% .30d\n", 2147483647);
	printf("%- .30d\n", 2147483647);
	printf("%0 .30d\n", 2147483647);
	printf("% .30d\n", 2147483647);
	printf("%0- .30d\n", 2147483647);
	printf("%0-.30d\n", 2147483647);
	printf("%-.30d\n", 2147483647);
	printf("%0.30d\n", 2147483647);
	printf("%0-+40.30d\n", 2147483647);
	printf("%40d\n", 2147483647);
	printf("%+40d\n", 2147483647);
	printf("% 40d\n", 2147483647);
	printf("%-40d\n", 2147483647);
	printf("%040d\n", 2147483647);
	printf("% +40d\n", 2147483647);
	printf("%-+40d\n", 2147483647);
	printf("%0+40d\n", 2147483647);
	printf("%- 40d\n", 2147483647);
	printf("%0 40d\n", 2147483647);
	printf("%0 40.30d\n", 2147483647);
	printf("%40.30d\n", 2147483647);
	printf("%0-40d\n", 2147483647);
	printf("%- +40d\n", 2147483647);
	printf("%0 +40d\n", 2147483647);
	printf("%0+40d\n", 2147483647);
	printf("%+40d\n", 2147483647);
	printf("%0-+40d\n", 2147483647);
	printf("%0- +40d\n", 2147483647);
	printf("%+d\n", 2147483647);
	printf("%- +d\n", 2147483647);
	printf("%0 +d\n", 2147483647);
	printf("%0-+d\n", 2147483647);
	printf("%0+d\n", 2147483647);
	printf("%0- +d\n", 2147483647);
	printf("% d\n", 2147483647);
	printf("%- d\n", 2147483647);
	printf("%0 d\n", 2147483647);
	printf("%0- d\n", 2147483647);
	printf("%-d\n", 2147483647);
	printf("%0-d\n", 2147483647);
	printf("%0d\n", 2147483647);
	
















/*	
//	d [' '] [+] [minimum width] [precision]
	printf("% +40.30d\n", 2147483647);
//	d [-] [' '] [+] [minimum width] [precision]
	printf("%- +40.30d\n", 2147483647);
//	d [0] [-] [' '] [+] [minimum width] [precision]
	printf("%0- +40.30d\n", 2147483647);

	
//	d [minimum width]
	printf("%30d\n", -2147483647);
//	d [+]
	printf("%+d\n", +2147483647);				//for 'signed' pos, neg 
//	d [' ']
	printf("% d\n", 2147483647);				//only for 'signed' positives
//	d [+] [precision]
	printf("%+.30d\n", 2147483647);         
//	d [' '] [precision]
	printf("% .30d\n", 2147483647);         
//	d [+] [minimum width]
	printf("%+30d\n", 2147483647);         
//	d [' '] [minimum width]
	printf("% 10d\n", 2147483647);         
//	d [-] [minimum width]
	printf("%-20d\n", 2147483647);         
//	d [0] [minimum width]
	printf("%020d\n", 2147483647);         

//	d [+] [minimum width] [precision]
	printf("%+30.30d\n", 2147483647);         
//	d [' '] [minimum width] [precision]
	printf("% 10.30d\n", 2147483647);         
//	d [-] [minimum width] [precision]
	printf("%-20.30d\n", 2147483647);         
//	d [0] [minimum width] [precision]
	printf("%020.30d\n", 2147483647);         

	

//	d with [-] and [minimum width]
	printf("%-30d\n", -2147483647);
printf("------------------------------\n");

	printf("%0d\n", 777);
	printf("%-d\n", 777);
	printf("% d\n", 777);
	printf("%+d\n", 777);
	printf("%10d\n", 777);
	printf("%.5d\n", 777);

//	d with [0] and [minimum width]
	printf("%030d\n", -2147483647);
//	d with [0] and [precision]              	 // [0] is ignored
	printf("%0.20d\n", -2147483647);
//	d with [-] and [minimum width] and [precision]
	printf("%-40.30d\n", -2147483647);
//	d with [+] and [' '] and [minimum width]	//+ overrides a space
	printf("%+ 30d\n", -2147483647);                  
printf("-------------------------------------------------------------------\n");
//	d
	printf("%i\n", in);						// must be signed 'int' (-2,147,483,647, +2,147,483,647) 
//	d with [hh]
	printf("%hhi\n", ch); 					// must be declared as signed 'char' (−128, +127) 
//	d with [h]
	printf("%hi\n", sh);					// must be declared as signed 'short' (−32,768, +32,767)
//	d with [l]
	printf("%li\n", lo);					// must be declared as signed 'long' (-9,223,372,036,854,775,807, +9,223,372,036,854,775,807)
//	d with [ll]
	printf("%lli\n", lolo);					// must be declared as signed 'long long' (-9,223,372,036,854,775,807, +9,223,372,036,854,775,807)
printf("------------------------------\n");
//	d with [minimum width]
	printf("%30i\n", -2147483647);
//	d with [0] and [minimum width]
	printf("%030i\n", -2147483647);
//	d with [-] and [minimum width]
	printf("%-30i\n", -2147483647);
//	d with [precision]                      	 //precision puts [0s]
	printf("%.20i\n", -2147483647);
//	d with [0] and [precision]              	 // [0] is ignored
	printf("%0.20i\n", -2147483647);
//	d with [minimum width] and [precision]
	printf("%40.30i\n", -2147483647);
//	d with [-] and [minimum width] and [precision]
	printf("%-40.30i\n", -2147483647);
//	d with [' ']
	printf("% i\n", 2147483647);				//only for 'signed' positives
//	d with [+]
	printf("%+i\n", +2147483647);				//for 'signed' pos, neg 
//	d with [+] and [minimum width]
	printf("%+30i\n", -2147483647);         
//	d with [+] and [' '] and [minimum width]	//+ overrides a space
	printf("%+ 30i\n", -2147483647);                  
	
*/




	return (0);
}
