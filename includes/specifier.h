/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 14:06:44 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/15 15:44:52 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFIER_H
# define SPECIFIER_H 

t_type g_type[] =
{
	{ "diu", int_arg},
	{ "oxX", int_base_arg},
	{ "sc", sc_arg },
	{ "SC", wSC_arg },
	{ "f", float_arg },
/*	{ "DOU", dou_arg },
	{ "p", p_arg },
*/	{ "%", pct_arg},
	{ " ", usage}
};

#endif
