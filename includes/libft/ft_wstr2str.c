/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr2str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:59:43 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/13 22:14:00 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Convert a wchar_t *str to a char *str formatted according to UTF8 standard.
**	The function allocate a fresh string and returned a pointer to this string.
*/

#include "libft.h"

char	*ft_wstr2str(wchar_t *src)
{
	char	*ret;
	char	*tmp;

	tmp = ft_strnew(0);
	if (!src || !tmp)
		return (NULL);
	ret = NULL;
	while (*src)
	{
		ret = ft_strjoin(tmp, ft_uni2utf8(*src));
		free(tmp);
		tmp = ret;
		src++;
	}
	return (ret);
}
