/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 15:42:48 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/16 16:59:06 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		float_arg(va_list ap, t_spec *spec)
{
	t_var	var;

	spec->field = NULL;
	if (spec->c_specifier == 'f')
	{
		var.d = (double)va_arg(ap, double);
		spec->field = ft_dtoa(var.d, spec->precision);
	}
	ft_generate_field(spec);
}

void		int_arg(va_list ap, t_spec *spec)
{
	t_var	var;

	spec->field = NULL;
	var.im = va_arg(ap, intmax_t);
	if (spec->c_specifier == 'i' || spec->c_specifier == 'd')
	{
		spec->field = ft_itoa(var.i);
		ft_add_precision(spec);
	}
	else if (spec->c_specifier == 'u')
	{
		var.u = (unsigned int)va_arg(ap, int);
		spec->field = ft_uitoa(var.u);
		ft_add_precision(spec);
	}
	ft_generate_field(spec);
}

void		int_base_arg(va_list ap, t_spec *spec)
{
	t_var	var;

	spec->field = NULL;
	var.u = (unsigned int)va_arg(ap, int);
	if (var.u == 0)
		spec->attribute = ft_str_del_char(&spec->attribute, '#');
	if (spec->c_specifier == 'o')
		spec->field = ft_uitoa_base(var.u, 8);
	else if (spec->c_specifier == 'x')
		spec->field = ft_uitoa_base(var.u, 16);
	else if (spec->c_specifier == 'X')
	{
		spec->field = ft_uitoa_base(var.u, 16);
		spec->field = ft_strremapi(spec->field, &ft_toupper);
	}
	ft_add_precision(spec);
	ft_generate_field(spec);
}

void		sc_arg(va_list ap, t_spec *spec)
{
	t_var	var;

	spec->field = NULL;
	if (spec->c_specifier == 's')
	{
		var.s = (char*)va_arg(ap, char*);
		if (spec->precision >= 0)
			spec->field = ft_strsub(var.s, 0, spec->precision);
		else
			spec->field = ft_strdup(var.s);
	}
	if (spec->c_specifier == 'c')
	{
		var.c = (char)va_arg(ap, int);
		spec->field = ft_strcnew(1, var.c);
	}
	ft_generate_field(spec);
}

void		wSC_arg(va_list ap, t_spec *spec)
{
	t_var	var;
	char	*tmp;
	wchar_t	*wtmp;

	spec->field = NULL;
	if (spec->c_specifier == 'S')
	{
		var.ws = (wchar_t*)va_arg(ap, wchar_t*);
		if (spec->precision >= 0)
		{
			if (!(tmp = ft_wstr2str(var.ws)))
				return ;
			spec->field = ft_strsub(tmp, 0, spec->precision);
			ft_strdel(&tmp);
			ft_clean_utf8str(spec->field);
		}
		else
			spec->field = ft_wstr2str(var.ws);
	}
	if (spec->c_specifier == 'C')
	{
		var.wc = (wchar_t)va_arg(ap, wchar_t);
		wtmp = ft_wstrcnew(1, var.wc);
		spec->field = ft_wstr2str(wtmp);
		free(wtmp);
		wtmp = NULL;
	}
	ft_generate_wfield(spec);
}

void		pct_arg(va_list ap, t_spec *spec)
{
	(void)ap;
	spec->field = ft_strdup("%");
}
