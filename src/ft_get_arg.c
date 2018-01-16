/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 15:42:48 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/16 18:47:01 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_var	ft_get_arg(va_list ap, t_spec *spec)
{
	t_var	var;

	if (ft_strchr("di", spec->c_specifier))
		var.im = va_arg(ap, intmax_t);
	else if (ft_strchr("ouxXDOU", spec->c_specifier))
		var.uim = va_arg(ap, uintmax_t);
	else if (ft_strchr("eEfFgGaA", spec->c_specifier))
		var.ld = va_arg(ap, long double);
	else if (ft_strchr("c", spec->c_specifier))
		var.c = (char)va_arg(ap, int);
	else if (ft_strchr("s", spec->c_specifier))
		var.s = va_arg(ap, char*);
	else
		var.im = 0;
	return (var);
}
