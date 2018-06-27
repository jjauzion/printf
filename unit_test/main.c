/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 10:33:34 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/27 10:21:22 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int		main ()
{
	int ret;
	int retft;

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
	printf("2.7 printf:\t|% d|\n", 0);
	ft_printf("2.7 ft_printf:\t|% d|\n", 0);
	printf("2.8 printf:\t|%ld|\n", 0xff11ff11ff88);
	ft_printf("2.8 printf:\t|%D|\n", 0xff11ff11ff88);

	printf("\n--> Test 03 : simple %%i et %%u\n");
	printf("printf:\n\tchaine de test %i suite %i\n", 2, -2);
	ft_printf("ft_printf:\n\tchaine de test %i suite %i\n", 2, -2);
	printf("printf:\n\tchaine de test %u suite %u\n", 3, -3);
	ft_printf("ft_printf:\n\tchaine de test %u suite %u\n", 3, -3);

/*	printf("\n--> Test 04 : test %%f\n");
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
*/
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
	printf("6.3 printf:\t|%03.0d| ; |%03.2d| ; |%0+4.4d|\n", 2, 2, 2);
	ft_printf("6.3 ft_printf:\t|%03.0d| ; |%03.2d| ; |%0+4.4d|\n", 2, 2, 2);

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
	ret = printf("7.7 |%s|\n", "\0a");
	retft = ft_printf("7.7 |%s|\n", "\0a");
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);

	printf("\n--> Test 08 : test hexa\n");
	printf("8.1 printf:\t|%x| ; |%X|\n", 12, 12);
	ft_printf("8.1 ft_printf:\t|%x| ; |%X|\n", 12, 12);
	printf("8.2 printf:\t|%x| ; |%X|\n", -12, -8);
	ft_printf("8.2 ft_printf:\t|%x| ; |%X|\n", -12, -8);
	printf("8.5 printf:\t|%.10x| ; |%.1x|\n", 45612, 45612);
	ft_printf("8.5 ft_printf:\t|%.10x| ; |%.1x|\n", 45612, 45612);
	printf("8.6 printf:\t|%15x| ; |%1x|\n", 45612, 45612);
	ft_printf("8.6 ft_printf:\t|%15x| ; |%1x|\n", 45612, 45612);
	printf("8.9 printf:\t|%#15x| ; |%#-15x|\n", 45612, 45612);
	ft_printf("8.9 ft_printf:\t|%#15x| ; |%#-15x|\n", 45612, 45612);
	printf("8.10 printf:\t|%2.6X| ; |%0.6X| ; |%0.X| ; |%010.X|\n", 128641, 128641, 128641, 128641);
	ft_printf("8.10 ft_printf:\t|%2.6X| ; |%0.6X| ; |%0.X| ; |%010.X|\n", 128641, 128641, 128641, 128641);
	printf("8.11 printf:\t|%#20.8X| ; |%-#20.8X| ; |%#-20.2X| ; |%0#20.10X|\n", 128641, 128641, 128641, 128641);
	ft_printf("8.11 ft_printf:\t|%#20.8X| ; |%-#20.8X| ; |%#-20.2X| ; |%0#20.10X|\n", 128641, 128641, 128641, 128641);
	printf("8.12 printf:\t|%010X| ; |%0#10X|; |%010.2X| ; |%010.1X| ; |%010.5X|\n", 17, 17, 17, 17, 17);
	ft_printf("8.12 ft_printf:\t|%010X| ; |%0#10X|; |%010.2X| ; |%010.1X| ; |%010.5X|\n", 17, 17, 17, 17, 17);
	printf("8.15 printf:\t|%#3X| ; |%#X| ; |%#-3X| ; |%#03X|\n", 20, 0, 0, 0);
	ft_printf("8.15 ft_printf:\t|%#3X| ; |%#X| ; |%#-3X| ; |%#03X|\n", 20, 0, 0, 0);
	printf("8.17 printf:\t|%#.0o| ; |%#.0x| ; |%#05.0x| ; |%#+05x|\n", 0, 0, 0, 0);
	ft_printf("8.17 ft_printf:\t|%#.0o| ; |%#.0x| ; |%#05.0x| ; |%#+05x|\n", 0, 0, 0, 0);

	printf("\n--> Test 09 : test octal\n");
	printf("9.1 printf:\t|%o| ; |%o| ; |%o|\n", 12, 2, 0);
	ft_printf("9.1 ft_printf:\t|%o| ; |%o| ; |%o|\n", 12, 2, 0);
	printf("9.2 printf:\t|%o| ; |%o| ; |%o|\n", -12, -7, -0);
	ft_printf("9.2 ft_printf:\t|%o| ; |%o| ; |%o|\n", -12, -7, -0);
	printf("9.3 printf:\t|%o| ; |%o|\n", 0, -1);
	ft_printf("9.3 ft_printf:\t|%o| ; |%o|\n", 0, -1);
	printf("9.5 printf:\t|%.10o| ; |%.1o|\n", 45612, 45612);
	ft_printf("9.5 ft_printf:\t|%.10o| ; |%.1o|\n", 45612, 45612);
	printf("9.6 printf:\t|%15o| ; |%1o|\n", 45612, 45612);
	ft_printf("9.6 ft_printf:\t|%15o| ; |%1o|\n", 45612, 45612);
	printf("9.9 printf:\t|%#15o| ; |%#-15o|\n", 45612, 45612);
	ft_printf("9.9 ft_printf:\t|%#15o| ; |%#-15o|\n", 45612, 45612);
	printf("9.10 printf:\t|%2.8o| ; |%0.8o| ; |%0.o| ; |%010.o|\n", 128641, 128641, 128641, 128641);
	ft_printf("9.10 ft_printf:\t|%2.8o| ; |%0.8o| ; |%0.o| ; |%010.o|\n", 128641, 128641, 128641, 128641);
	printf("9.11 printf:\t|%#20.8o| ; |%-#20.8o| ; |%#-20.2o| ; |%0#20.10o|\n", 128641, 128641, 128641, 128641);
	ft_printf("9.11 ft_printf:\t|%#20.8o| ; |%-#20.8o| ; |%#-20.2o| ; |%0#20.10o|\n", 128641, 128641, 128641, 128641);
	printf("9.12 printf:\t|%010o| ; |%0#10o|; |%010.2o| ; |%010.1o| ; |%010.5o|\n", 17, 17, 17, 17, 17);
	ft_printf("9.12 ft_printf:\t|%010o| ; |%0#10o|; |%010.2o| ; |%010.1o| ; |%010.5o|\n", 17, 17, 17, 17, 17);
	printf("9.15 printf:\t|%#3o| ; |%#o| ; |%#-3o| ; |%#03o|\n", 20, 0, 0, 0);
	ft_printf("9.15 ft_printf:\t|%#3o| ; |%#o| ; |%#-3o| ; |%#03o|\n", 20, 0, 0, 0);
	printf("9.16 printf:\t|%.0o| ; |%.o| ; |%.4o|\n", 0, 0, 0);
	ft_printf("9.16 ft_printf:\t|%.0o| ; |%.o| ; |%.4o|\n", 0, 0, 0);

	printf("\n--> Test 10 : test char\n");
	printf("10.1 printf:\t|%c| ; |%-c|\n", 'a', '0');
	ft_printf("10.1 ft_printf:\t|%c| ; |%-c|\n", 'a', '0');
	printf("10.4 printf:\t|%c| ; |%-c|\n", '\0', '\0');
	ft_printf("10.4 ft_printf:\t|%c| ; |%-c|\n", '\0', '\0');
	ret = printf("10.5 |%5c|\n", '\0');
	retft = ft_printf("10.5 |%5c|\n", '\0');
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("10.6 |%-5c| ; |%-5c|\n", '\0', 'a');
	retft = ft_printf("10.6 |%-5c| ; |%-5c|\n", '\0', 'a');
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("10.7 |%.5c|\n", '\0');
	retft = ft_printf("10.7 |%.5c|\n", '\0');
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);

	printf("\n--> Test 11 : test length modifier\n");
	ret = printf("11.1 %-10s: |%hU|\n", "printf ", 4294967296);
	retft = ft_printf("11.1 %-10s: |%hU|\n", "ft_printf ", 4294967296);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);

	printf("\n--> Test 12 : test UNICODE\n");

