/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 10:24:24 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/29 10:49:43 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

int		main()
{
	int		ret;
	int		retft;

	setlocale(LC_ALL, "");
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

	printf("\n--> Test 4 : couleur\n");
	retft = ft_printf("4.1 : force {blue}bleu{eoc} force {red}rouge{eoc} voilou :)\n");
	printf("retft = %d\n", retft);
	retft = ft_printf("4.2 : {yellow}%s{eoc}\n", "yellow");
	printf("retft = %d\n", retft);
	retft = ft_printf("4.3 : {green}%s puis |%*.3d|{eoc} voilou :)\n", "green", 5, 5);
	printf("retft = %d\n", retft);
	retft = ft_printf("4.4 : {greeen}%s puis |%*.3d|{eOc} voilou :)\n", "green", 5, 5);
	printf("retft = %d\n", retft);
	retft = ft_printf("4.5 : {eoc}{eoc} voilou :)\n");
	printf("retft = %d\n", retft);
	retft = ft_printf("4.6 : {red}{green} voilou{yellow}{eoc} :)\n");
	printf("retft = %d\n", retft);
	retft = ft_printf("4.7 : {red}{green}%.*s%lc%d{eoc} voilou :)\n", 2, "12345", L'米', 5);
	printf("retft = %d\n", retft);
	retft = ft_printf("4.8 : {{{{%.*s%lc%d{{ }}}%d{{magenta}voilou{eoc}} :)\n", 1, "12", L'米', 5, 0);
	printf("retft = %d\n", retft);
	retft = ft_printf("4.9 : ");
	retft += ft_printf("{eoc}");
	retft += ft_printf("\n");
	printf("retft = %d\n", retft);
	retft = ft_printf("4.10 : vide apres ca ret 0 attendu -->");
	retft = ft_printf("");
	printf("\nretft = %d\n", retft);


	while (1)
	{}
}
