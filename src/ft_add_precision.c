/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:37:53 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/11 19:58:44 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_copy_w_zero(char *dst, char *src, int sign, int nb_zero)
{
	int		i;
	int		j;

	if (sign)
		dst[0] = '-';
	i = 0 + sign;
	j = 0 + sign;
	while (src[j])
	{
		if (i < nb_zero + sign)
			dst[i] = '0';
		else
		{
			dst[i] = (src[j]);
			j++;
		}
		i++;
	}
	dst[i] = '\0';
}

void		ft_add_precision(t_spec *spec)
{
	int		sign;
	int		len;
	char	*ret;

	sign = (spec->field[0] == '-') ? 1 : 0;
	len = (sign) ? ft_strlen(spec->field) - 1 : ft_strlen(spec->field);
	if (len >= spec->precision)
		return ;
	if (!(ret = ft_strnew(spec->precision + sign)))
		return ;
	ft_copy_w_zero(ret, spec->field, sign, spec->precision - len);
	free(spec->field);
	spec->field = ret;
}
