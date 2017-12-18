/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_elm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:44:19 by jjauzion          #+#    #+#             */
/*   Updated: 2017/12/15 19:15:17 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_chain		*ft_add_elm(char *str, int type, t_chain *lst)
{
	t_chain	*new_elm;
	t_chain	*tmp;

	if (!(new_elm = (t_chain *)malloc(sizeof(t_chain))))
		return (NULL);
	if (!(new_elm->str = ft_strdup(str)))
		return (NULL);
	new_elm->type = type;
	new_elm->next = NULL;
	if (!lst)
	{
		new_elm->id = 0;
		return (new_elm);
	}
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	new_elm->id = tmp->id + 1;
	tmp->next = new_elm;
	return (lst);
}
