/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 19:54:28 by jjauzion          #+#    #+#             */
/*   Updated: 2017/12/20 20:35:46 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_get_sign(char *arg, t_spec spec)
{
	char	sign;

	sign = '\0';
	if (ft_strchr(spec.attribute, ' '))
		sign = ' ';
	if (ft_strchr(spec.attribute, '+'))
		sign = '+';
	if (arg[0] == '-')
		sign = '-';
	return (sign);
}

void	ft_shift_string(char *arg, char c, char option, int width)
{
	int		len;
	int		i;

	if (!arg)
		return ;
	if (!(len = ft_strlen(arg)))
		return ;
	if (option == 'r')
	{
		while (--width)
			arg[width] = arg[width - 1];
		arg[0] = c;
	}
	if (option == 'l')
	{
		i = -1;
		while (++i < len - 1)
			arg[i] = arg[i + 1];
		arg[len - 1] = c;
	}
}

void	ft_apply_sign(char *arg, char sign, int width)
{
	int		i;

	if (!sign)
		return ;
	i = 0;
	while (!ft_isdigit(arg[i]) && arg[i])
		i++;
	if (i == 0)
		ft_shift_string(arg, sign, 'r', width);
	else
		arg[i - 1] = sign;
}

int		ft_width(char *arg, t_spec spec, char sign)
{
	int		len;

	len = ft_strlen(arg);
	len = (sign) ? len + 1 : len;
	if (spec.width > len)
		return (spec.width);
	else
		return (len);
}

void	ft_padding(char *arg, char option, char sign, int width)
{
	int		len;
	char	c;
	int		nb2pad;

	if (!arg || !(option == ' ' || option == '0' || option == '-'))
		return ;
	len = ft_strlen(arg);
	c = (option == '-') ? ' ' : option;
	nb2pad = width;
	if (option != '-')
	{
		if (option == '0')
			nb2pad = (sign) ? nb2pad - 1 : nb2pad;
		arg = ft_strrev(arg);
	}
	while (len < nb2pad)
		arg[len++] = c;
	if (option != '-')
		arg = ft_strrev(arg);
	ft_apply_sign(arg, sign, width);
}

char	*ft_generate_field(char **arg, t_spec spec)
{
	int		len;
	char	sign;
	int		width;

	len = ft_strlen(*arg);
	sign = ft_get_sign(*arg, spec);
	if (sign == '-')
		ft_shift_string(*arg, '\0', 'l', 0);
	width = ft_width(*arg, spec, sign);
	if (!(*arg = (char *)ft_realloc((void **)arg, len, width - len + 1)))
		return (NULL);
	if (ft_strchr(spec.attribute, '-'))
		ft_padding(*arg, '-', sign, width);
	else if (ft_strchr(spec.attribute, '0'))
		ft_padding(*arg, '0', sign, width);
	else
		ft_padding(*arg, ' ', sign, width);
	return (*arg);
}