char* l = setlocale(LC_ALL, ""); 
if (l == NULL) 
	    printf("Locale not set\n"); 
else
	    printf("Locale set to %s\n", l); 
	ret = printf("12.1 :\t%C\n", 945);
	retft = ft_printf("12.1 :\t%C\n", 945);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("12.2 :\t|%S| ; |%25S| ; |%-25S|\n", L"我是一只猫。", L"我是一只猫。", L"我是一只猫。");
	retft = ft_printf("12.2 :\t|%S| ; |%25S| ; |%-25S|\n", L"我是一只猫。", L"我是一只猫。", L"我是一只猫。");
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("12.5 :\t|%-5C| ; |%5C|; |%5C|\n", 945, L'只', L'α');
	retft = ft_printf("12.5 :\t|%-5C| ; |%5C|; |%5C|\n", 945, L'只', L'α');
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("12.12 :\t|%-5C|\n", L'\0');
	retft = ft_printf("12.12 :\t|%-5C|\n", L'\0');
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("12.13 :%-c mais c'est nul !!\n", '\0');
	retft = ft_printf("12.13 :%-c mais c'est nul !!\n", '\0');
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("12.14 :hello ca%-4c %1c va %10c%-c ??\n", '\0', 'v',(char)564, 0);
	retft = ft_printf("12.14 :hello ca%-4c %1c va %10c%-c ??\n", '\0', 'v',(char)564, 0);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
