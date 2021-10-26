/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:28:22 by mberger-          #+#    #+#             */
/*   Updated: 2021/10/26 10:03:05 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int			i;
	static char	res[10];

	if (n < 0)
		write(fd, "-", 1);
	else
		n = -n;
	i = 10;
	while (1)
	{
		res[--i] = '0' - n % 10;
		n /= 10;
		if (!n)
			break ;
	}
	write(fd, res + i, 10 - i);
}