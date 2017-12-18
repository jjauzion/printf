/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 10:27:07 by jjauzion          #+#    #+#             */
/*   Updated: 2017/12/18 18:06:51 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_spec(t_spec spec)
{
	ft_putstr("arg id = ");
	ft_putnbr(spec.arg_id);
	ft_putstr("\n");
	ft_putstr("attribute = ");
	ft_putstr(spec.attribute);
	ft_putstr("\n");
	ft_putstr("width = ");
	ft_putnbr(spec.width);
	ft_putstr("\n");
	ft_putstr("preci = ");
	ft_putnbr(spec.precision);
	ft_putstr("\n");
	ft_putstr("modifier = ");
	ft_putstr(spec.l_modifier);
	ft_putstr("\n");
	ft_putstr("specifier = ");
	ft_putchar(spec.c_specifier);
	ft_putstr("\n");
}

t_spec	*ft_init_spec(int size)
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
	}
	return (spec);
}

int		ft_printf(const char *format, ...)
{
	t_spec	*spec;
	int		cpt;
	va_list	ap;
	va_list	copy;
	int		count;

	va_start(ap, format);
	va_copy(copy, ap);
	count = ft_count_specifier(format);
	spec = ft_init_spec(count);
	cpt = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			format++;
		}
		else
		{
			spec[cpt].arg_id = cpt;
			if (!(format = ft_parse(format, &spec[cpt])))
				return (-1);
			ft_print_spec(spec[cpt]);
			va_copy(copy, ap);
//			ft_print (...);
			va_end(copy);
			cpt++;
		}
	}
	va_end(ap);
	ft_putendl("\n<<<<<<<<<<<<<<<<<<");
	return (666);
}
