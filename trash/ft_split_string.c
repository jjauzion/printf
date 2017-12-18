/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:20:03 by jjauzion          #+#    #+#             */
/*   Updated: 2017/12/16 19:09:11 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_add_char_chain(char *str, int i, char *buf, t_chain **lst)
{
	int		j;

	j = 0;
	while (str[i] != 92 && str[i] != '%' && str[i])
	{
/*ft_putendl("//////////////////////");
ft_putstr("i : ");
ft_putendl(ft_itoa(i));
ft_putstr("str : ");
ft_putchar(str[i]);
ft_putendl("");
ft_putendl("\\\\\\\\\\\\\\\\\\\\\\");
*/		buf[j] = str[i];
		j++;
		i++;
	}
	buf[i] = '\0';
	if (!(*lst = ft_add_elm(buf, 0, *lst)))
		return (-1);
	return (i);
}

int			ft_add_convert_spe(char *str, int i, char *buf, t_chain **lst)
{
	int		j;
	char	*valid;

	buf[0] = '%';
	valid = ft_strdup("sSpdDioOuUxXcCeEfFgGaAn%");
	i++;
	j = 0;
	while (valid[j])
	{
		j++;
		if (str[i] == valid[j])
		{
			buf[1] = valid[j];
			buf[2] = '\0';
			if (!(*lst = ft_add_elm(buf, 1, *lst)))
				return (-1);
			return (i);
		}
	}
	if (str[i] >= 0 && str[i] < 8)
		return (-1);
	j = 0;
	while (str[i] >= 0 && str[i] < 8 && j < 3)
	{
		buf[j] = str[i];
		i++;
		j++;
	}
	if (!(*lst = ft_add_elm(buf, 1, *lst)))
		return (-1);
	return (i);
}

t_chain		*ft_split_string(char *str)
{
	int		i;
	char	*buf;
	t_chain	*lst;
	
	lst = NULL;
	if (!(buf = (char *)malloc(sizeof(char) * ft_strlen(str))))
		return (NULL);
	i = 0;
	while (str[i])
	{
/*ft_putendl(">-----------------------");
ft_putstr("i : ");
ft_putendl(ft_itoa(i));
ft_putstr("str : ");
ft_putchar(str[i]);
ft_putendl("");
*/
		if (str[i] != '%' && str[i])
			i = ft_add_char_chain(str, i, buf, &lst);
		if (i < 0)
			return (NULL);
/*ft_putstr("i : ");
ft_putendl(ft_itoa(i));
ft_putstr("str : ");
ft_putchar(str[i]);
ft_putendl("");
ft_putendl("-----------------------<");
*/
//		if (str[i] == 92)
//			i = ft_add_esc_seq(str, i, buf, &lst);
		if (i < 0)
			return (NULL);
//		if (str[i] == '%')
//			i = ft_add_conver_spec(str, i, buf, &lst);
		if (i < 0)
			return (NULL);
	}
	return (lst);
}
