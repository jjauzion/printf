/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 10:27:07 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/22 19:18:38 by jjauzion         ###   ########.fr       */
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

static void		ft_printf_closure(t_spec **spec, char ***plain_str, int nb_param)
{
	int	i;

	ft_delspec(spec, nb_param);
	i = -1;
	while (++i < nb_param)
	{
		ft_strdel(&(*plain_str)[i]);
	}
	ft_strdel(&(*plain_str)[i]);
	free(*plain_str);
}

int				ft_printf(const char *format, ...)
{
	t_spec	*spec;
	int		cpt;
	va_list	ap;
	int		count;
	char	**plain_str;
	int		i;

	va_start(ap, format);
	count = ft_count_specifier(format);
	plain_str = (char**)malloc(sizeof(char*) * (count + 1));
	if (!plain_str)
		return (-1);
	cpt = -1;
	while (++cpt < count + 1)
	{
		if (!(plain_str[cpt] = ft_strnew(ft_strlen(format))))
			return (-1);
	}
	spec = ft_init_spec(count);
	cpt = 0;
	count = 0;
	i = 0;
	while (*format && i >= 0)
	{
		i = 0;
		while (*format && *format != '%')
		{
			plain_str[cpt][i] = *format;
			format++;
			i++;
		}
		if (*format == '%')
		{
			spec[cpt].arg_id = cpt;
			if (!(format = ft_parse(format, &spec[cpt])))
				return (-1);
			if (ft_get_param(ap, spec, cpt))
				i = -1;
			count++;
		}
		cpt++;
	}
	cpt = ft_print_all(plain_str, spec, count);
	va_end(ap);
	ft_printf_closure(&spec, &plain_str, count);
	return (cpt);
}
