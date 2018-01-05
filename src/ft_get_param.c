/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:55:54 by jjauzion          #+#    #+#             */
/*   Updated: 2017/12/20 20:35:43 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "specifier.h"
#include <stdio.h>
char		*int_arg(va_list ap, t_spec spec)
{
	t_var	var;
	char	*res;

	res = NULL;
	if (spec.c_specifier == 'i' || spec.c_specifier == 'd')
	{
		var.i = (int)va_arg(ap, int);
		res = ft_itoa(var.i);
	}
	else if (spec.c_specifier == 'u')
	{
		var.u = (unsigned int)va_arg(ap, int);
		res = ft_uitoa(var.u);
	}
	else if (spec.c_specifier == 'f')
	{
		var.d = (double)va_arg(ap, double);
		res = ft_dtoa(var.d, spec.precision);
	}
	return (res);
}

void		ft_get_param(va_list ap, t_spec spec, int count)
{
	int		i;
	char	*arg;

	(void)count;
	i = 0;
	while (!ft_strchr(g_type[i].type, (int)spec.c_specifier))
		i++;
	arg = g_type[i].fct(ap, spec);
//ft_putstr("1 arg = ");
//ft_putendl(arg); 
	arg = ft_generate_field(&arg, spec);
//ft_putstr("2 arg = ");
//ft_putendl(arg); 
	ft_putstr(arg);
	ft_strdel(&arg);
}
