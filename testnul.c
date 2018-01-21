/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testnul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 18:11:49 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/21 19:15:45 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int		ret;
	int		retft;
	int		max;
	char	c;
	int		i;

//	setlocale(LC_ALL, "");
	max = MB_CUR_MAX;
	printf("max = %d\n", max);

	ret = printf("%C mais rien", 0xbffe);
	printf("\n--------\nret = %d\n---------\n", ret);

	retft = ft_printf("%C", 0xbffe);
	printf("\n--------\nretft = %d\n---------\n", retft);

	c = 254;
	ret = printf("%c et rien?", c);
	printf("\n--------\nret = %d\n---------\n", ret);

	retft = ft_printf("%c et rien?", c);
	printf("\n--------\nretft = %d\n---------\n", retft);

	i = (unsigned char)c;
	printf("i = %d\n", i);

	return (0);
}
