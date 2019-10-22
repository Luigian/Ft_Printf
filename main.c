/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 21:08:55 by lusanche          #+#    #+#             */
/*   Updated: 2019/10/21 20:17:31 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{

	void		*p = "pointer";
	char		ch = -128;							//hh
	short		sh = -32768;						//h
	int			in = -2147483647;					// no flag
	long		lon = -9223372036854775807;			//l
	long long	lonlon = -9223372036854775807;		//ll	
	unsigned char			uch = 255;						//hh
	unsigned short			ush = 65535;					//h
	unsigned int			uin = 4294967295;				// no flag
	unsigned long			ulon = 18446744073709551615;	//l
	unsigned long long		ulonlon = 18446744073709551615;	//ll


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

	printf("%c\n", 42);
	printf("%20c\n", 42);
	printf("%-20c\n", 42);
printf("-------------------------------------------------------------------\n");
	printf("%s\n", "silicon valley");
	printf("%.13s\n", "silicon valley");
	printf("%15.13s\n", "silicon valley");
	printf("%-15.13s\n", "silicon valley");
	printf("%15s\n", "silicon valley");
	printf("%-15s\n", "silicon valley");
printf("-------------------------------------------------------------------\n");
	printf("%p\n", p);
	printf("%20p\n", p);
	printf("%-20p\n", p);
printf("-------------------------------------------------------------------\n");
	printf("%d\n", in);						// must be signed 'int' (-2,147,483,647, +2,147,483,647) 
	printf("%hhd\n", ch); 					// must be declared as signed 'char' (−128, +127) 
	printf("%hd\n", sh);					// must be declared as signed 'short' (−32,768, +32,767)
	printf("%ld\n", lon);					// must be declared as signed 'long' (-9,223,372,036,854,775,807, +9,223,372,036,854,775,807)
	printf("%lld\n", lonlon);				// must be declared as signed 'long long' (-9,223,372,036,854,775,807, +9,223,372,036,854,775,807)
	printf("%0d\n", 777);
	printf("%-d\n", 777);
	printf("% d\n", 777);
	printf("%+d\n", 777);
	printf("%10d\n", 777);
	printf("%.5d\n", 777);
printf("-------------------------------------------------------------------\n");
	printf("%o\n", 112);					// dec 112 = oct 160
	printf("%o\n", 160);					// dec 160 = oct 240
	printf("%o\n", 'p');					// 'p' = dec 112 = oct 160
	printf("%hho\n", uch);
	printf("%ho\n", ush);
	printf("%o\n", uin);
	printf("%lo\n", ulon);
	printf("%llo\n", ulonlon);
	printf("%#o\n", 112);
	printf("%0o\n", 112);
	printf("%-o\n", 112);
	printf("%10o\n", 112);
	printf("%.5o\n", 112);
printf("-------------------------------------------------------------------\n");
	printf("%u\n", 2010);
	printf("%hhu\n", uch);
	printf("%hu\n", ush);
	printf("%u\n", uin);
	printf("%lu\n", ulon);
	printf("%llu\n", ulonlon);
	printf("%0u\n", uin);
	printf("%-u\n", uin);
	printf("%30u\n", uin);
	printf("%.30u\n", uin);
printf("-------------------------------------------------------------------\n");
	printf("%x\n", 2010);
	printf("%hhx\n", uch);
	printf("%hx\n", ush);
	printf("%x\n", uin);
	printf("%lx\n", ulon);
	printf("%llx\n", ulonlon);
	printf("%#x\n", 2010);
	printf("%0x\n", 2010);
	printf("%-x\n", 2010);
	printf("%10x\n", 2010);
	printf("%.5x\n", 2010);
printf("-------------------------------------------------------------------\n");
	printf("%X\n", 2010);
	printf("%hhX\n", uch);
	printf("%hX\n", ush);
	printf("%X\n", uin);
	printf("%lX\n", ulon);
	printf("%llX\n", ulonlon);
	printf("%#X\n", 2010);
	printf("%0X\n", 2010);
	printf("%-X\n", 2010);
	printf("%10X\n", 2010);
	printf("%.5X\n", 2010);
printf("-------------------------------------------------------------------\n");





	return (0);
}
