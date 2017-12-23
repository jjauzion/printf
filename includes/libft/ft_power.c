#include "libft.h"

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
