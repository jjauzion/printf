/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:48:23 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/17 11:55:13 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_float_arg(t_var var, t_spec *spec)
{
	long double	arg;

	spec->field = NULL;
	if (ft_strequ(spec->l_modifier, "l"))
		arg = var.ld;
	else
		arg = (double)var.ld;
	spec->field = ft_dtoa(var.ld, spec->precision);
	ft_generate_field(spec);
}
