/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 08:35:47 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/21 00:21:48 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/hprintf.h"
#include <stdio.h>
#include <locale.h>
#include <limits.h>
int		main(void)
{
	char 	*locale;
	int		len;

//	ft_printf("CHIFFRE : %C\n", L'漢');
//	ft_printf("CHIFFRE : %jd\n", 65280);
//	ft_printf("CHIFFRE : %zd\n", 123456789123456);
//	printf("CHIFFRE : %zd\n", 123456789123456);
//	len = ft_printf("null byte : %c\n", '\0');
//	printf("len : %d\n", len);
//	len = printf("null byte : %c\n",'\0');
//	ft_printf("FAU : %C\n", 4088443056);
//	len = printf("CHIFFRE : %lc\n", 4088443056);
//	printf("len : %d\n", len)

	/*len = ft_printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S", 
		L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
		L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
	printf("len : %d\n", len);
	len = printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S", 
		L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
		L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
	printf("len : %d\n", len);
	*/

//	printf("%.100*s|\n",-100,"hahahaha");


	/*len = ft_printf("%.0p, %.p\n", 0, 0);
	printf("len : %d\n", len);
	len = ft_printf("%#.0x, %#.x\n", 0, 0);
	printf("len : %d\n", len);
	len = printf("%.0p, %.p\n", 0, 0);
	printf("len : %d\n", len);
	len = ft_printf("%#.0x, %#.x\n", 0, 0);
	printf("len : %d\n", len);
	
	len = ft_printf("%.4S", L"我是一只猫。");
	printf("len : %d\n", len);
	len = printf("%.4S", L"我是一只猫。");
	printf("len : %d\n", len);
	*/
	/* UNDEFINED BEHAVIOR */
/*	len = printf("{%05p}", (void*) &len);
	len = printf("{%05p}", 0);
	len = printf("{%030S}", L"我是一只猫。");	
	len = printf("{%05s}", "abc");

*/
//	ft_printf("%-30d %-30d %-30d\n%-30d %-30d %-30d\n", 123, 456, 789, 1235, 58962,123875);
/*	len = ft_printf("%#.3o\n", 1);
	printf("len : %d\n", len);
	len = ft_printf("%#3o\n", 1);
	printf("len : %d\n", len);
	len = printf("%#.3o\n", 1);
	printf("len : %d\n", len);
	len = printf("%#3o\n", 1);
	printf("len : %d\n", len);
*/

	
	int i = 1;
	int j = 1;
	wchar_t	s[4];

	locale = setlocale(LC_ALL,"");
//	len = ft_printf("%d\n", 100);
//	len = ft_printf("%C", 0x11ffff);
//	len = printf("%C", 0x11ffff);
//	len = ft_printf("%8C et coco %C titi %lc", 3250, 0x11ffff, 'a');
	len =	ft_printf("%C", 0x11ffff);
	printf("len : %d\n", len);
	len = printf("%C", 0x11ffff);
//	len = printf("%8C et coco %C titi %lc", 3250, 0x11ffff, 'a');
	printf("len : %d\n", len);
	/*
 * s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';
	//i = ft_printf("%C", 0x11ffff);
	//j = printf("%C", 0x11ffff);
	//i = ft_printf("%lc", 254);
	//j = printf("%lc", 254);
	
	i = ft_printf("%6C et coco %C titi %C tyty", 3250, 0xd800, 'u');
	j = ft_printf("%6C et coco %C titi %C tyty", 3250, 0xd800, 'u');
	//i = ft_printf("\n%8C et coco %C titi %lc\n", 3250, 0x11ffff, 'a');
	//j = printf("\n%8C et coco %C titi %lc\n", 3250, 0x11ffff, 'a');
	//i = ft_printf("%---10.5ls\n", s);
	//j = printf("%---10.5ls\n", s);
	//i = ft_printf("yo%2C%-12lc et %C titi %C tyty", 'u', 254, 256, 'a');
	//j = printf("ya%2C%-12lc et %C titi %C tyty", 'u', 254, 256, 'a');
	printf("\nretour ft_printf = %d\nretour printf = %d\n", i, j);
	len = ft_printf("%lc", 254);
	printf("len : %d\n", len);
	len = printf("%lc", 254);
	printf("len : %d\n", len);

	len = ft_printf("%   .0D\n", 0);
	printf("len : %d\n", len);
	len = printf("%   .0D\n", 0);
	printf("len : %d\n", len);
	len = ft_printf("toto%.0d et %+.i et  %   .0D !!!", 0, 0, 0);
	printf("len : %d\n", len);
	len = printf("toto%.0d et %+.i et  %   .0D !!!", 0, 0, 0);
	printf("len : %d\n", len);

	len = ft_printf("{%10.3S}\n", L"我是一只猫。");
	printf("len : %d\n", len);
	len = printf("{%10.3S}\n", L"我是一只猫。");
	printf("len : %d\n", len);
	len = printf("{%S}\n", L"我是一只猫。");
	printf("len : %d\n", len);
*/	
//	len = ft_printf("@OCTAL faux: %5.o %5.0o\n", 0, 0);
//	printf("len : %d\n", len);
//	len = printf("OCTAL @VRAI: %5.o %5.0o\n", 0, 0);
//	printf("len : %d\n", len);

//	len = ft_printf("@DECi faux: %5.d %5.0d\n", 0, 0);
//	printf("len : %d\n", len);
//	len = printf("@DECI VRAI: %5.d %5.0d\n", 0, 0);
//	printf("len : %d\n", len);

//	ft_printf("coucou 漢字: %100S|\n", L"漢漢字漢字漢字漢字漢字字");
//	printf("coucou 漢字: %100S|\n",  L"漢漢字漢字漢字漢字漢字字");
//	ft_printf("coucou : %C\n", 28450);

	//printf("coucou");
	//printf("coucou : %10S\n", L"漢字");
	//ft_printf("%+#hocoucou\n", 1234567891);
	//printf("%+#hocoucou\n", 1234567891);
	//printf("\nreal : %d\n", printf("% 3"));
	//ft_printf("%+0#10.5hhXcoucou\n", 12345678);
	//printf("%+0#10.5hhXcoucou\n", 12345678);
	//ft_printf("%+0#100.0Dcoucou\n", 123456789123456);
	//printf("%+0#100.0ldcoucou\n", 123456789123456);
	//printf("d : %dcoucou\n", 123456789123456);
	//printf("lld : %lldcoucou\n", 123456789123456);
}
