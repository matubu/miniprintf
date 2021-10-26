/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:48:14 by mberger-          #+#    #+#             */
/*   Updated: 2021/10/25 13:47:04 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(char *s, t_printf_opt *opt)
{
	if (s == NULL)
		return (ft_printf_s("(null)", 6, opt));
	return (ft_printf_s(s, ft_strlen(s), opt));
}

int	ft_printf_char(char c, t_printf_opt *opt)
{
	return (ft_printf_s(&c, 1, opt));
}
