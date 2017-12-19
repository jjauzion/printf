/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 19:54:28 by jjauzion          #+#    #+#             */
/*   Updated: 2017/12/19 20:28:29 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_plus_or_space(char **arg, t_spec spec)
{
	char	*tmp;
	int		len;

	len = ft_strlen(*arg);
	tmp = ft_strdup("difeEgG");
	if (ft_strchr(tmp, (int)spec.c_specifier) && (*arg)[0] != '-' && (ft_strchr(spec.attribute, '+') || ft_strchr(spec.attribute, ' ')))
	{
		if (!(*arg = (char *)ft_realloc((void **)arg, len, 1)))
			return (NULL);
		*arg = ft_strrev(*arg);
		if (ft_strchr(spec.attribute, '+'))
			*arg = ft_strcat(*arg, "+");
		else
			*arg = ft_strcat(*arg, " ");
		*arg = ft_strrev(*arg);
	}
	ft_strdel(&tmp);
	return (*arg);
}

char	*ft_padding(char **arg, t_spec spec)
{
	int		len;

	if (!(*arg = ft_plus_or_space(arg, spec)))
		return (NULL);
	len = ft_strlen(*arg);
	if (len >= spec.width)
		return (*arg);
	if (!(*arg = (char *)ft_realloc((void **)arg, len, spec.width - len)))
		return (NULL);
	if (!ft_strchr(spec.attribute, '-'))
		*arg = ft_strrev(*arg);
	while (len < spec.width)
	{
		if (ft_strchr(spec.attribute, '0') && !ft_strchr(spec.attribute, '-'))
			(*arg)[len] = '0';
		else
			(*arg)[len] = ' ';
		len++;
	}
	(*arg)[len] = '\0';
	if (!ft_strchr(spec.attribute, '-'))
		*arg = ft_strrev(*arg);
	return (*arg);
}
