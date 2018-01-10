/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 15:42:48 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/10 19:19:40 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*int_arg(va_list ap, t_spec spec)
{
	t_var	var;
	char	*res;

	res = NULL;
	if (spec.c_specifier == 'i' || spec.c_specifier == 'd')
	{
		var.i = (int)va_arg(ap, int);
		res = ft_itoa(var.i);
		res = ft_add_precision(&res, spec);
	}
	else if (spec.c_specifier == 'u')
	{
		var.u = (unsigned int)va_arg(ap, int);
		res = ft_uitoa(var.u);
		res = ft_add_precision(&res, spec);
	}
	else if (spec.c_specifier == 'f')
	{
		var.d = (double)va_arg(ap, double);
		res = ft_dtoa(var.d, spec.precision);
	}
	res = ft_generate_field(&res, spec);
	return (res);
}

char		*int_base_arg(va_list ap, t_spec spec)
{
	t_var	var;
	char	*res;

	res = NULL;
	if (spec.c_specifier == 'o')
	{
		var.u = (unsigned int)va_arg(ap, int);
		res = ft_uitoa_base(var.u, 8);
		res = ft_add_precision(&res, spec);
	}
	else if (spec.c_specifier == 'x')
	{
		var.u = (unsigned int)va_arg(ap, int);
		res = ft_uitoa_base(var.u, 16);
		res = ft_add_precision(&res, spec);
	}
	else if (spec.c_specifier == 'X')
	{
		var.u = (unsigned int)va_arg(ap, int);
		res = ft_uitoa_base(var.u, 16);
		res = ft_strremapi(res, &ft_toupper);
		res = ft_add_precision(&res, spec);
	}
	res = ft_generate_field(&res, spec);
	return (res);
}

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
/*	if (spec.c_specifier == 'S')
	{
		var.s = (char*)va_arg(ap, char*);
		if (spec.precision >= 0)
			res = ft_strsub(var.s, 0, spec.precision);
		else
			res = ft_strdup(var.s);
	}
*/	res = ft_generate_field(&res, spec);
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

char		*pct_arg(va_list ap, t_spec spec)
{
	char	*res;

	(void)ap;
	(void)spec;
	res = ft_strdup("%");
	return (res);
}
