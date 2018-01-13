/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 18:42:24 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/13 22:27:20 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		main(void)
{
	wchar_t	*str;
	int		c;
	int		i;
	char	*test;

	ft_putwstr(L"test \x3B1 ok\n");
	ft_putwstr(L"我是一只猫。\n");
	str = ft_wstrdup(L"u我2αi");
	ft_putwstr(str);
	ft_putstr("\n");
	test = ft_wstr2str(str);
	ft_putstr("test str = ");
	ft_putstr(test);
	ft_putstr("\n");
	ft_putstr("len(test) = ");
	ft_putnbr(ft_strlen(test));
	ft_putstr("\n");

	while (*test)
	{
		i = *test;
		ft_putstr("i = ");
		ft_putnbr(i);
		ft_putstr(" = |");
		ft_putchar(i);
		ft_putstr("|\n");
		test++;
	}

	ft_putstr("------------------------\n");
	c = 85;
	write(1, &c, 1);
	c = 206;
	write(1, &c, 1);
/*	c = 177;
	write(1, &c, 1);*/
	ft_putstr("\n");
}
