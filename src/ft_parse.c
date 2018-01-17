/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 10:33:10 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/17 11:56:01 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_parse(const char *format, t_spec *spec)
{
	int		tmp;

	format++;
	spec->attribute = ft_get_attribute(&format);
	tmp = ft_get_digit(&format);
	if (spec->attribute[0] == '\0')
	{
		if (*format == '$')
		{
			spec->arg_id = tmp;
			format++;
			spec->attribute = ft_get_attribute(&format);
			tmp = ft_get_digit(&format);
		}
	}
	spec->width = tmp;
	spec->precision = ft_get_precision(&format);
	spec->l_modifier = ft_get_lmodifier(&format);
	spec->c_specifier = *format;
	if (ft_strchr("fFgGeE", spec->c_specifier) && (spec->precision < 0))
		spec->precision = 6;
	if (ft_strchr("diouxXDOU", spec->c_specifier)
		   	&& ft_strchr(spec->attribute, '0') && spec->precision >= 0)
		spec->attribute = ft_str_del_char(&spec->attribute, '0');
	format++;
	return (format);
}
