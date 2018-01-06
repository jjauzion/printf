#include "libft.h"

double		ft_round_up(double nbr, int precision)
{
	int			n;
	int			i;
	double		real;
	double		ret;

	n = (int)nbr;
	real = nbr - (double)n;
	ret = (double)n;
	i = precision + 1;
	i = 0;
	while (++i <= precision + 1)
	{
		n = (int)(real * 10);
		real = real * 10 - (double)n;
		if (i <= precision)
			ret = ret + (double)n / (double)ft_power(10, i);
	}
	if (n >= 5)
		ret = ret + 1. / (double)ft_power(10, precision);
	return (ret);
}
