/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:30:02 by mberger-          #+#    #+#             */
/*   Updated: 2021/10/20 14:30:03 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	char	*cpy;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (s_len - start < len)
		len = s_len - start;
	out = malloc(len + 1);
	if (out == NULL)
		return (NULL);
	s += start;
	cpy = out;
	while (len-- && *s)
		*cpy++ = *s++;
	*cpy = '\0';
	return (out);
}
