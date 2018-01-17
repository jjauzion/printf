/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 10:52:22 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/17 10:52:33 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_wstr_arg(t_var var, t_spec *spec)
{
	char	*tmp;

	spec->field = NULL;
	if (spec->precision >= 0)
	{
		if (!(tmp = ft_wstr2str(var.ws)))
			return ;
		spec->field = ft_strsub(tmp, 0, spec->precision);
		ft_strdel(&tmp);
		ft_clean_utf8str(spec->field);
	}
	else
		spec->field = ft_wstr2str(var.ws);
	ft_generate_wfield(spec);
}
