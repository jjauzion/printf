/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 10:27:07 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/25 12:09:14 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_spec	*ft_init_spec(int size)
{
	t_spec	*spec;
	int		i;

	if (!(spec = (t_spec*)malloc(sizeof(t_spec) * size)))
		return (NULL);
	i = -1;
	while (++i < size)
	{
		spec[i].attribute = NULL;
		spec[i].width = -1;
		spec[i].precision = -1;
		spec[i].l_modifier = NULL;
		spec[i].c_specifier = 0;
		spec[i].v_char = 0;
	}
	return (spec);
}

static void		ft_delspec(t_spec **spec, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if ((*spec)[i].attribute)
			ft_strdel(&(((*spec)[i]).attribute));
		if ((*spec)[i].l_modifier)
			ft_strdel(&(((*spec)[i]).l_modifier));
		if ((*spec)[i].field)
			ft_strdel(&(((*spec)[i]).field));
	}
	free(*spec);
}

static void		ft_printf_closure(t_spec **spec, char **plain_str, int nb_param)
{
	ft_delspec(spec, nb_param);
	ft_strdel(plain_str);
}

int				ft_printf(const char *format, ...)
{
	t_spec	*spec;
	int		cpt;
	va_list	ap;
	int		count;
	char	*plain_str;
	int		i;
	int		ret;
	int		iscolor;

	va_start(ap, format);
	count = ft_count_specifier(format);
	if (!(plain_str = ft_strnew(ft_strlen(format))))
		return (-1);
	spec = ft_init_spec(count);
	cpt = 0;
	count = 0;
	i = 0;
	ret = 0;
	while (*format)
	{
		i = 0;
		iscolor = 1;
		if (*format == '{')
		{
			plain_str[i] = '\0';
			ret = ft_print_current(plain_str, NULL, ret);
			i = 0;
			iscolor = ft_color(&format);
		}
		while (*format && *format != '%' && (*format != '{' || !iscolor))
		{
			iscolor = 1;
			plain_str[i] = *format;
			format++;
			i++;
		}
		plain_str[i] = '\0';
		if (*format == '%')
		{
			spec[cpt].arg_id = cpt;
			if (!(format = ft_parse(ap, format, &spec[cpt])))
				return (-1);
			count++;
			if (ft_get_param(ap, spec, cpt))
			{
				ft_printf_closure(&spec, &plain_str, count);
				return (-1);
			}
			ret = ft_print_current(plain_str, &spec[cpt], ret);
			cpt++;
		}
		else
			ret = ft_print_current(plain_str, NULL, ret);
	}
	va_end(ap);
	ft_printf_closure(&spec, &plain_str, count);
	return (ret);
}
