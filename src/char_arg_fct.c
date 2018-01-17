#include "ft_printf.h"

void	ft_wstr_arg(t_var var, t_spec *spec)
{
	char	*tmp;

	spec->field = NULL;
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
	ft_generate_wfield(spec);
}

void	ft_wchar_arg(t_var var, t_spec *spec)
{
	wchar_t	*wtmp;

	wtmp = ft_wstrcnew(1, var.wc);
	spec->field = ft_wstr2str(wtmp);
	free(wtmp);
	wtmp = NULL;
	ft_generate_wfield(spec);
}

void	ft_str_arg(t_var var, t_spec *spec)
{
	spec->field = NULL;
	if (spec->precision >= 0)
		spec->field = ft_strsub(var.s, 0, spec->precision);
	else
		spec->field = ft_strdup(var.s);
	ft_generate_field(spec);
}

void	ft_char_arg(t_var var, t_spec *spec)
{
	spec->field = ft_strcnew(1, var.c);
	ft_generate_field(spec);
}
