/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:39:27 by jjauzion          #+#    #+#             */
/*   Updated: 2017/12/18 17:31:02 by jjauzion         ###   ########.fr       */
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

int			ft_printf(const char *format, ...);
const char	*ft_parse(const char *format, t_spec *spec);
int			ft_count_specifier(const char *str);

#endif
