#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int		main ()
{
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

	printf("\n\n--------------------------------\n");
	printf("5.1 printf:\t|%2hd| ; |%2hd|\n", 32767, 32768);
	ft_printf("5.1 ft_printf:\t|%2hd| ; |%2hd|\n", 32767, 32768);
	printf("5.1 printf:\t|%2lld| ; |%2d|\n", 9223372036854775807, 9223372036854775807);
	ft_printf("5.1 ft_printf:\t|%2lld| ; |%2d|\n", 9223372036854775807, 9223372036854775807);
}
