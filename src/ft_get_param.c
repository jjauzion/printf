/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:55:54 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/08 14:17:44 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "specifier.h"

void		ft_get_param(va_list ap, t_spec spec, int count)
{
	int		i;
	char	*arg;

	(void)count;
	i = 0;
	while (!ft_strchr(g_type[i].type, (int)spec.c_specifier))
		i++;
	arg = g_type[i].fct(ap, spec);
	ft_putstr(arg);
	ft_strdel(&arg);
}
