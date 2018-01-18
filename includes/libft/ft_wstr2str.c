/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr2str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:59:43 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/18 19:32:13 by jjauzion         ###   ########.fr       */
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
	char	*ctmp;

	tmp = ft_strnew(0);
	if (!src || !tmp)
		return (NULL);
	if (!*src)
		return (tmp);
	while (*src)
	{
		ctmp = ft_uni2utf8(*src);
		ret = ft_strjoin(tmp, ctmp);
		free(ctmp);
		free(tmp);
		tmp = ret;
		src++;
	}
	return (ret);
}
