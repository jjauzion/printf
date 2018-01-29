#include "ft_printf.h"
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "");
	ft_printf("hello %ls \n", L"猫gf");
	return (0);
}
