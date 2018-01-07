/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 10:33:10 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/07 19:52:47 by jjauzion         ###   ########.fr       */
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
	if (!(spec->c_specifier = ft_get_cspecifier(&format)))
		return (NULL);
	if (ft_strchr("fFgGeE", spec->c_specifier) && (spec->precision < 0))
		spec->precision = 6;
	format++;
	return (format);
}
