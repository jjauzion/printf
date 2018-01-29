/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_current.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:27:43 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/29 13:04:30 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_print_buff(char *buff, int *index)
{

	if (!buff)
		return ;
	buff[*index + 1] = '\0';
	ft_putstr(buff);
	*index = 0;
	buff[0] = '\0';
}

static int	ft_copy2buff(char *buff, int *index, char *src)
{
	size_t	i;
	int		ret;

	ret = 0;
	i = -1;
	while (src[++i])
	{
		buff[*index] = src[i];
		ret++;
		if (buff[*index] == '\n' || *index >= BUFF_SIZE)
			ft_print_buff(buff, index);
		else
			(*index)++;
	}
	buff[*index] = '\0';
	return (ret);
}

int		ft_print_current(char *plain_str, t_spec *spec, int ret)
{
	static char	*buff;
	static int	index;

	if (!buff)
		buff = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buff || ret < 0)
		return (-1);
	ret += ft_copy2buff(buff, &index, plain_str);
	if (!spec)
		return (ret);
	if (ft_strchr("cC", spec->c_specifier) && ft_strchr(spec->attribute, '-'))
	{
		ft_print_buff(buff, &index);
		ret += ft_putwchar(spec->v_char);
	}
	ret += ft_copy2buff(buff, &index, spec->field);
	if (ft_strchr("cC", spec->c_specifier) && !ft_strchr(spec->attribute, '-'))
	{
		ft_print_buff(buff, &index);
		ret += ft_putwchar(spec->v_char);
	}
	return (ret);
}
