/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:21:23 by mberger-          #+#    #+#             */
/*   Updated: 2021/11/04 11:27:00 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf_opt	ft_printf_parse_opt(const char **s)
{
	t_printf_opt	opt;

	(void)s;
	opt = ft_printf_init_opt();
	return (opt);
}
