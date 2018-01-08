/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 18:51:15 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/08 20:42:27 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "locale.h"

int			ft_count_bit(unsigned int var)
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

void		ft_putwchar(unsigned int c)
{
	int				active_bit;
	int				nb_octet;
	unsigned char	*wc;

	if (!(wc = (unsigned char*)malloc(sizeof(char) * 4)))
		return ;
	setlocale(LC_ALL, "en_US.UTF-8");
	active_bit = ft_count_bit(c);
	nb_octet = ft_bit2oct(active_bit);
	if (nb_octet == 1)
		write(1, &c, 1);
	if (nb_octet == 2)
	{
		wc[0] = 0x80 | (c & 0x3F);
		wc[1] = 0xC0 | ((c >> 6) & 0x1F);
		write(1, &(wc[1]), 1);
		write(1, &(wc[0]), 1);
	}
	if (nb_octet == 3)
	{
		wc[0] = 0x80 | (c & 0x3F);
		wc[1] = 0x80 | ((c >> 6) & 0x3F);
		wc[2] = 0xE0 | ((c >> 6) & 0xF);
		write(1, &(wc[2]), 1);
		write(1, &(wc[1]), 1);
		write(1, &(wc[0]), 1);
	}
	if (nb_octet == 4)
	{
		wc[0] = 0x80 | (c & 0x3F);
		wc[1] = 0x80 | ((c >> 6) & 0x3F);
		wc[2] = 0x80 | ((c >> 6) & 0x3F);
		wc[3] = 0xF0 | ((c >> 6) & 0x7);
		write(1, &(wc[3]), 1);
		write(1, &(wc[2]), 1);
		write(1, &(wc[1]), 1);
		write(1, &(wc[0]), 1);
	}
}

int main ()
{
	ft_putwchar(0x007E);
	ft_putwchar(0x03B1);
	ft_putwchar(0x00E9);
	ft_putwchar(0x20AC);
	ft_putwchar(0x1D11E);
	ft_putstr("\n");
}



