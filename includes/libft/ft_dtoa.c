#include "libft.h"
#include <stdio.h>
char		*ft_dtoa(double nbr, int precision)
{
	int		n;
	double		real;
	char	*mynum;
	int		len;
	int		i;

printf("\n>------------------\navant : %.50f ; precision = %d\n", nbr, precision);
	nbr = ft_round_up(nbr, precision);
printf("apres : %.50f\n<---------------------\n", nbr);
	n = (int)nbr;
	mynum = ft_itoa(n);
	len = ft_strlen(mynum);
	mynum = (char *)ft_realloc((void **)&mynum, len, precision + 2);
	mynum[len] = '.';
	real = nbr - (double)n;
	i = -1;
	while (++i < precision)
	{
printf("real = %f\n", real);
printf("real*10 = %.50f\n", real * 10);
printf("(int)(real*10) = %d\n", (int)(real * 10));
		n = (int)(real * 10);
printf("n = %d\n", n);
		real = real * 10 - (double)n;
printf("real = %f\n", real);
		mynum[len + i + 1] = n + '0';
		mynum[len + i + 2] = '\0';
printf("mynum = %s\n", mynum);
	}
	mynum[len + i + 1] = '\0';
	return (mynum);
}
