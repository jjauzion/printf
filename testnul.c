/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testnul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 18:11:49 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/25 13:51:57 by jjauzion         ###   ########.fr       */
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

	setlocale(LC_ALL, "");
	max = MB_CUR_MAX;
	printf("max = %d\n", max);
/*
	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';

	printf("\n\nprintf : ->\n");
	ret = printf("%.ls", s);
	printf("|\nft_printf : ->\n");
	retft = ft_printf("%.ls", s);
	printf("|\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
*/
	printf("\n\nprintf : |\n");
	ret = printf("%s", NULL);
	printf("|\nft_printf : |\n");
	retft = ft_printf("%s", NULL);
	printf("|\n---> ret = %d ; retft = %d <---\n\n", ret, retft);

	return (0);
}
