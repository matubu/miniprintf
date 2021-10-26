/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:28:59 by mberger-          #+#    #+#             */
/*   Updated: 2021/10/20 14:28:59 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*out;
	size_t	i;

	i = ft_strlen(s);
	out = (char *)malloc(i + 1);
	if (out == NULL)
		return (NULL);
	out[i] = '\0';
	while (i--)
		out[i] = s[i];
	return (out);
}
