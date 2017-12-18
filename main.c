/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 10:33:34 by jjauzion          #+#    #+#             */
/*   Updated: 2017/12/18 18:06:49 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

int		ft_testprintf(const char *s, ...)
{
	va_list		ap;
	char		c;
	int			i;
	
	va_start(ap, s);
	while (*s)
	{
		if (*s != '%')
			ft_putchar(*s);
		else
		{
			s++;
			if (*s == 'c')
			{
				c = va_arg(ap, int);
				ft_putchar(c);
			}
			if (*s == 'i')
			{
				i = va_arg(ap, int);
				ft_putnbr(i);
			}
		}
		s++;
	}
	va_end(ap);
	return (1);
}

int		main ()
{

	printf("-------------TEST PRINTF-------------\n");
	printf("\n--> Test 01 : nb arg > 10\n");
	printf("arg 0 : %i ; arg 1 : %i ; arg 2 : %i ; arg 3 : %i ; arg 4 : %i ; arg 5 : %i ; arg 6 : %i ; arg 7 : %i ; arg 8 : %i ; arg 9 : %i ; arg 10 : %i\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

	printf("\n--> Test 02 : long attribute and repetion\n");
	printf("%+++++++++++------+2i\n", 2);

	printf("\n--> Test 03 : \n");
	printf("test 03 : |%2$-+*1$d| ; |%1$d|\n", 10, 2);
	printf("test 03bis : |%i| ;  |%*d|\n", 10, 2, 8);


	ft_printf("\n\tchaine de test %5$#+-432.lld suite%i", 'b');
	ft_printf("\n\ntest 03 : |%2$-+1d| ; |%1$d|\n", 10, 2);
	printf("\n-------------END TEST PRINTF-------------\n");
	ft_testprintf("coucou %i ca marche %c marche aussi\n", 1, '*');
/*
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
