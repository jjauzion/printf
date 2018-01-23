/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:27:36 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/17 11:58:41 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double		ft_round_up(long double nbr, int precision)
{
	int			n;
	int			i;
	long double	real;
	long double	ret;

	n = (int)nbr;
	real = nbr - (long double)n;
	ret = (long double)n;
	i = precision + 1;
	i = 0;
	while (++i <= precision + 1)
	{
		n = (int)(real * 10);
		real = real * 10 - (long double)n;
		if (i <= precision)
			ret = ret + (long double)n / (long double)ft_power(10, i);
	}
	if (n >= 5)
		ret = ret + 1. / (long double)ft_power(10, precision);
	return (ret);
}
