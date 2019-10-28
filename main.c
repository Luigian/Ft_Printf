/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 21:08:55 by lusanche          #+#    #+#             */
/*   Updated: 2019/10/27 21:29:20 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	void					*p = "pointer";
	char					ch = -128;							//hh
	short					sh = -32768;						//h
	int						in = -2147483647;					// no flag
	long					lon = -9223372036854775807;			//l
	long long				lonlon = -9223372036854775807;		//ll	
	unsigned char			uch = 255;							//hh
	unsigned short			ush = 65535;						//h
	unsigned int			uin = 4294967295;					// no flag
	unsigned long			ulon = 9223372036854775807;			//l
	unsigned long long		ulonlon = 9223372036854775807;		//ll

	setbuf(stdout, NULL);
/*	printf("[c] -------------------------------------------------------------\n");
	printf("%c\n", 42);
	printf("%-c\n", 42);
	printf("%20c\n", 42);
	printf("[s] -----------------------------------------------------------\n");
	printf("%s\n", "silicon valley");
	printf("%-s\n", "silicon valley");
	printf("%20s\n", "silicon valley");
	printf("%.3s\n", "silicon valley");
	printf("[p] -------------------------------------------------------------\n");
	printf("%p\n", p);
	printf("%-p\n", p);
	printf("%20p\n", p);
	printf("[d] -------------------------------------------------------------\n");
	printf("%d\n", in);
	printf("%hhd\n", ch);
	printf("%hd\n", sh);
	printf("%ld\n", lon);
	printf("%lld\n", lonlon);
	printf("%0d\n", 777);
	printf("%-d\n", 777);
	printf("% d\n", 777);
	printf("%+d\n", 777);
	printf("%10d\n", 777);
	printf("%.5d\n", 777);
	printf("[o] -----------------------------------------------------------\n");
	printf("%o\n", 112);		// dec 112 = oct 160
	printf("%o\n", 160);		// dec 160 = oct 240
	printf("%o\n", 'p');		// 'p' = dec 112 = oct 160
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
	printf("[u] -----------------------------------------------------------\n");
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
	printf("[x] -----------------------------------------------------------\n");
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
	printf("[X] -----------------------------------------------------------\n");
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
	printf("[f] -----------------------------------------------------------\n");
	printf("%f\n", 3.1416);
	printf("%lf\n", (double) 3.1416);
	printf("%Lf\n", (long double) 3.1416);
	printf("%#.f\n", 3.1);
	printf("%0f\n", 3.1416);
	printf("%-f\n", 3.1416);
	printf("% f\n", 3.1416);
	printf("%+f\n", 3.1416);
	printf("%20f\n", 3.1416);
	printf("%.20f\n", 3.1416);
	printf("[%%] -----------------------------------------------------------\n");
	printf("%%\n");
	printf("%%%d\n", 35);
	printf("%c%%%d\n", 'h', 35);
	printf("%#%\n");
	printf("%0%\n");
	printf("%-%\n");
	printf("% %\n");
	printf("%+%\n");
	printf("%20%\n");
	printf("%.0%\n");
	printf("[\\] -----------------------------------------------------------\n");
	printf("%\"\n", 128);
	printf("%20\"\n", 128);
	printf("%020\"\n", 128);
	printf("%-20\"\n", 128);
	printf("[other] -------------------------------------------------------\n");
	printf("%m\n", 128);
	printf("%20m\n", 128);
	printf("%020m\n", 128);
	printf("%-20m\n", 128);
	printf("[empty] --------------------------------------------------------\n");
	printf("%-20", 128);
	printf("%-20hh", 128);
	printf("%", 128);
*/	printf("[ft_printf] ----------------------------------------------------\n");
	//fflush(stdout);
//	ft_printf("%dhola\n", 20);
//	ft_printf("%d%c%s%ihola\n", 20);
//	ft_printf("%\nhola\n", 20);
//	ft_printf("%#0- +30.20lllhhhLxEl%Lhhhlll.20+30 -0#u%ocsphola\n", 20);
	printf("%.3d\n", 42);
	ft_printf("%.3d\n", 42);

	system("leaks a.out");
	return (0);
}
