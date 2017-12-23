#include "libft.h"

char		*ft_dtoa(double nbr, int precision)
{
	int		n;
	double		real;
	char	*mynum;
	int		len;
	int		i;

	nbr = ft_round_up(nbr, precision);
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
