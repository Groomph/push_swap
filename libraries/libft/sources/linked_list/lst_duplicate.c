/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_duplicate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 22:05:40 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/26 17:23:40 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*lst_duplicate(t_list *original)
{
	t_list	*new;
	t_list	*first;

	first = NULL;
	while (original)
	{
		new = malloc(sizeof(t_list));
		if (!new)
		{
			ft_lstclear(&first, &free);
			return (NULL);
		}
		new->nb = original->nb;
		new->index = original->index;
		new->group = 0;
		ft_lstadd_back(&first, new);
		original = original->next;
	}
	return (first);
}
