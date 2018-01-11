/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:15:45 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/11 16:29:33 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_specifier(const char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[++i])
	{
		if (str[i - 1] == '%' && str[i] != '%')
			count++;
	}
	return (count);
}
