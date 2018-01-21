/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 15:40:29 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/21 17:46:46 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <locale.h>
#include <stdlib.h>
#include "ft_printf.h"

int main ()
{

	int i = 250;
	int ret = 0;
	int retft = 0;
	int	max = MB_CUR_MAX;

	printf("max = %d\n", max);
/*	char* l = setlocale(LC_ALL, "");
	if (l == NULL)
		printf("Locale not set\n");
	else
		printf("Locale set to %s\n", l); 
*/
	printf("\n->\n");
	ret = printf("%lc", 254);
	printf("\n---> ret = %d\n", ret);
	retft = ft_printf("%lc", 254);
	printf("\n---> retft = %d\n", retft);
	while (i < 513)
	{
		ret = printf("%C", i);
//		ret = ft_printf("%C", i);
		printf("\ni = %d ; ret = %d\n", i, ret);
		if (ret < 0)
			getchar();
		i++;
	}

	/*	i = 490;
		ret = write(1, &i, 1);
		printf("\nafter ret = %d\n", ret);
		*/
}
