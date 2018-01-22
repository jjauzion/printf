/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:15:45 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/22 17:42:32 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_specifier(const char *str)
{
	int	count;
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 0;
	count = 0;
	while (i <= len)
	{
		while (i <= len && str[i] != '%')
			i++;
		if (str[i] == '%')
		{
			count++;
			i++;
			while (ft_strchr(" +-#*'$0123456789.hlLjtz", str[i]))
				i++;
			i++;
		}
	}
	return (count);
}
