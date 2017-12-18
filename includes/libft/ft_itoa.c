/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 09:46:11 by jjauzion          #+#    #+#             */
/*   Updated: 2017/11/16 10:55:28 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoui(int n, unsigned int *nbr)
{
	int	sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		*nbr = (unsigned int)(n * -1);
	}
	else
		*nbr = n;
	return (sign);
}

static void	ft_apply_sign(int i, int sign, char *str)
{
	if (sign < 0)
	{
		str[i + 1] = '-';
		str[i + 2] = '\0';
	}
	else
		str[i + 1] = '\0';
}

char		*ft_itoa(int n)
{
	char			*str;
	unsigned int	nbr;
	int				sign;
	int				i;

	nbr = 0;
	sign = ft_itoui(n, &nbr);
	if (!(str = (char *)malloc(sizeof(char) * 12)))
		return (NULL);
	i = 0;
	while (nbr >= 10)
	{
		str[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i++;
	}
	str[i] = nbr % 10 + '0';
	ft_apply_sign(i, sign, str);
	str = ft_strrev(str);
	return (str);
}
