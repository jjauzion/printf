/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 15:39:06 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/11 16:15:17 by jjauzion         ###   ########.fr       */
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
}					t_spec;

typedef struct		s_type
{
	char			*type;
	char			*(*fct)(va_list ap, t_spec spec);
}					t_type;

typedef union		u_variable
{
	short			xs;
	int				i;
	unsigned int	u;
	long			l;
	double			d;
	float			f;
	char			c;
	char			*s;
}					t_var;

int					ft_printf(const char *format, ...);
const char			*ft_parse(const char *format, t_spec *spec);
int					ft_count_specifier(const char *str);
void				ft_get_param(va_list ap, t_spec spec, int count, char **param);
void				ft_padding(char *arg, char option, char sign, int width);
char				*ft_add_precision(char **nbr, t_spec spec);
char				*ft_generate_field(char **arg, t_spec spec);
int					ft_print_all(char **plain_str, char **param, t_spec *spec, int nb_param);

char				ft_get_sign(char *arg, t_spec spec);
void				ft_shift_string(char *arg, char c, char option, int width);
void				ft_apply_sign(char *arg, char sign, int width);
int					ft_width(char *arg, t_spec spec, char sign);
void				ft_padding(char *arg, char option, char sign, int width);
char				ft_get_cspecifier(const char **format);
char				*ft_get_lmodifier(const char **format);
int					ft_get_precision(const char **format);
char				*ft_get_attribute(const char **format);
int					ft_get_digit(const char **str);
char				*ft_hashtag_attribute(char **arg, t_spec spec);
void				ft_padding(char *arg, char option, char sign, int width);

char				*int_arg(va_list ap, t_spec spec);
char				*int_base_arg(va_list ap, t_spec spec);
char				*s_arg(va_list ap, t_spec spec);
char				*c_arg(va_list ap, t_spec spec);
char				*pct_arg(va_list ap, t_spec spec);

#endif
