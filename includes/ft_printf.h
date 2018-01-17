/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 15:39:06 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/17 11:50:44 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct		s_specifier
{
	int				arg_id;
	char			*attribute;
	int				width;
	int				precision;
	char			*l_modifier;
	char			c_specifier;
	char			*field;
}					t_spec;

typedef union		u_variable
{
	intmax_t		im;
	uintmax_t		uim;
	long double		ld;
	char			c;
	char			*s;

	int				i;
	short int		si;
	long int		li;
	long long int	lli;
	size_t			st;
	unsigned int	u;
	double			d;
	float			f;
	wchar_t			wc;
	wchar_t			*ws;
}					t_var;

typedef struct		s_type
{
	char			*type;
	void			(*fct)(t_var var, t_spec *spec);
}					t_type;

int					ft_printf(const char *format, ...);
const char			*ft_parse(const char *format, t_spec *spec);
int					ft_count_specifier(const char *str);
int					ft_get_param(va_list ap, t_spec *spec, int cpt);
void				ft_add_precision(t_spec *spec);
void				ft_generate_field(t_spec *spec);
int					ft_print_all(char **plain_str, t_spec *spec, int nb_param);
t_var				ft_get_arg(va_list ap, t_spec *spec);

void				ft_generate_wfield(t_spec *spec);
void				ft_clean_utf8str(char *str);

char				ft_get_sign(t_spec spec);
void				ft_shift_string(char *arg, char c, char option, int width);
void				ft_apply_sign(char *arg, char sign, int width);
int					ft_width(t_spec spec, int sign_len);
void				ft_padding(char *arg, char option, int sign_len, int width);
char				*ft_get_lmodifier(const char **format);
int					ft_get_precision(const char **format);
char				*ft_get_attribute(const char **format);
int					ft_get_digit(const char **str);
void				ft_hashtag_attribute(t_spec *spec);
void				ft_apply_ohashtag(t_spec *spec);
void				ft_apply_0xhashtag(t_spec *spec, int width);

void				ft_usage(t_var var, t_spec *spec);
void				ft_int_arg(t_var var, t_spec *spec);
void				ft_uint_arg(t_var var, t_spec *spec);
void				ft_wstr_arg(t_var var, t_spec *spec);
void				ft_str_arg(t_var var, t_spec *spec);
void				ft_wchar_arg(t_var var, t_spec *spec);
void				ft_char_arg(t_var var, t_spec *spec);
void				ft_float_arg(t_var var, t_spec *spec);
void				ft_pct_arg(t_var var, t_spec *spec);

#endif
