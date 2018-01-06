/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 10:33:34 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/06 18:08:46 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main ()
{

/* TEST FLOAT */
/*	printf("\n\n-------------TEST DTOA-------------\n");
	double	testd;
	float	testf;
	char	*tests;

	testd = 0.999999;
	testd = 2.123456789;
	testf = 2.123456789;
	tests = ft_dtoa((double)testf, 8);
	printf("tests = %s ; testd = %.8f ; testf = %.8f\n", tests, testd, testf);
	tests = ft_dtoa((double)testd, 8);
	printf("tests = %s ; testd = %.8f\n", tests, testd);
	testd = 0.5555555555;
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

	printf("\n--> Test 06 : precision + width with int\n");
	printf("6.1 printf:\t|%2.0d| ; |%2.2d| ; |%2.3d| ; |%5.3d|\n", 2, 2, 2, 2);
	ft_printf("6.1 ft_printf:\t|%2.0d| ; |%2.2d| ; |%2.3d| ; |%5.3d|\n", 2, 2, 2, 2);
*/	printf("6.2 printf:\t|%-2.0d| ; |%-2.2d| ; |%-2.3d| ; |%-5.3d|\n", 2, 2, 2, 2);
	ft_printf("6.2 ft_printf:\t|%-2.0d| ; |%-2.2d| ; |%-2.3d| ; |%-5.3d|\n", 2, 2, 2, 2);

	printf("\n-------------END TEST PRINTF-------------\n");

	while (1)
	{}

	return (0);
}
