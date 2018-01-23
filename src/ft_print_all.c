/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:01:24 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/23 15:36:14 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_all(char **plain_str, t_spec *spec, int nb_param)
{
	int				i;
	int				ret;

	i = -1;
	ret = 0;
	while (++i < nb_param)
	{
		if (spec[i].width < 0)
			return (-1);
		ft_putstr(plain_str[i]);
		ret += ft_strlen(plain_str[i]);
		if (ft_strchr("cC", spec[i].c_specifier) && ft_strchr(spec[i].attribute, '-'))
			ret += ft_putwchar(spec[i].v_char);
		ft_putstr(spec[i].field);
		ret += spec[i].width;
		if (ft_strchr("cC", spec[i].c_specifier) && !ft_strchr(spec[i].attribute, '-'))
			ret += ft_putwchar(spec[i].v_char);
	}
	ft_putstr(plain_str[i]);
	ret += ft_strlen(plain_str[i]);
	return (ret);
}
