/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:27:19 by mberger-          #+#    #+#             */
/*   Updated: 2021/10/20 14:27:20 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*cp;

	if (n == 0 || dest == src)
		return (dest);
	if (src < dest)
	{
		while (n--)
			((char *)dest)[n] = ((char *)src)[n];
		return (dest);
	}
	cp = dest;
	while (n--)
		*(char *)dest++ = *(char *)src++;
	return (cp);
}
