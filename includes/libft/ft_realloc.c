/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:25:20 by jjauzion          #+#    #+#             */
/*   Updated: 2017/12/19 20:09:23 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void		*ft_realloc(void **src, size_t len, size_t size)
{
	void	*dst;

	if (!(dst = ft_memalloc(len + size)))
		return (NULL);
	dst = ft_memcpy(dst, *src, len + 1);
	free(*src);
	*src = NULL;
	return (dst);
}
