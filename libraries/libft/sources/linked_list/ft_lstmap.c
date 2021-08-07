/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:57:16 by rsanchez          #+#    #+#             */
/*   Updated: 2021/07/25 14:07:30 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	newobject_null(t_list **first, void (*del)(void *))
{
	if (del)
		ft_lstclear(first, del);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;
	void	*new_object;

	first = NULL;
	while (lst && f)
	{
		new_object = f(lst->object);
		if (!new_object)
		{
			newobject_null(&first, del);
			return (NULL);
		}
		new = ft_lstnew(new_object);
		if (!new && del)
		{
			ft_lstclear(&first, del);
			del(new_object);
		}
		if (!new)
			return (NULL);
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}
