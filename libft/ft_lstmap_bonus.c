/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:25:54 by mberger-          #+#    #+#             */
/*   Updated: 2021/10/20 14:25:55 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out;
	void	*content;

	if (lst == NULL)
		return (NULL);
	content = f(lst->content);
	out = ft_lstnew(content);
	if (out == NULL)
	{
		del(content);
		return (NULL);
	}
	if (lst->next == NULL)
	{
		out->next = NULL;
		return (out);
	}
	out->next = ft_lstmap(lst->next, f, del);
	if (out->next == NULL)
	{
		ft_lstdelone(out, del);
		return (NULL);
	}
	return (out);
}
