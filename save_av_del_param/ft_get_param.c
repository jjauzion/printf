/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:55:54 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/11 19:05:49 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "specifier.h"

void	ft_get_param(va_list ap, t_spec *spec, int cpt)
{
	int		i;

	i = 0;
	while (!ft_strchr(g_type[i].type, (int)spec[cpt].c_specifier))
		i++;
	g_type[i].fct(ap, spec, cpt);
}
