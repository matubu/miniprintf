/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:39:03 by mberger-          #+#    #+#             */
/*   Updated: 2021/10/19 16:28:35 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		pow;
	char	*out;
	int		p;
	int		neg;

	neg = 1;
	if (n >= 0 && neg--)
		n = -n;
	pow = 1;
	p = n;
	while (p < -9 && ++pow)
		p /= 10;
	out = malloc(pow + neg + 1);
	if (out == NULL)
		return (NULL);
	out[pow + neg] = '\0';
	while (pow--)
	{
		out[pow + neg] = '0' - n % 10;
		n /= 10;
	}
	if (neg)
		*out = '-';
	return (out);
}
