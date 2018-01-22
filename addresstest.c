/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addresstest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:50:16 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/22 18:27:04 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main ()
{
	char		*c;
	size_t		test;
	char		*str;
	uintmax_t	uim;

	c = ft_strnew(2);
	printf("@c = |%-50.20p|\n", c);
	ft_printf("@c = |%-50.20p|\n", c);

	while (1);
	{}
	return (0);
}
