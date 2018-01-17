/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 10:51:52 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/17 10:52:43 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_base(char spec)
{
	if (spec == 'o')
		return (8);
	else if (spec == 'x' || spec == 'X')
		return (16);
	else
		return (10);
}

void	ft_uint_arg(t_var var, t_spec *spec)
{
	uintmax_t	arg;
	int			base;

	base = ft_base(spec->c_specifier);
	spec->field = NULL;
	if (ft_strequ(spec->l_modifier, "hh"))
		arg = (unsigned char)var.uim;
	else if (ft_strequ(spec->l_modifier, "h"))
		arg = (short unsigned)var.uim;
	else if (ft_strequ(spec->l_modifier, "j"))
		arg = var.uim;
	else if (ft_strequ(spec->l_modifier, "l"))
		arg = (long unsigned int)var.uim;
	else if (ft_strequ(spec->l_modifier, "ll"))
		arg = (unsigned long long int)var.uim;
	else if (ft_strequ(spec->l_modifier, "z"))
		arg = (size_t)var.uim;
	else
		arg = (unsigned int)var.uim;
	spec->field = ft_uitoa_base(arg, base);
	ft_add_precision(spec);
	ft_generate_field(spec);
}