//	ret = printf("12.6 :\t|%2$-7C| ; |%1$7C|\n", 945, L'只');
//	retft = ft_printf("12.6 :\t|%2$-7C| ; |%1$7C|\n", 945, L'只');
//	if (ret != retft)
//		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);

	printf("\n--> Test 13 : test %%\n");
	ret = printf("13.1 :\t%%5d %%d OK?\n");
	retft = ft_printf("13.1 :\t%%5d %%d OK?\n");
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);

	printf("\n--> Test 14 : test valeur retour\n");
	ret = printf("14.1 :\t|%o| ; |%o| ; |%o|\n", 12, 2, 0);
	retft = ft_printf("14.1 :\t|%o| ; |%o| ; |%o|\n", 12, 2, 0);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("14.2 :\t|%o| ; |%o| ; |%o|\n", -12, -7, -0);
	retft = ft_printf("14.2 :\t|%o| ; |%o| ; |%o|\n", -12, -7, -0);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("14.3 :\t|%o| ; |%o|\n", 0, -1);
	retft = ft_printf("14.3 :\t|%o| ; |%o|\n", 0, -1);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("14.5 :\t|%.10o| ; |%.1o|\n", 45612, 45612);
	retft = ft_printf("14.5 :\t|%.10o| ; |%.1o|\n", 45612, 45612);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("14.6 :\t|%15o| ; |%1o|\n", 45612, 45612);
	retft = ft_printf("14.6 :\t|%15o| ; |%1o|\n", 45612, 45612);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("14.9 :\t|%#15o| ; |%#-15o|\n", 45612, 45612);
	retft = ft_printf("14.9 :\t|%#15o| ; |%#-15o|\n", 45612, 45612);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("14.10 :\t|%2.8o| ; |%0.8o| ; |%0.o| ; |%010.o|\n", 128641, 128641, 128641, 128641);
	retft = ft_printf("14.10 :\t|%2.8o| ; |%0.8o| ; |%0.o| ; |%010.o|\n", 128641, 128641, 128641, 128641);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("14.11 :\t|%#20.8o| ; |%-#20.8o| ; |%#-20.2o| ; |%0#20.10o|\n", 128641, 128641, 128641, 128641);
	retft = ft_printf("14.11 :\t|%#20.8o| ; |%-#20.8o| ; |%#-20.2o| ; |%0#20.10o|\n", 128641, 128641, 128641, 128641);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("14.12 :\t|%010o| ; |%0#10o|; |%010.2o| ; |%010.1o| ; |%010.5o|\n", 17, 17, 17, 17, 17);
	retft = ft_printf("14.12 :\t|%010o| ; |%0#10o|; |%010.2o| ; |%010.1o| ; |%010.5o|\n", 17, 17, 17, 17, 17);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("14.15 :\t|%#3o| ; |%#o| ; |%#-3o| ; |%#03o|\n", 20, 0, 0, 0);
	retft = ft_printf("14.15 :\t|%#3o| ; |%#o| ; |%#-3o| ; |%#03o|\n", 20, 0, 0, 0);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);

	printf("\n--> Test 15 : undefined behaviour\n");
	printf("15.8.3 :\t|%x| ; |%X|\n", 0, -1);
	ft_printf("15.8.3 :\t|%x| ; |%X|\n", 0, -1);
	printf("15.8.4 :\t|%X| ; |%X| ; |%X|\n", 4294967295, -1, -2);
	ft_printf("15.8.4 :\t|%X| ; |%X| ; |%X|\n", 4294967295, -1, -2);
	printf("15.8.7 :\t|%-15x| ; |%+1x|\n", 45612, 45612);
	ft_printf("15.8.7 :\t|%-15x| ; |%+1x|\n", 45612, 45612);
	printf("15.8.8 :\t|%015x| ; |%0-15x|\n", 45612, 45612);
	ft_printf("15.8.8 :\t|%015x| ; |%0-15x|\n", 45612, 45612);
	printf("15.8.13 :\t|%04X| ; |%04.1X| ; |%0#4X| ; |%X|\n", 10, 10, 10, 4294967295);
	ft_printf("15.8.13 :\t|%04X| ; |%04.1X| ; |%0#4X| ; |%X|\n", 10, 10, 10, 4294967295);
	printf("15.8.14 :\t|%#+05X| ; |%#+05.2X| ; |%#+05.7X|\n", 10, 10, 10);
	ft_printf("15.8.14 :\t|%#+05X| ; |%#+05.2X| ; |%#+05.7X|\n", 10, 10, 10);
	printf("15.9.4 :\t|%o| ; |%o| ; |%o|\n", 4294967295, -1, -2);
	ft_printf("15.9.4 :\t|%o| ; |%o| ; |%o|\n", 4294967295, -1, -2);
	printf("15.9.7 :\t|%-15o| ; |%+1o|\n", 45612, 45612);
	ft_printf("15.9.7 :\t|%-15o| ; |%+1o|\n", 45612, 45612);
	printf("15.9.8 :\t|%015o| ; |%0-15o|\n", 45612, 45612);
	ft_printf("15.9.8 :\t|%015o| ; |%0-15o|\n", 45612, 45612);
	printf("15.9.13 :\t|%04o| ; |%0#4o| ; |%o|\n", 10, 10, 4294967295);
	ft_printf("15.9.13 :\t|%04o| ; |%0#4o| ; |%o|\n", 10, 10, 4294967295);
	printf("15.10.2 :\t|%4.5c| ; |%-5.3c|\n", 'a', 'b');
	ft_printf("15.10.2 :\t|%4.5c| ; |%-5.3c|\n", 'a', 'b');
	printf("15.10.3 :\t|%04.5c| ; |%0c|\n", 'a', 'b');
	ft_printf("15.10.3 :\t|%04.5c| ; |%0c|\n", 'a', 'b');
	ret = printf("15.12.3 :\t|%S| ; |%.2S| ; |%-20S|\n", L"我是一只猫。", L"我是一只猫。", L"我是一只猫。");
	retft = ft_printf("15.12.3 :\t|%S| ; |%.2S| ; |%-20S|\n", L"我是一只猫。", L"我是一只猫。", L"我是一只猫。");
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("15.12.4 :\t|%0S| ; |%#025S| ; |%0-20S|\n", L"我是一只猫。", L"我是一只猫。", L"我是一只猫。");
	retft = ft_printf("15.12.4 :\t|%0S| ; |%#025S| ; |%0-20S|\n", L"我是一只猫。", L"我是一只猫。", L"我是一只猫。");
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("15.12.7 :\t|%.1S| ; |%.5S| ; |%.6S| ; |%.20S|\n", L"我是一只猫。", L"我是一只猫。", L"我是一只猫。", L"我是一只猫。");
	retft = ft_printf("15.12.7 :\t|%.1S| ; |%.5S| ; |%.6S| ; |%.20S|\n", L"我是一只猫。", L"我是一只猫。", L"我是一只猫。", L"我是一只猫。");
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("15.12.8 :\t|%.8S| ; |%.5S| ; |%.6S|\n", L"u我2αi", L"u我2αi", L"u我2αi");
	retft = ft_printf("15.12.8 :\t|%.8S| ; |%.5S| ; |%.6S|\n", L"u我2αi", L"u我2αi", L"u我2αi");
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("15.12.9 :\t|%5.2S| ; |%-5.2S| ; |%05.2S|\n", L"u我2αi", L"u我2αi", L"u我2αi");
	retft = ft_printf("15.12.9 :\t|%5.2S| ; |%-5.2S| ; |%05.2S|\n", L"u我2αi", L"u我2αi", L"u我2αi");
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("15.12.10 :\t|%5.3S| ; |%-5.3S| ; |%05.3S|\n", L"u我2αi", L"u我2αi", L"u我2αi");
	retft = ft_printf("15.12.10 :\t|%5.3S| ; |%-5.3S| ; |%05.3S|\n", L"u我2αi", L"u我2αi", L"u我2αi");
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("15.12.11 :\t|%.10S| ; |%5.10S| ; |%015.10S|\n", L"u我2αi", L"u我2αi", L"u我2αi");
	retft = ft_printf("15.12.11 :\t|%.10S| ; |%5.10S| ; |%015.10S|\n", L"u我2αi", L"u我2αi", L"u我2αi");
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("15.14.4 :\t|%o| ; |%o| ; |%o|\n", 4294967295, -1, -2);
	retft = ft_printf("15.14.4 :\t|%o| ; |%o| ; |%o|\n", 4294967295, -1, -2);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("15.14.7 :\t|%-15o| ; |%+1o|\n", 45612, 45612);
	retft = ft_printf("15.14.7 :\t|%-15o| ; |%+1o|\n", 45612, 45612);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("15.14.8 :\t|%015o| ; |%0-15o|\n", 45612, 45612);
	retft = ft_printf("15.14.8 :\t|%015o| ; |%0-15o|\n", 45612, 45612);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("15.14.13 :\t|%04o| ; |%0#4o| ; |%o|\n", 10, 10, 4294967295);
	retft = ft_printf("15.14.13 :\t|%04o| ; |%0#4o| ; |%o|\n", 10, 10, 4294967295);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);

	printf("\n--> Test 16 : test %%p\n");
	ret = printf("16.1 :\t|%p| ; |%50p| ; |%-50.20p|\n", &ret, &ret, &ret);
	retft = ft_printf("16.1 :\t|%p| ; |%50p| ; |%-50.20p|\n", &ret, &ret, &ret);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);

	printf("\n--> Test xx : test all\n");
	ret = printf("xx.1 string with nothing special ; just plain text :)\n");
	retft = ft_printf("xx.1 string with nothing special ; just plain text :)\n");
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("xx.2 %c%d%s", '|', 7, " Uniquement des specifier|\n");
	retft = ft_printf("xx.2 %c%d%s", '|', 7, " Uniquement des specifier|\n");
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("xx.3 test ac plusieur arg enchaine <%c%d%s> alors?\n", '|', 7, " tut tut|");
	retft = ft_printf("xx.3 test ac plusieur arg enchaine <%c%d%s> alors?\n", '|', 7, " tut tut|");
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("xx.4 %s%2c%d%S", "Uniquement des specifier.", ' ', 7, L" 猫 c'est pas si compliqué\n");
	retft = ft_printf("xx.4 %s%2c%d%S", "Uniquement des specifier.", ' ', 7, L" 猫 c'est pas si compliqué\n");
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("xx.5 just a little trick %%r \n");
	retft = ft_printf("xx.5 just a little trick %%r \n");
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
//	printf("4567 |%-10]5d| plip\n", 12);
//	printf("4567 |%10]5d| plip\n", 12);	

	printf("\n--> Test yy : seg fault\n");
	printf("\n>>Test 01:\n");
	ft_printf("wrong specifier : %r \n");
	printf("\n>>Test 02:\n");
	ret = printf("");
	retft = ft_printf("");
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	printf("\n>>Test 03:\n");
	ret = printf("danger ! %lhlhl++--d danger over.\n", 10);
	retft = ft_printf("danger ! %lhlhl++--d danger over.\n", 10);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	printf("\n>>Test 04:\n");
	ret = printf("%l+010d\n", 10);
	retft = ft_printf("%l+010d\n", 10);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	printf("\n>>Test 05:\n");
	ret = printf("%d\n", 10, 25);
	retft = ft_printf("%d\n", 10, 25);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	printf("\n>>Test 06:\n");
	ret = printf("%d\n", "str");
	retft = ft_printf("%d\n", "str");
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
/*	printf("\n>>Test 07:\n");
	ret = printf("%s\n", 10);
	retft = ft_printf("%s\n", 10);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur de retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);*/

	printf("\n-------------END TEST PRINTF-------------\n");

	return (0);
}
