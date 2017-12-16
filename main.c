/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 08:35:47 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/16 18:58:59 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/hprintf.h"
#include <stdio.h>
#include <locale.h>
int		main(void)
{
	char *locale;
	void	*coucou;
	int		len;

	coucou = &locale;
	locale = setlocale(LC_ALL,"");
//	ft_printf("CHIFFRE : %C\n", L'漢');
//	ft_printf("CHIFFRE : %jd\n", 65280);
//	ft_printf("CHIFFRE : %zd\n", 123456789123456);
//	printf("CHIFFRE : %zd\n", 123456789123456);
	len = ft_printf("null byte : %c\n", '\0');
	printf("len : %d\n", len);
	len = printf("null byte : %c\n",'\0');
//	ft_printf("FAU : %C\n", 4088443056);
//	len = printf("CHIFFRE : %lc\n", 4088443056);
	printf("len : %d\n", len);
		
	len = ft_printf("@moulitest: %5.x %5.0x\n", 0, 0);
	printf("len : %d\n", len);
	len = printf("@moulitest: %5.x %5.0x\n", 0, 0);
	printf("len : %d\n", len);
	
	
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
