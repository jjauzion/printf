/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 10:33:34 by jjauzion          #+#    #+#             */
/*   Updated: 2017/12/20 20:35:36 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main ()
{

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
/*
	printf("\n--> Test 05 : test precision\n");
	printf("printf:\n.5i : |%.5i| ;  i : |%i|\n", 2, 2);
	printf("printf:\n2.5i : |%2.5i| ;  2i : |%2i|\n", 2, 2);
	printf("printf:\n0.5i : |%0.5i| ;  0i : |%0i|\n", 2, 2);
	printf("printf:\n10.5i : |%10.5i| ;  5.5i : |%5.5i|\n", 2, 2);
	printf("printf:\n+10.5i : |%+10.5i| ;  +-10.5i : |%+-10.5i|\n", 2, 2);
	printf("printf:\n+10.5i : |%+10.5i| ;  +-10.5i : |%+-10.5i|\n", -2, -2);
	printf("printf:\nf : |%f| ;  .5f : |%.5f|\n", 2.123456789, 2.123456789);
	printf("printf:\nf : |%f| ;  .0f : |%.0f|\n", 2., 2.123456789);
	printf("printf:\n#f : |%#f| ;  #.0f : |%#.0f|\n", 2., 2.123456789);
	printf("printf:\nf : |%f| ;  .5f : |%.5f|\n", 2.1, 2.1);
	printf("printf:\n10f : |%10f| ;  10.3f : |%10.3f|\n", 2.1, 2.1);
	printf("printf:\n010f : |%010f| ;  010.3f : |%010.3f|\n", 2.1, 2.1);
	printf("printf:\n1f : |%1f| ;  02.5f : |%02.5f|\n", 2.1, 2.1);
	printf("printf:\ng : |%g| ;  .5g : |%.5g|\n", 2.123456789, 2.123456789);
*/
	printf("\n-------------END TEST PRINTF-------------\n");

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
	testd = 2.999999;
	printf("\n>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("testd = %.7f\n", testd);
	printf("testd = %.8f\n", testd);
	printf("testd = %.9f\n", testd);
	printf("testd = %.15f\n", testd);
	printf("testd = %.50f\n", testd);
	tests = ft_dtoa((double)testd, 6);
	printf("tests = %s ; testd = %f\n", tests, testd);

/*	
	printf("\n--> Test 02 : long attribute and repetion\n");
	printf("%+++++++++++------+2i\n", 2);

	printf("\n--> Test 03 : \n");
	printf("test 03 : |%2$-+*1$d| ; |%1$d|\n", 10, 2);
	printf("test 03bis : |%i| ;  |%*d|\n", 10, 2, 8);

	printf("\n--> Test 04 : diouxX\n");
	printf("10 into -> o : %1$o ; u : %1$u ; x : %1$x ; X : %1$X ; i : %1$i ; d : %1$d\n", 10);
	printf("-10 into -> o : %1$o ; u : %1$u ; x : %1$x ; X : %1$X ; i : %1$i ; d : %1$d\n", -10);
//	printf("4567 |%-10]5d| plip\n", 12);
//	printf("4567 |%10]5d| plip\n", 12);
    printf("|%10.5d|\n", -12);
    printf("|%10d|\n", -12);
    printf("|%010d|\n", -12); 
    printf("|%-10.5d|\n", -12);
//  printf("|%-010.5d|\n", -12);
    printf("%%.5d -12 -> |%.5d|\n", -12);
    printf("%%.5d +12 -> |%.5d|\n", 12);
    printf("%%.0d +12 -> |%.0d|\n", 12);
    printf("%%.0d + 0 -> |%.0d|\n", 0);
    printf("%%d 5 -> |%d|\n", 512);
    printf("%%hd 5 -> |%hd|\n", 512);
    printf("%%ld 5 -> |%ld|\n", 512);
    printf("%%+u 14 -> |%+u|\n", 14);
*//*
	char			*s;
	double			nbr;
	int				nbr2;
	int				width;
	long long int	lli;
	long int		li;

	s = ft_strdup("\"my test""string""...");
	printf("test a : %c\n", s[0]);
	printf("test b : %c\n", s[1]);
	printf("test 0 : %15s[]\ntest 1 : %-15s[]\n", s, s);
	printf("test 01 : %3s[]\ntest 02 : %s[]\n", s, s);
	printf("test 2 : %.5f\ntest 3 : %.5F\n", 20.01, 20.01);
	printf("test 4 : %.1i\ntest 5 : %S\n", 20, L"\100");
	printf("test 6 : %f\ntest 7 : %f\n", 1./0, 0./0.);
	nbr = (1. / 0.) - (1. / 0.);
	printf("test 8 : %f\ntest 9 : %f\n", nbr, 99999999999999999999999999999999.9);
	printf("test 10 : %e\ntest 11 : %.2e\n", 20., 20.);
	nbr = 20.153468412134651354651364165431315120001;
	printf("test 10 : %f\ntest 11 : %a\n", nbr, nbr);
	printf("test 12 : ""test guillemet"" \" hashtag 2%% ' \100 \\ \' \n ");
	nbr2 = 7;
	width = 3;
	printf("test 13 : |%*d|\n", width, nbr2);
	printf("test 14 : |%2$*1$d|\n", width, nbr2);
	lli = -9223372036854775807;
	printf("test 14 : |%lld|\n", lli);
	li = -9223372036854775807;
	printf("test 14 : |%ld|\n", li);
	printf("test 15 : %aq.2f\n", 1234567.89);
	printf("test 16 : \78\n");
	printf("test 17 : \77\n");
	printf("test 18 : %'d ; %'f\n", 5, 153214.1256);
	printf("test 19 : |%+d| ; |% d|\n", 5, 5);
	printf("test 20	: %.1234f\n", 5.);
	printf("test 21 : |%2$-+*1$d| ; |%1$d|\n", 10, 2);
*/
	return (0);
}
