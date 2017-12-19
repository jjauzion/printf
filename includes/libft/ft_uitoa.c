/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 09:46:11 by jjauzion          #+#    #+#             */
/*   Updated: 2017/12/19 17:55:39 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_size(int nbr)
{
	int	size;

	size = 1;
	while (nbr > 10 || nbr < -10)
	{
		nbr = nbr / 10;
		size++;
	}
	if (nbr < 0)
		return (size + 1);
	else
		return (size);
}

char		*ft_uitoa(unsigned int n)
{
	char			*str;
	int				i;
	int				size;

	size = ft_get_size(n);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (n >= 10)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	str[i] = n % 10 + '0';
	str = ft_strrev(str);
	return (str);
}
