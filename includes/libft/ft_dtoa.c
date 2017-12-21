#include "libft.h"
#include <stdio.h>
long long int		ft_power(int nb, int power)
{
	long long int	res;

	res = nb;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (--power)
		res = res * 10;
	return (res);
}

double		ft_round_up(double nbr, int precision)
{
	int		n;
	int		i;
	double		real;

	n = (int)nbr;
	real = nbr - (double)n;
	i = precision;
	while (--i >= 0)
	{
		n = (int)(real * 10);
		real = real * 10 - (double)n;
	}
	if (n >= 5)
		nbr = nbr + 1. / (double)ft_power(10, precision);
	return (nbr);
}

char		*ft_dtoa(double nbr, int precision)
{
	int		n;
	double		real;
	char	*mynum;
	int		len;
	int		i;

printf("1 In number = %f\n", nbr);
	nbr = ft_round_up(nbr, precision);
printf("2 In number = %f\n", nbr);
	n = (int)nbr;
	mynum = ft_itoa(n);
	len = ft_strlen(mynum);
	mynum = (char *)ft_realloc((void **)&mynum, len, precision + 2);
	mynum[len] = '.';
	real = nbr - (double)n;
	i = -1;
	while (++i < precision)
	{
		n = (int)(real * 10);
		real = real * 10 - (double)n;
		mynum[len + i + 1] = n + '0';
	}
	mynum[len + i + 1] = '\0';
	return (mynum);
}
