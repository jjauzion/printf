/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:15:45 by jjauzion          #+#    #+#             */
/*   Updated: 2017/12/18 17:34:25 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_specifier(const char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == '%')
			count++;
		str++;
	}
	return (count);
}
