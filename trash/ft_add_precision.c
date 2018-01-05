/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 13:07:39 by jjauzion          #+#    #+#             */
/*   Updated: 2017/12/20 16:27:46 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_precision(char **arg, t_spec spec)
{
	int		len;

	len = ft_strlen(*arg);
	if (len >= spec.precision)
		return (*arg);

}
