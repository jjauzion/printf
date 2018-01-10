/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 14:06:44 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/10 18:51:05 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFIER_H
# define SPECIFIER_H 

t_type g_type[] =
{
	{"bdiuf", int_arg},
	{"oxX", int_base_arg},
	{ "s", s_arg },
	{ "cC", c_arg },
/*	{ "DOU", dou_arg },
	{ "S", ws_arg },
	{ "p", p_arg },
*/	{ "%", pct_arg }
};

#endif
