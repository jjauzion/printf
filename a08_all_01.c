#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int		ret;
	int		retft;

	printf("ft_printf:\n");
	retft = ft_printf("<%----4c>", '\0');
	printf("|\nprintf:\n");
	ret = printf("<%----4c>", '\0');
	//ret = printf("hello ca%----4c %1c va %10c%-c ??", '\0', '\n',
	//													(char)564, 0);
	printf("|\n");
	printf("\n\nft_printf:\n");
	retft = ft_printf("|hello ca%----4c %1c va %10c%-c ??|\n", '\0', '\n',
														(char)564, 0);
	printf("printf:\n");
	ret = printf("|hello ca%----4c %1c va %10c%-c ??|\n", '\0', '\n',
														(char)564, 0);
	if (ret != retft)
		printf("ret = %d ; retft = %d\n", ret, retft);
	return (0);
}
