/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtag_attribute.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 10:30:13 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/11 19:57:08 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hashtag_attribute(t_spec *spec)
{
	char	*res;

	if (spec->c_specifier == 'o')
		res = ft_strjoin("0", spec->field);
	if (spec->c_specifier == 'x')
		res = ft_strjoin("0x", spec->field);
	if (spec->c_specifier == 'X')
		res = ft_strjoin("0X", spec->field);
	free(spec->field);
	spec->field = res;
}
