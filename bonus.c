/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 10:24:24 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/23 15:22:40 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main()
{
	int		ret;
	int		retft;

	printf("\n--> Test 1 : precision *\n");
	ret = printf("1.1 %-12s|%.*d|\n", "printf :", 10, 2);
	retft = ft_printf("1.1 %-12s|%.*d|\n", "ft_printf :", 10, 2);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("1.2 %-12s|%-10.*d|\n", "printf :", 3, 2);
	retft = ft_printf("1.2 %-12s|%-10.*d|\n", "ft_printf :", 3, 2);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("1.3 %-12s|%-10.*d| ; |%s|\n", "printf :", 3, 2, "juste un check");
	retft = ft_printf("1.3 %-12s|%-10.*d| ; |%s|\n", "ft_printf :", 3, 2, "juste un check");
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("1.4 %-12s|%-10.*d| ; |%d| ; |%.*s| ; |%d|\n", "printf :", 3, 2, 1, 3, "12345", 5);
	retft = ft_printf("1.4 %-12s|%-10.*d| ; |%d| ; |%.*s| ; |%d|\n", "ft_printf :", 3, 2, 1, 3, "12345", 5);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);

	printf("\n--> Test 2 : width *\n");
	ret = printf("2.1 %-12s|%*d|\n", "printf :", 10, 2);
	retft = ft_printf("2.1 %-12s|%*d|\n", "ft_printf :", 10, 2);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("2.2 %-12s|%*.3d|\n", "printf :", 10, 2);
	retft = ft_printf("2.2 %-12s|%*.3d|\n", "ft_printf :", 10, 2);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("2.3 %-12s|%-0*.2d|\n", "printf :", 10, 2);
	retft = ft_printf("2.3 %-12s|%-0*.2d|\n", "ft_printf :", 10, 2);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("2.4 %-12s|%*.*d|\n", "printf :", 10, 2, 5);
	retft = ft_printf("2.4 %-12s|%*.*d|\n", "ft_printf :", 10, 2, 5);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("2.5 %-12s|%-*.*s| ; |%d|\n", "printf :", 10, 4, "123456", 5);
	retft = ft_printf("2.5 %-12s|%-*.*s| ; |%d|\n", "ft_printf :", 10, 4, "123456", 5);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);

	printf("\n--> Test 3 : modifier t\n");
	ret = printf("3.1 %-12s|%td|\n", "printf :", 10);
	retft = ft_printf("3.1 %-12s|%td|\n", "ft_printf :", 10);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
	ret = printf("3.2 %-12s|%td|\n", "printf :", -10);
	retft = ft_printf("3.2 %-12s|%td|\n", "ft_printf :", -10);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);

	printf("\n--> Test 4 : attribut '\n");
	ret = printf("4.1 %-12s|%'.3f|\n", "printf :", 2147483.647);
	retft = ft_printf("4.1 %-12s|%'.3f|\n", "ft_printf :", 2147483.647);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);

	printf("\n--> Test 5 : attribut '\n");
	ret = printf("5.1 %-12s|%'.3f|\n", "printf :", 2147483.647);
	retft = ft_printf("5.1 %-12s|%td|\n", "ft_printf :", 10);
	if (ret != retft)
		printf("\n/!\\ Erreur Valeur retour !! /!\\\n---> ret = %d ; retft = %d <---\n\n", ret, retft);
/*
	ft_printf("couleur {blue}bleu{eoc} couleur {red}rouge{eoc} voilou :)\n");

	char *test;
	test = ft_strdup("{red}");
	ft_color(&test);
	ft_putstr("ouuuuuuuiii\n");
	test = ft_strdup("{eoc}");
	ft_color(&test);
	ft_putstr("test0");
	ft_putstr("\x1b[32mtest1\033[0m");
	ft_putstr("test2");
	ft_putstr("\x1b[93;41m");
	ft_putstr("test3");
	ft_putstr("test4");
	ft_putstr("\033[0m");
	ft_putstr("test5");
	printf("\n\n*------------*\n");
	printf("aa\x1b[94myolo\x1b[0mbb\n");
	ft_printf("aa\x1b[94myolo\x1b[0mbb\n");
*/
}
