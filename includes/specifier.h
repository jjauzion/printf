/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 14:06:44 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/17 11:50:16 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFIER_H
# define SPECIFIER_H 

t_type g_type[] =
{
	{ "di", ft_int_arg},
	{ "ouxXDOU", ft_uint_arg},
	{ "S", ft_wstr_arg},
	{ "s", ft_str_arg},
	{ "c", ft_char_arg},
	{ "C", ft_wchar_arg},
	{ "f", ft_float_arg },
//	{ "p", p_arg },
	{ "%", ft_pct_arg},
	{ " ", ft_usage}
};

#endif
