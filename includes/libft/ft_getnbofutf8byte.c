/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbofutf8byte.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:26:10 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/13 19:30:43 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_bit2oct(int nb)
{
	if (nb <= 7)
		return (1);
	if (nb <= 11)
		return (2);
	if (nb <= 16)
		return (3);
	return (4);
}

int			ft_getnbofutf8byte(wchar_t var)
{
	int		active_bits;

	active_bits = 0;
	while (var)
	{
		var = var >> 1;
		active_bits++;
	}
	return (ft_bit2oct(active_bits));
}
