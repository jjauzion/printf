/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 15:39:06 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/15 16:51:15 by jjauzion         ###   ########.fr       */
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

typedef struct		s_type
{
	char			*type;
	void			(*fct)(va_list ap, t_spec *spec);
}					t_type;

typedef union		u_variable
{
	int				i;
	short int		si;
	intmax_t		im;
	long int		li;
	long long int	lli;
	size_t			st;
	unsigned int	u;
	double			d;
	float			f;
	char			c;
	char			*s;
	wchar_t			wc;
	wchar_t			*ws;
}					t_var;

int					ft_printf(const char *format, ...);
const char			*ft_parse(const char *format, t_spec *spec);
int					ft_count_specifier(const char *str);
int					ft_get_param(va_list ap, t_spec *spec, int cpt);
void				ft_add_precision(t_spec *spec);
void				ft_generate_field(t_spec *spec);
int					ft_print_all(char **plain_str, t_spec *spec, int nb_param);

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

void				int_arg(va_list ap, t_spec *spec);
void				int_base_arg(va_list ap, t_spec *spec);
void				sc_arg(va_list ap, t_spec *spec);
void				wSC_arg(va_list ap, t_spec *spec);
void				pct_arg(va_list ap, t_spec *spec);
void				usage(va_list ap, t_spec *spec);
void				float_arg(va_list ap, t_spec *spec);

#endif
