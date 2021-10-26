/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:31:21 by mberger-          #+#    #+#             */
/*   Updated: 2021/10/20 14:31:22 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*out;
	int		len;

	if (!*s1)
		return (ft_strdup(s1));
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	if (len != 0)
	{
		while (ft_strchr(set, s1[--len]))
			;
		len++;
	}
	len++;
	out = malloc(len);
	if (out == NULL)
		return (NULL);
	ft_strlcpy(out, s1, len);
	return (out);
}
