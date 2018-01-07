/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 10:33:10 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/07 12:33:54 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_get_digit(const char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (ft_isdigit((*str)[i]))
		i++;
	if (i > 0)
	{
		tmp = ft_strsub(*str, 0, i);
		*str += i;
		i = ft_atoi(tmp);
		ft_strdel(&tmp);
	}
	return (i);
}

char		*ft_get_attribute(const char **format)
{
	char		*valid_attribute;
	int			i;
	char		*attribute;
	char		*ptr;

	valid_attribute = ft_strdup("#0-+ '");
	ptr = (char*)valid_attribute;
	attribute = ft_strnew(ft_strlen(*format) + 1);
	i = 0;
	while ((ptr = ft_strchr(valid_attribute, (int)(**format))))
	{
		attribute[i] = *ptr;
		(*format)++;
		i++;
	}
	attribute[i] = '\0';
	ft_strdel(&valid_attribute);
	return (attribute);
}

int			ft_get_precision(const char **format)
{
	if (**format != '.')
		return (-1);
	(*format)++;
	return (ft_get_digit(format));
}

char		*ft_get_lmodifier(const char **format)
{
	char	*valid_modifier;
	char	*modifier;
	char	*ptr;

	valid_modifier = ft_strdup("hljtzL");
	ptr = (char*)valid_modifier;
	modifier = ft_strnew(3);
	if (!(ptr = ft_strchr(valid_modifier, (int)(**format))))
	{
		ft_strdel(&valid_modifier);
		return (modifier);
	}
	modifier[0] = *ptr;
	(*format)++;
	if (*ptr == 'h' && **format == 'h')
	{
		modifier[1] = **format;
		(*format)++;
	}
	if (*ptr == 'l' && **format == 'l')
	{
		modifier[1] = **format;
		(*format)++;
	}
	ft_strdel(&valid_modifier);
	return (modifier);
}

char		ft_get_cspecifier(const char **format)
{
	char		*valid_specifier;
	char		specifier;
	char		*ptr;

	valid_specifier = ft_strdup("diouxXDOUeEfFgGaAcCsSPn%");
	ptr = (char*)valid_specifier;
	if (!(ptr = ft_strchr(valid_specifier, (int)(**format))))
	{
		ft_strdel(&valid_specifier);
		return (0);
	}
	specifier = *ptr;
	ft_strdel(&valid_specifier);
	return (specifier);
}

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
