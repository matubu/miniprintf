/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 09:47:27 by mberger-          #+#    #+#             */
/*   Updated: 2021/10/26 09:47:36 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_repeat(int *len, char c, int count)
{
	while (count-- > 0)
		*len += write(1, &c, 1);
}

//OK: left spaces padding
//OK: zero padding
//FIXME: right spaces
int	ft_printf_n(char *bef, char *str, int n, t_printf_opt *opt)
{
	int	len;
	int	blen;

	len = 0;
	blen = 0;
	if (bef)
		blen = ft_strlen(bef);
	//if (opt->flags & PRINTF_FLAG_ALTR && opt->width > opt->length)
	//	ft_printf_repeat(&len, ' ', opt->width - n - blen - 1);
	//else if (opt->flags & PRINTF_FLAG_ZERO && opt->width > opt->length && opt->width > 0 && opt->length >= 0)
	//	ft_printf_repeat(&len, ' ', opt->width - opt->length - blen);
	if (!(opt->flags & (PRINTF_FLAG_ZERO | PRINTF_FLAG_LEFT))
		|| (opt->flags & PRINTF_FLAG_ZERO && opt->width > opt->length && opt->width > 0 && opt->length > 0))
		ft_printf_repeat(&len, ' ', opt->width - blen - ft_max(n, opt->length));
	if (bef)
		len += write(1, bef, blen);
	if (opt->length > 0)
		ft_printf_repeat(&len, '0', opt->length - n);
	else if (opt->flags & PRINTF_FLAG_ZERO)
		ft_printf_repeat(&len, "0 "[str == NULL], opt->width - (n + blen));
	len += write(1, str, n);
	if (opt->flags & PRINTF_FLAG_LEFT)
		ft_printf_repeat(&len, ' ', opt->width - len);
	return (len);
}

int	ft_printf_s(char *str, int n, t_printf_opt *opt)
{
	int	len;

	len = 0;
	if (opt->length >= 0)
		n = ft_min(n, opt->length);
	if (!(opt->flags & PRINTF_FLAG_LEFT))
		ft_printf_repeat(&len, ' ', opt->width - n);
	len += write(1, str, n);
	if (opt->flags & PRINTF_FLAG_LEFT)
		ft_printf_repeat(&len, ' ', opt->width - n);
	return (len);
}