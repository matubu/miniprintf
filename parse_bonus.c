/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:21:23 by mberger-          #+#    #+#             */
/*   Updated: 2021/11/04 11:21:32 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf_opt	ft_printf_parse_opt(const char **s)
{
	t_printf_opt	opt;

	opt = ft_printf_init_opt();
	while (1)
	{
		if (**s == '#')
			opt.flags |= PRINTF_FLAG_ALTR;
		else if (**s == '+')
			opt.flags |= PRINTF_FLAG_PLUS;
		else if (**s == ' ')
			opt.flags |= PRINTF_FLAG_SPAC;
		else if (**s == '-')
			opt.flags |= PRINTF_FLAG_LEFT;
		else if (**s == '0')
			opt.flags |= PRINTF_FLAG_ZERO;
		else
			break ;
		(*s)++;
	}
	while (ft_isdigit(**s))
		opt.width = opt.width * 10 + *(*s)++ - '0';
	if (**s == '.' && (*s)++ && opt.length++)
		while (ft_isdigit(**s))
			opt.length = opt.length * 10 + *(*s)++ - '0';
	return (opt);
}
