#include "libft.h"

double		ft_round_up(double nbr, int precision)
{
	int		n;
	int		i;
	double		real;

	n = (int)nbr;
	real = nbr - (double)n;
	i = precision + 1;
	while (--i >= 0)
	{
		n = (int)(real * 10);
		real = real * 10 - (double)n;
	}
	if (n >= 5)
		nbr = nbr + 1. / (double)ft_power(10, precision);
	return (nbr);
}
