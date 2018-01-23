#include "ft_printf.h"

int		ft_str_arg(t_var var, t_spec *spec)
{
	char	*tmp;

	spec->field = NULL;
	if (spec->c_specifier == 'S' || ft_strchr(spec->l_modifier, 'l'))
	{
		if (!var.ws)
			tmp = ft_strdup("(null)");
		else
		{
			if (!(tmp = ft_wstr2str(var.ws, spec->precision)))
			{
				spec->width = -1;
				spec->field = ft_strnew(0);
				return (1);
			}
		}
		if (spec->precision >= 0)
		{
			spec->field = ft_strsub(tmp, 0, spec->precision);
			ft_clean_utf8str(spec->field);
		}
		else
			spec->field = ft_strdup(tmp);
		ft_strdel(&tmp);
		ft_generate_wfield(spec);
	}
	else
	{
		if (!var.s)
			tmp = ft_strdup("(null)");
		else
			tmp = ft_strdup(var.s);
		if (spec->precision >= 0)
			spec->field = ft_strsub(tmp, 0, spec->precision);
		else
			spec->field = ft_strdup(tmp);
		ft_strdel(&tmp);
		ft_generate_wfield(spec);
	}
	return (0);
}

int		ft_char_arg(t_var var, t_spec *spec)
{
	spec->field = ft_strnew(0);
	if (spec->c_specifier == 'C' || ft_strchr(spec->l_modifier, 'l'))
	{
		if ((var.wc >= 0xD800 && var.wc <= 0xDFFF) || var.wc > 0x10FFFF || var.wc < 0)
		{
			spec->width = -1;
			return (1);
		}
		if (MB_CUR_MAX < ft_getnbofutf8byte(var.wc))
		{
			if (var.wc < 256)
				spec->v_char = (char)var.wc;
			else
			{
				spec->width = -1;
				return (1);
			}
		}
		else
			spec->v_char = var.wc;
	}
	else
		spec->v_char = (wchar_t)var.c;
	ft_generate_wfield(spec);
	return (0);
}
