/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_field.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:55:21 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/11 19:56:29 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_generate_field(t_spec *spec)
{
	int		len;
	char	sign;
	int		width;

	sign = ft_get_sign(*spec);
	if (sign == '-')
		ft_shift_string(spec->field, '\0', 'l', 0);
	if (ft_strchr(spec->attribute, '#'))
		ft_hashtag_attribute(spec);
	if (!spec->field)
		return ;
	len = ft_strlen(spec->field);
	width = ft_width(*spec, sign);
//realloc only if width != len ?
	if (!(spec->field = (char *)ft_realloc((void **)&spec->field, len + 1, width - len + 1)))
		return ;
	if (ft_strchr(spec->attribute, '-'))
		ft_padding(spec->field, '-', sign, width);
	else if (ft_strchr(spec->attribute, '0'))
		ft_padding(spec->field, '0', sign, width);
	else
		ft_padding(spec->field, ' ', sign, width);
}
