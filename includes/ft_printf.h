/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 15:39:06 by jjauzion          #+#    #+#             */
/*   Updated: 2017/12/19 20:18:21 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct	s_specifier
{
	int		arg_id;
	char	*attribute;
	int		width;
	int		precision;
	char	*l_modifier;
	char	c_specifier;
}				t_spec;

typedef struct	s_type
{
	char	*type;
	char*	(*fct)(va_list ap, t_spec spec);
}				t_type;

int			ft_printf(const char *format, ...);
const char	*ft_parse(const char *format, t_spec *spec);
int			ft_count_specifier(const char *str);
void		ft_get_param(va_list ap, t_spec spec, int count);
char		*int_arg(va_list ap, t_spec spec);
char		*ft_padding(char **arg, t_spec spec);

#endif
