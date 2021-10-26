/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:28:40 by mberger-          #+#    #+#             */
/*   Updated: 2021/10/20 14:28:41 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_malloc_splits(char ***splits, const char *s, char c)
{
	int	size;
	int	i;

	size = 1;
	i = -1;
	while (s[++i])
		if (s[i] != c && size++)
			while (s[i] && s[++i] != c)
				;
	*splits = malloc(size * sizeof(char *));
	return (*splits == NULL);
}

static int	ft_split_free(char **splits, int n)
{
	while (n--)
		free(splits[n]);
	free(splits);
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char			**out;
	unsigned int	size;
	unsigned int	n;

	if (ft_malloc_splits(&out, s, c))
		return (NULL);
	n = 0;
	while (*s)
	{
		if (*s++ != c)
		{
			size = 1;
			while (*s && *s != c && size++)
				s++;
			out[n] = malloc(size + 1);
			if (out[n] == NULL && ft_split_free(out, n))
				return (NULL);
			ft_strlcpy(out[n++], s - size, size + 1);
		}
	}
	out[n] = NULL;
	return (out);
}
