/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 18:51:15 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/13 19:33:17 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_apply_mask(wchar_t c, unsigned char *wc, int nb_octet)
{
	int		i;

	i = -1;
	while (++i < nb_octet - 1)
	{
		wc[i] = 0x80 | (c & 0x3F);
		c = c >> 6;
	}
	if (nb_octet == 2)
		wc[1] = 0xC0 | (c & 0x1F);
	if (nb_octet == 3)
		wc[2] = 0xE0 | (c & 0xF);
	if (nb_octet == 4)
		wc[3] = 0xF0 | (c & 0x7);
}

void		ft_putwchar(wchar_t c)
{
	int				nb_octet;
	unsigned char	*wc;
	int				i;

	if (!(wc = (unsigned char*)malloc(sizeof(char) * 4)))
		return ;
	i = 0;
	while (++i < 4)
		wc[i] = '\0';
	setlocale(LC_ALL, "en_US.UTF-8");
	nb_octet = ft_getnbofutf8byte(c);
	if (nb_octet == 1)
	{
		write(1, &c, 1);
		return ;
	}
	ft_apply_mask(c, wc, nb_octet);
	i = 4;
	while (--i >= 0)
		write(1, &(wc[i]), 1);
	free(wc);
}
