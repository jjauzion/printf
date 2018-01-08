/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_field.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:55:21 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/08 10:52:04 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_generate_field(char **arg, t_spec spec)
{
	int		len;
	char	sign;
	int		width;

	len = ft_strlen(*arg);
	sign = ft_get_sign(*arg, spec);
	if (sign == '-')
		ft_shift_string(*arg, '\0', 'l', 0);
	if (ft_strchr(spec.attribute, '#'))
		*arg = ft_hashtag_attribute(arg, spec);
	if (!*arg)
		return (NULL);
	width = ft_width(*arg, spec, sign);
//realloc only if width != len ?
	if (!(*arg = (char *)ft_realloc((void **)arg, len, width - len + 1)))
		return (NULL);
	if (ft_strchr(spec.attribute, '-'))
		ft_padding(*arg, '-', sign, width);
	else if (ft_strchr(spec.attribute, '0'))
		ft_padding(*arg, '0', sign, width);
	else
		ft_padding(*arg, ' ', sign, width);
	return (*arg);
}
