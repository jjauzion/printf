/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtag_attribute.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 10:30:13 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/08 10:59:40 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_hashtag_attribute(char **arg, t_spec spec)
{
	char	*res;

	if (spec.c_specifier == 'o')
		res = ft_strjoin("0", *arg);
	if (spec.c_specifier == 'x')
		res = ft_strjoin("0x", *arg);
	if (spec.c_specifier == 'X')
		res = ft_strjoin("0X", *arg);
	ft_strdel(arg);
	return (res);
}
