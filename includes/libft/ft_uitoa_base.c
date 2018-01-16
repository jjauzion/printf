/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 17:20:27 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/15 16:56:57 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_obase(unsigned int base)
{
	unsigned int	i;
	char			*obase;

	obase = ft_strnew(base);
	i = -1;
	while (++i < base)
	{
		if (i < 10)
			obase[i] = '0' + i;
		else
			obase[i] = 'a' + i - 10;
	}
	return (obase);
}

char			*ft_uitoa_base(unsigned int value, unsigned int base)
{
	char	*obase;
	char	*res;
	int		i;

	if (base < 2 || base > 16)
		return (NULL);
	obase = ft_obase(base);
	if (!(res = ft_strnew(32)))
		return (NULL);
	i = 0;
	while (value >= base)
	{
		res[i] = obase[value % base];
		value = value / base;
		i++;
	}
	res[i] = obase[value % base];
	res[i + 1] = '\0';
	res = ft_strrev(res);
	ft_strdel(&obase);
	return (res);
}
