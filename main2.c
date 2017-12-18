/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 09:35:07 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/18 22:22:18 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
int		main(int ac, char **av)
{
	char c;
	c = 'a';
/*	int len = 123456789;
	short x = (short) len;
	int n;
	double f = 100010.9999; */
	char *locale;
	locale = setlocale(LC_ALL, "");
	int a;
	a = 224;
	write(1,&(a),1);
	a = 175;
	write(1,&(a),1);
	a = 174;
	write(1,&(a),1);

	//write(1,&c, 5);	
//	printf("TOTAL : %d\n", printf("%0-10.5d",12345));
//	int result = printf("%C\n", 0x11ffff);
//	printf("%d\n", result);
//	n = 0;*/
	//len = printf("char : %C\n", 65280);
	//printf("len : %d\n");
/*	printf("TOTAL : %d\n", len);
	len = printf("char : %C nbr : %d \n",192,192 );
	printf("TOTAL : %d\n", len);
	printf("nbr: %d\n", 'α');*/
/*	len = printf("%S",L"漢字");
	printf("\n TOTAL : %d\n",len);
	len = printf("%C", '漢');
	printf("\n TOTAL : %d\n",len);
	len = printf("%ld", "字");
	rintf("\n TOTAL : %d\n",len);*/
//	printf("TOTAL : %d\n", printf("%lu\n", -123));
	//printf("%Ld\n",123);:
	//printf("%10%d",1);
	
	//printf("%d hahaha : %d huhuhu %n: %d, hehehe : %d\n", 1234, 4567, &len,  891, 23);
	//int i = printf("%d\n", atoi("2147483648"));
/*	long double x = 123456.123456;
	long double	original;
	long long	z = 0;
	long long	expo = 0;
	long double	w = 0;
	int		integer = 0;

 	original = x;
	integer = (long long) x;
	x = x - integer;
	//dprintf(1, "x avant : %f\n",(x = x * (float) 10));
	expo = 1;

	z = (long long) x;
	w = (long double) z;
	dprintf(1,"d avant : %Lf\n", w);
	while (w != x)
	{
		x = x * (long double) 10;
		dprintf(1,"x : %Lf", x);
		z = (long long) x;
		w = (long double) z;
		//dprintf(1,"w : %f\n", w);
		expo = expo * 10;
	}
	dprintf(1,"%Lf\n",w);
	dprintf(1,"entier : %d\n", (int) original);
	dprintf(1,"virgule : %lld\n", z % expo);
	
	//len = printf("%f\n int : %d\n float : %f\nres : %d\n", x, (z =(int) x), (z = (float) z), (15 == 14));
	//printf("%d", atoi("99999999999999999"));
//	dprintf(1, "retour printf = %d\n", len);
	printf(" 10.9999 : %a \n",f);
	printf(" 10.9999 : %A \n",f);

	f = 10123456789.1234567899999;
	printf(" 10123456789.1234567899999 : %e \n",f);
	printf(" 10123456789.1234567899999 : %a \n",f);
	len = sizeof(long long int);
	printf("pi=%a\n", 3.14);
	printf("123.4567 : %a \n",123.4567);
	printf("1.567 : %.2e\n", 1.567);
	printf("1.567 : %.2a\n", 1.567);
	printf("%%");*/
	//printf("%2$*1$d", 10, 5);

	/*printf("%.1d\n", 1234);
	  printf("%.6d\n", 1234);
	  printf("% 6.5d\n", 1234);
	  printf("% 6d\n", 1234);
	  printf("% 6.7d\n", 1234);
	  printf("%1.6d\n", 1234);
	  printf("%1.6d\n", 0);

	  printf("%8.4s\n", "abcdefghijklmnop");
	  printf("%8.4s\n", "12345");
	  printf("%8.4s\n", "1234");*/

}
