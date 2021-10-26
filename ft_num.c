/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:47:45 by mberger-          #+#    #+#             */
/*   Updated: 2021/10/25 13:50:49 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_uint(char *bef, unsigned int n, t_printf_opt *opt)
{
	int		i;
	char	buf[11];

	i = 11;
	while (1)
	{
		buf[--i] = n % 10 + '0';
		n /= 10;
		if (!n)
			break ;
	}
	if (opt->length == 0 && buf[i] == '0')
		return (ft_printf_n(bef, NULL, 0, opt));
	return (ft_printf_n(bef, buf + i, 11 - i, opt));
}

int	ft_printf_int(int nb, t_printf_opt *opt)
{
	if (nb < 0)
		return (ft_printf_uint("-", -nb, opt));
	else if (opt->flags & PRINTF_FLAG_PLUS)
		return (ft_printf_uint("+", nb, opt));
	else if (opt->flags & PRINTF_FLAG_SPAC)
		return (ft_printf_uint(" ", nb, opt));
	return (ft_printf_uint(NULL, nb, opt));
}

int	ft_printf_base16(unsigned long n, char *base, t_printf_opt *opt)
{
	char			buf[10];
	int				i;
	unsigned long	nb;

	i = 10;
	nb = n;
	while (1)
	{
		buf[--i] = base[n % 16];
		n /= 16;
		if (!n)
			break ;
	}
	if (opt->length == 0 && nb == 0)
		return (ft_printf_n(NULL, NULL, 0, opt));
	if (opt->flags & PRINTF_FLAG_ALTR && nb)
		return (ft_printf_n(base + 16, buf + i, 10 - i, opt));
	return (ft_printf_n(NULL, buf + i, 10 - i, opt));
}

int	ft_printf_ptr(unsigned long long n, char *base, t_printf_opt *opt)
{
	char	buf[21];
	int		i;

	i = 21;
	while (1)
	{
		buf[--i] = base[n % 16];
		n /= 16;
		if (!n)
			break ;
	}
	return (ft_printf_n("0x", buf + i, 21 - i, opt));
}
