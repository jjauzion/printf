/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 15:42:48 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/11 20:03:43 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		int_arg(va_list ap, t_spec *spec)
{
	t_var	var;

	spec->field = NULL;
	if (spec->c_specifier == 'i' || spec->c_specifier == 'd')
	{
		var.i = (int)va_arg(ap, int);
		spec->field = ft_itoa(var.i);
		ft_add_precision(spec);
	}
	else if (spec->c_specifier == 'u')
	{
		var.u = (unsigned int)va_arg(ap, int);
		spec->field = ft_uitoa(var.u);
		ft_add_precision(spec);
	}
	else if (spec->c_specifier == 'f')
	{
		var.d = (double)va_arg(ap, double);
		spec->field = ft_dtoa(var.d, spec->precision);
	}
	ft_generate_field(spec);
}

void		int_base_arg(va_list ap, t_spec *spec)
{
	t_var	var;

	spec->field = NULL;
	if (spec->c_specifier == 'o')
	{
		var.u = (unsigned int)va_arg(ap, int);
		spec->field = ft_uitoa_base(var.u, 8);
		ft_add_precision(spec);
	}
	else if (spec->c_specifier == 'x')
	{
		var.u = (unsigned int)va_arg(ap, int);
		spec->field = ft_uitoa_base(var.u, 16);
		ft_add_precision(spec);
	}
	else if (spec->c_specifier == 'X')
	{
		var.u = (unsigned int)va_arg(ap, int);
		spec->field = ft_uitoa_base(var.u, 16);
		spec->field = ft_strremapi(spec->field, &ft_toupper);
		ft_add_precision(spec);
	}
	ft_generate_field(spec);
}
/*
char		*s_arg(va_list ap, t_spec spec)
{
	t_var	var;
	char	*res;

	res = NULL;
	if (spec.c_specifier == 's')
	{
		var.s = (char*)va_arg(ap, char*);
		if (spec.precision >= 0)
			res = ft_strsub(var.s, 0, spec.precision);
		else
			res = ft_strdup(var.s);
	}
	res = ft_generate_field(&res, spec);
	return (res);
}

char		*c_arg(va_list ap, t_spec spec)
{
	t_var	var;
	char	*res;

	res = NULL;
	if (spec.c_specifier == 'c')
	{
		var.c = (char)va_arg(ap, int);
		res = ft_strcnew(1, var.c);
	}
	if (spec.c_specifier == 'C')
	{
		var.i = (int)va_arg(ap, int);
		res = ft_strcnew(1, var.c);
	}
	res = ft_generate_field(&res, spec);
	return (res);
}
*/
void		pct_arg(va_list ap, t_spec *spec)
{
	(void)ap;
	spec->field = ft_strdup("%");
}
