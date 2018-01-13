/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:55:54 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/12 11:21:41 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "specifier.h"

int		ft_get_param(va_list ap, t_spec *spec, int cpt)
{
	int		i;

	i = 0;
	while (!ft_strchr(g_type[i].type, (int)spec[cpt].c_specifier) && g_type[i].type[0] != ' ')
		i++;
	g_type[i].fct(ap, &spec[cpt]);
	if (g_type[i].type[0] == ' ')
		return (1);
	else
		return (0);
}

void	usage(va_list ap, t_spec *spec)
{
	(void)ap;
	ft_putstr("\n---------------------------\nError: '%");
	ft_putchar(spec->c_specifier);
	ft_putendl("' is not a valid specifier");
	ft_putendl("---------------------------\n");
}
