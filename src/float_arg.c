/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:48:23 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/21 16:33:08 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_float_arg(t_var var, t_spec *spec)
{
	long double	arg;

	spec->field = NULL;
	if (ft_strequ(spec->l_modifier, "L"))
		arg = var.ld;
	else
		arg = (double)var.ld;
	spec->field = ft_dtoa(var.ld, spec->precision);
	ft_generate_field(spec);
	return (0);
}
