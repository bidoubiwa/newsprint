/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 08:35:47 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/17 20:52:46 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/hprintf.h"
#include <stdio.h>
#include <locale.h>
int		main(void)
{
	char 	*locale;
	int		len;

	locale = setlocale(LC_ALL,"en_US.UTF-8");
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
	
	
	len = ft_printf("FAX : %S\n", L"Α α");
	printf("len : %d\n", len);
	len = printf("VRAI : %S\n", L"Α α");
	printf("len : %d\n", len);
	
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
	//ft_printf("coucou : %C\n", 28450);

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
