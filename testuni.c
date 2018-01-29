#include "ft_printf.h"
#include <locale.h>

int main(void)
{
	int	ret;
	int	retft;
	char	*str;

	str = ft_itoa(1000);
	printf("str = |%s|\n", str);
	printf("size = |%jd|\n", sizeof(uintmax_t));
//	setlocale(LC_ALL, "");
	retft = ft_printf("42%c42\n", (char)-69);
	ret = printf("42%c42\n", (char)-69);
	printf("\nret = %d ; retft = %d\n", ret, retft);
	return (0);
}
