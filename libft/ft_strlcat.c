/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:30:56 by mberger-          #+#    #+#             */
/*   Updated: 2021/10/20 14:30:57 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dlen;

	i = 0;
	while (dest[i] != '\0' && i != size)
		i++;
	dlen = i;
	if (size - i == 0)
		return (i + ft_strlen(src));
	j = 0;
	while (src[j] != '\0')
	{
		if (size - i != 1)
		{
			dest[i] = src[j];
			i++;
		}
		j++;
	}
	dest[i] = '\0';
	return (dlen + j);
}
