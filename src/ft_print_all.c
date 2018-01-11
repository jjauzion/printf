/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:01:24 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/11 16:30:09 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_all(char **plain_str, char **param, t_spec *spec, int nb_param)
{
	int		i;

	(void)spec;	
	i = -1;
	while (++i < nb_param)
	{
		ft_putstr(plain_str[i]);
		ft_putstr(param[i]);
	}
	ft_putstr(plain_str[i]);
	return (1);
}
