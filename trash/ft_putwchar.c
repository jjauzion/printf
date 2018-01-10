/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 18:51:15 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/10 18:32:22 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "locale.h"

int			ft_count_bit(int var)
{
	int		count;

	count = 0;
	while (var)
	{
		var = var >> 1;
		count++;
	}
	return (count);
}

int			ft_bit2oct(int nb)
{
	if (nb <= 7)
		return (1);
	if (nb <= 11)
		return (2);
	if (nb <= 16)
		return (3);
	return (4);
}

void		ft_apply_mask(unsigned int c, unsigned char *wc, int nb_octet)
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

void		ft_putwchar(unsigned int c)
{
	int				active_bit;
	int				nb_octet;
	unsigned char	*wc;
	int				i;

	if (!(wc = (unsigned char*)malloc(sizeof(char) * 4)))
		return ;
	i = 0;
	while (++i < 4)
		wc[i] = '\0';
ft_putstr("\n+++++++++++++\n");
ft_putstr("c = ");
ft_putnbr(c);
ft_putstr("\n");
ft_putstr("wc[3] = ");
ft_putnbr(wc[3]);
ft_putstr("\n");
ft_putstr("wc[2] = ");
ft_putnbr(wc[2]);
ft_putstr("\n");
ft_putstr("wc[1] = ");
ft_putnbr(wc[1]);
ft_putstr("\n");
ft_putstr("wc[0] = ");
ft_putnbr(wc[0]);
ft_putstr("\n------------\n");
	setlocale(LC_ALL, "en_US.UTF-8");
	active_bit = ft_count_bit(c);
	nb_octet = ft_bit2oct(active_bit);
	if (nb_octet == 1)
	{
		write(1, &c, 1);
		return ;
	}
	ft_apply_mask(c, wc, nb_octet);
ft_putstr("\n>>>>>>>>>>>>>\n");
ft_putstr("c = ");
ft_putnbr(c);
ft_putstr("\n");
ft_putstr("wc[3] = ");
ft_putnbr(wc[3]);
ft_putstr("\n");
ft_putstr("wc[2] = ");
ft_putnbr(wc[2]);
ft_putstr("\n");
ft_putstr("wc[1] = ");
ft_putnbr(wc[1]);
ft_putstr("\n");
ft_putstr("wc[0] = ");
ft_putnbr(wc[0]);
ft_putstr("\n<<<<<<<<<<<<\n");
	i = 4;
	while (--i >= 0)
		write(1, &(wc[i]), 1);
	free(wc);
}

int main ()
{
	setlocale(LC_ALL, "en_US.UTF-8");

	ft_putwchar(0x1D11E);
	ft_putwchar(0x007E);
	ft_putwchar(0x03B1);
	ft_putwchar(0x00E9);
	ft_putwchar(0x20AC);
	ft_putwchar(L'我');
	ft_putstr("\n");
}
