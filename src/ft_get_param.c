/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:55:54 by jjauzion          #+#    #+#             */
/*   Updated: 2017/12/19 20:19:18 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "specifier.h"
#include <stdio.h>
char		*int_arg(va_list ap, t_spec spec)
{
	int		arg;
	char	*res;

	res = NULL;
	arg = va_arg(ap, int);
	if (spec.c_specifier == 'i' || spec.c_specifier == 'd')
		res = ft_itoa(arg);
	else if (spec.c_specifier == 'u')
		res = ft_uitoa((unsigned int)arg);
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
	arg = ft_padding(&arg, spec);
	ft_putstr(arg);
	ft_strdel(&arg);
}
