/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 10:33:34 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/11 18:08:38 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int		main ()
{

/* TEST FLOAT */
	printf("\n\n-------------TEST DTOA-------------\n");
	double	testd;
	float	testf;
	char	*tests;

	testd = 0.999999;
	testd = 2.123456789;
	testf = 2.123456789;
	tests = ft_dtoa((double)testf, 8);
	printf("tests = %s ; testd = %.8f ; testf = %.8f\n", tests, testd, testf);
	ft_strdel(&tests);
	tests = ft_dtoa((double)testd, 8);
	printf("tests = %s ; testd = %.8f\n", tests, testd);
	testd = 0.5555555555;
	ft_strdel(&tests);
	tests = ft_dtoa((double)testd, 8);
	printf("tests = %s ; testd = %.7f\n", tests, testd);
	testd = 2.999999000000000;
	printf("\n>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("testd = %.7f\n", testd);
	printf("testd = %.8f\n", testd);
	printf("testd = %.9f\n", testd);
	printf("testd = %.15f\n", testd);
	printf("testd = %.16f\n", testd);
	printf("testd = %.50f\n", testd);
	ft_strdel(&tests);
	tests = ft_dtoa((double)testd, 6);
	printf("tests = %s ; testd = %f\n", tests, testd);
	printf("\n-------------END TEST DTOA-------------\n\n");

	printf("-------------TEST PRINTF-------------\n");
	printf("\n--> Test 01 : nb arg > 10\n");
	printf("PRINTF:\narg 0 : %i ; arg 1 : %i ; arg 2 : %i ; arg 3 : %i ; arg 4 : %i ; arg 5 : %i ; arg 6 : %i ; arg 7 : %i ; arg 8 : %i ; arg 9 : %i ; arg 10 : %i\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	ft_printf("FT_PRINTF:\narg 0 : %i ; arg 1 : %i ; arg 2 : %i ; arg 3 : %i ; arg 4 : %i ; arg 5 : %i ; arg 6 : %i ; arg 7 : %i ; arg 8 : %i ; arg 9 : %i ; arg 10 : %i\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

	printf("\n--> Test 02 : simple padding\n");
	printf("2.0 printf:\t|%5d| ; |%05d| ; |%-5d|\n", 2, 2, 2);
	ft_printf("2.0 ft_printf:\t|%5d| ; |%05d| ; |%-5d|\n", 2, 2, 2);

	printf("2.1 printf:\t|%+0d| ; |%+2d| ; |%0+5d|\n", 2, 2, 2);
	ft_printf("2.1 ft_printf:\t|%+0d| ; |%+2d| ; |%0+5d|\n", 2, 2, 2);
	
	printf("2.2 printf:\t|%+5d| ; |%-+5d| ; |%+-+-+-+--5d|\n", 2, 2, 2);
	ft_printf("2.2 ft_printf:\t|%+5d| ; |%-+5d| ; |%+-+-+-+--5d|\n", 2, 2, 2);
	
	printf("2.3 printf:\t|% d| ; |%0 5d| ; |%- 5d|\n", 2, 2, 2);
	ft_printf("2.3 ft_printf:\t|% d| ; |%0 5d| ; |%- 5d|\n", 2, 2, 2);
	
	printf("2.4 printf:\t|%5d| ; |%05d| ; |%-5d|\n", -2, -2, -2);
	ft_printf("2.4 ft_printf:\t|%5d| ; |%05d| ; |%-5d|\n", -2, -2, -2);
	
	printf("2.5 printf:\t|%+5d| ; |%+05d| ; |%+-5d|\n", -2, -2, -2);
	ft_printf("2.5 ft_printf:\t|%+5d| ; |%+05d| ; |%+-5d|\n", -2, -2, -2);
	
	printf("2.6 printf:\t+d : |%+d| ;  +5d : |%+5d| ; +-5d : |%+-5d| ; +05d : |%+05d|\n", 0, 0, 0, 0);
	ft_printf("2.6 ft_printf:\t+d : |%+d| ;  +5d : |%+5d| ; +-5d : |%+-5d| ; +05d : |%+05d|\n", 0, 0, 0, 0);

//	printf("printf:\t\t|%5s| ; |%05s| ; |%-5s|\n", "-2", "-2", "-2");
//	printf("printf:\t\t|%0-5d|\n", 2);
//	ft_printf("ft_printf:\t|%0-5d|\n", 2);

	printf("\n--> Test 03 : simple %%i et %%u\n");
	printf("printf:\n\tchaine de test %i suite %i\n", 2, -2);
	ft_printf("ft_printf:\n\tchaine de test %i suite %i\n", 2, -2);
	printf("printf:\n\tchaine de test %u suite %u\n", 3, -3);
	ft_printf("ft_printf:\n\tchaine de test %u suite %u\n", 3, -3);

	printf("\n--> Test 04 : test %%f\n");
	printf("4.1 printf:\t|%f| ; |%f| ; |%f| ; |%f| ; |%f|\n", 2.123456789, 2., 0.01, 0., 0.0000001);
	ft_printf("4.1 ft_printf:\t|%f| ; |%f| ; |%f| ; |%f| ; |%f|\n", 2.123456789, 2., 0.01, 0., 0.0000001);
	printf("4.2 printf:\t|%f| ; |%f| ; |%f| ; |%f| ; |%f|\n", 2.123455789, 2.999999, 2.9999999, 9.9999999, 0.5555555);
	ft_printf("4.2 ft_printf:\t|%f| ; |%f| ; |%f| ; |%f| ; |%f|\n", 2.123455789, 2.999999, 2.9999999, 9.9999999, 0.5555555);
	printf("4.3 printf:\t|%.0f| ; |%.0f| ; |%.0f| ; |%.0f| ; |%.0f|\n", 0., 2.999999, 2.123456789, 9.9999999, 0.4444444);
	ft_printf("4.3 ft_printf:\t|%.0f| ; |%.0f| ; |%.0f| ; |%.0f| ; |%.0f|\n", 0., 2.999999, 2.123456789, 9.9999999, 0.4444444);
	printf("4.4 printf:\t|%.2f| ; |%.1f| ; |%.8f| ; |%.10f| ; |%.6f|\n", 0., 2.999999, 2.123456789, 9.9999999, 0.5555555);
	ft_printf("4.4 ft_printf:\t|%.2f| ; |%.1f| ; |%.8f| ; |%.10f| ; |%.6f|\n", 0., 2.999999, 2.123456789, 9.9999999, 0.5555555);
	printf("4.5 printf:\t|%.12f| ; |%f| ; |%f|\n", 36.9999999999, 36.9999999999, -1.25);
	ft_printf("4.5 ft_printf:\t|%.12f| ; |%f| ; |%f|\n", 36.9999999999, 36.9999999999, -1.25);

	printf("\n--> Test 05 : precision with int\n");
	printf("5.1 printf:\t|%2d| ; |%.2d|\n", 2, 2);
	ft_printf("5.1 ft_printf:\t|%2d| ; |%.2d|\n", 2, 2);
	printf("5.2 printf:\t|%.2d| ; |%.2d| ; |%.2d|\n", 2, 20, -2);
	ft_printf("5.2 ft_printf:\t|%.2d| ; |%.2d| ; |%.2d|\n", 2, 20, -2);
	printf("5.3 printf:\t|%.2u| ; |%.2u| ; |%.2u|\n", 2, 20, -2);
	ft_printf("5.3 ft_printf:\t|%.2u| ; |%.2u| ; |%.2u|\n", 2, 20, -2);
	printf("5.4 printf:\t|%.0u| ; |%.1d| ; |%.7d| ; |%.20u|\n", 21, 21, 452, -2);
	ft_printf("5.4 ft_printf:\t|%.0u| ; |%.1d| ; |%.7d| ; |%.20u|\n", 21, 21, 452, -2);
	printf("5.5 printf:\t|%04.d| ; |%04.5d| ; |%+04.d| ; |%00.0d|\n", 21, 21, 21, -2);
	ft_printf("5.5 ft_printf:\t|%04.d| ; |%04.5d| ; |%+04.d| ; |%00.0d|\n", 21, 21, 21, -2);

	printf("\n--> Test 06 : precision + width with int\n");
	printf("6.1 printf:\t|%2.0d| ; |%2.2d| ; |%2.3d| ; |%5.3d|\n", 2, 2, 2, 2);
	ft_printf("6.1 ft_printf:\t|%2.0d| ; |%2.2d| ; |%2.3d| ; |%5.3d|\n", 2, 2, 2, 2);
	printf("6.2 printf:\t|%-2.0d| ; |%-2.2d| ; |%-2.3d| ; |%-5.3d|\n", 2, 2, 2, 2);
	ft_printf("6.2 ft_printf:\t|%-2.0d| ; |%-2.2d| ; |%-2.3d| ; |%-5.3d|\n", 2, 2, 2, 2);

	printf("\n--> Test 07 : test string\n");
	printf("7.1 printf:\t|%s| ; |%-s|\n", "chaine de test", "-s");
	ft_printf("7.1 ft_printf:\t|%s| ; |%-s|\n", "chaine de test", "-s");
	printf("7.2 printf:\t|%-12s| ; |%-.5s|\n", "**:)**", "-s");
	ft_printf("7.2 ft_printf:\t|%-12s| ; |%-.5s|\n", "**:)**", "-s");
//	printf("7.3 printf:\t|%+-12s| ; |%0-10.5s|\n", "**:)**", "-s");
//	ft_printf("7.3 ft_printf:\t|%+-12s| ; |%0-10.5s|\n", "**:)**", "-s");
	printf("7.4 printf:\t|%-12s| ; |%1s|\n", "", "s#$-s");
	ft_printf("7.4 ft_printf:\t|%-12s| ; |%1s|\n", "", "s#$-s");
	printf("7.5 printf:\t|%-.12s| ; |%.3s|\n", "(-_-)'", "s#$-s");
	ft_printf("7.5 ft_printf:\t|%-.12s| ; |%.3s|\n", "(-_-)'", "s#$-s");
	printf("7.6 printf:\t|%-9.12s| ; |%9.3s| ; |%7.s| ; |%3s|\n", "(-_-)'", "s#$-s", "coucou", "coucou");
	ft_printf("7.6 ft_printf:\t|%-9.12s| ; |%9.3s| ; |%7.s| ; |%3s|\n", "(-_-)'", "s#$-s", "coucou", "coucou");

	printf("\n--> Test 08 : test hexa\n");
	printf("8.1 printf:\t|%x| ; |%X|\n", 12, 12);
	ft_printf("8.1 ft_printf:\t|%x| ; |%X|\n", 12, 12);
	printf("8.2 printf:\t|%x| ; |%X|\n", -12, -8);
	ft_printf("8.2 ft_printf:\t|%x| ; |%X|\n", -12, -8);
	printf("8.3 printf:\t|%x| ; |%X|\n", 0, -1);
	ft_printf("8.3 ft_printf:\t|%x| ; |%X|\n", 0, -1);
//	printf("8.4 printf:\t|%X| ; |%X| ; |%X|\n", 4294967295, -1, -2);
//	ft_printf("8.4 ft_printf:\t|%X| ; |%X| ; |%X|\n", 4294967295, -1, -2);
	printf("8.5 printf:\t|%.10x| ; |%.1x|\n", 45612, 45612);
	ft_printf("8.5 ft_printf:\t|%.10x| ; |%.1x|\n", 45612, 45612);
	printf("8.6 printf:\t|%15x| ; |%1x|\n", 45612, 45612);
	ft_printf("8.6 ft_printf:\t|%15x| ; |%1x|\n", 45612, 45612);
//	printf("8.7 printf:\t|%-15x| ; |%+1x|\n", 45612, 45612);
//	ft_printf("8.7 ft_printf:\t|%-15x| ; |%+1x|\n", 45612, 45612);
//	printf("8.8 printf:\t|%015x| ; |%0-15x|\n", 45612, 45612);
//	ft_printf("8.8 ft_printf:\t|%015x| ; |%0-15x|\n", 45612, 45612);
	printf("8.9 printf:\t|%#15x| ; |%#-15x|\n", 45612, 45612);
	ft_printf("8.9 ft_printf:\t|%#15x| ; |%#-15x|\n", 45612, 45612);
	printf("8.10 printf:\t|%2.6X| ; |%0.6X| ; |%0.X| ; |%010.X|\n", 128641, 128641, 128641, 128641);
	ft_printf("8.10 ft_printf:\t|%2.6X| ; |%0.6X| ; |%0.X| ; |%010.X|\n", 128641, 128641, 128641, 128641);

	printf("\n--> Test 09 : test octal\n");
	printf("9.1 printf:\t|%o| ; |%o| ; |%o|\n", 12, 2, 0);
	ft_printf("9.1 ft_printf:\t|%o| ; |%o| ; |%o|\n", 12, 2, 0);
	printf("9.2 printf:\t|%o| ; |%o| ; |%o|\n", -12, -7, -0);
	ft_printf("9.2 ft_printf:\t|%o| ; |%o| ; |%o|\n", -12, -7, -0);
	printf("9.3 printf:\t|%o| ; |%o|\n", 0, -1);
	ft_printf("9.3 ft_printf:\t|%o| ; |%o|\n", 0, -1);
//	printf("9.4 printf:\t|%o| ; |%o| ; |%o|\n", 4294967295, -1, -2);
//	ft_printf("9.4 ft_printf:\t|%o| ; |%o| ; |%o|\n", 4294967295, -1, -2);
	printf("9.5 printf:\t|%.10o| ; |%.1o|\n", 45612, 45612);
	ft_printf("9.5 ft_printf:\t|%.10o| ; |%.1o|\n", 45612, 45612);
	printf("9.6 printf:\t|%15o| ; |%1o|\n", 45612, 45612);
	ft_printf("9.6 ft_printf:\t|%15o| ; |%1o|\n", 45612, 45612);
//	printf("9.7 printf:\t|%-15o| ; |%+1o|\n", 45612, 45612);
//	ft_printf("9.7 ft_printf:\t|%-15o| ; |%+1o|\n", 45612, 45612);
//	printf("9.8 printf:\t|%015o| ; |%0-15o|\n", 45612, 45612);
//	ft_printf("9.8 ft_printf:\t|%015o| ; |%0-15o|\n", 45612, 45612);
	printf("9.9 printf:\t|%#15o| ; |%#-15o|\n", 45612, 45612);
	ft_printf("9.9 ft_printf:\t|%#15o| ; |%#-15o|\n", 45612, 45612);
	printf("9.10 printf:\t|%2.8o| ; |%0.8o| ; |%0.o| ; |%010.o|\n", 128641, 128641, 128641, 128641);
	ft_printf("9.10 ft_printf:\t|%2.8o| ; |%0.8o| ; |%0.o| ; |%010.o|\n", 128641, 128641, 128641, 128641);

	printf("\n--> Test 10 : test char\n");
	printf("10.1 printf:\t|%c| ; |%-c|\n", 'a', '0');
	ft_printf("10.1 ft_printf:\t|%c| ; |%-c|\n", 'a', '0');
//	printf("10.2 printf:\t|%4.5c| ; |%-5.3c|\n", 'a', 'b');
//	ft_printf("10.2 ft_printf:\t|%4.5c| ; |%-5.3c|\n", 'a', 'b');
//	printf("10.3 printf:\t|%04.5c| ; |%0c|\n", 'a', 'b');
//	ft_printf("10.3 ft_printf:\t|%04.5c| ; |%0c|\n", 'a', 'b');

	printf("\n--> Test 11 : test length modifier\n");
//	printf("11.1 printf:\t|%hf|\n", 2147483647.);

	printf("\n--> Test 12 : test UNICODE\n");
char* l = setlocale(LC_ALL, "en_US.UTF-8"); 
if (l == NULL) 
	    printf("Locale not set\n"); 
else
	    printf("Locale set to %s\n", l); 
	printf("13.1 printf:\t%C\n", 945);
//	ft_printf("13.1 ft_printf:\t%C\n", 945);
	printf("13.2 printf:\t|%S| ; |%25S| ; |%-25S|\n", L"我是一只猫。", L"我是一只猫。", L"我是一只猫。");
	printf("13.3 printf:\t|%ls| ; |%.2ls| ; |%-20ls|\n", L"我是一只猫。", L"我是一只猫。", L"我是一只猫。");
//	printf("13.4 printf:\t|%0ls| ; |%#25ls| ; |%0-20ls|\n", L"我是一只猫。", L"我是一只猫。", L"我是一只猫。");
	printf("13.5 printf:\t|%-7C| ; |%7lc|\n", 945, L'只');
	printf("13.6 printf:\t|%2$-7C| ; |%2$7lc|\n", 945, L'只');

	printf("\n--> Test 13 : test %%\n");
	printf("13.1 printf:\t%%5d %%d OK?\n");
	ft_printf("13.1 ft_printf:\t%%5d %%d OK?\n");
	printf("13.2 printf:\t%%5d %%d OK?\n");

	printf("\n--> Test xx : test bug\n");
	ft_printf("string with nothing special ; just plain text :)\n");
	ft_printf("%c%d%s", '|', 7, " Uniquement des specifier|\n");
	ft_printf("test ac plusieur arg enchaine <%c%d%s> alors?", '|', 7, " tut tut|");
//	ft_printf("%s%c%d%ls", "Uniquement des specifier.", ' ', 7, L"c'est pas si compliqué\n");

//	ft_printf("wrong specifier : %r \n"); //leaks avec ce test a corriger ?

	printf("\n-------------END TEST PRINTF-------------\n");

	while (1)
	{}

	return (0);
}
