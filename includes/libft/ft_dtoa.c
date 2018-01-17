/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:25:59 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/17 11:58:39 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_dtoa(long double nbr, int precision)
{
	int			n;
	long double	real;
	char		*mynum;
	int			len;
	int			i;

//printf("\n>------------------\navant : %.50f ; precision = %d\n", nbr, precision);
	nbr = ft_round_up(nbr, precision);
//printf("apres : %.50f\n<---------------------\n", nbr);
	n = (int)nbr;
	mynum = ft_itoa(n);
	len = ft_strlen(mynum);
	mynum = (char *)ft_realloc((void **)&mynum, len + 1, precision + 2);
	mynum[len] = '.';
	real = ABS((nbr - (long double)n));
	i = -1;
	while (++i < precision)
	{
//printf("real = %f\n", real);
//printf("real*10 = %.50f\n", real * 10);
//printf("(int)(real*10) = %d\n", (int)(real * 10));
		n = (int)(real * 10);
//printf("n = %d\n", n);
		real = real * 10 - (long double)n;
//printf("real = %f\n", real);
		mynum[len + i + 1] = n + '0';
		mynum[len + i + 2] = '\0';
//printf("mynum = %s\n", mynum);
	}
	mynum[len + i + 1] = '\0';
	return (mynum);
}
