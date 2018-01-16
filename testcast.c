/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testcast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:25:16 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/16 17:31:17 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main ()
{
	intmax_t	im;

	im = 2147483647;
	im = 32769;
	printf("(intmax_t) = %jd\n", im);
	im = (short)im;
	printf("(short int) = %jd\n", im);
	return (1);
}
