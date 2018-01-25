/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testnul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 18:11:49 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/25 20:12:29 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int		ret;
	int		retft;
	int		max;
	int		i;
	wchar_t	s[4];
	char	*str;

//	setlocale(LC_ALL, "");
	max = MB_CUR_MAX;
	printf("max = %d\n", max);
/*
	s[0] = 'a';
	s[1] = 256;
	s[2] = 'b';
	s[3] = '\0';

	printf("\n\nprintf : ->\n");
	ret = printf("%9ls", s);
	printf("|\nft_printf : ->\n");
	retft = ft_printf("%9ls", s);
	printf("|\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
*/
/*	printf("\n\nprintf : |\n");
	ret = printf("hello %c et %c", 's', 'g');
	printf("|\nft_printf : |\n");
	retft = ft_printf("hello %c et %c", 's', 'g');
	printf("|\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
*/
	ft_printf("hello %s ca va", "op");

	return (0);
}
