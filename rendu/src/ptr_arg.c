/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:02:00 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/22 18:22:20 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ptr_arg(t_var var, t_spec *spec)
{
	char	*tmp;
	
	spec->field = ft_uitoa_base(var.uim, 16);
	ft_add_precision(spec);
	tmp = spec->field;
	spec->field = ft_strjoin("0x", tmp);
	ft_strdel(&tmp);
	ft_generate_wfield(spec);
	return (0);
}
