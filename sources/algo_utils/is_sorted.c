/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:37:24 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/26 18:37:55 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

BOOL	 is_sorted_increas(t_list *stack, int max)
{
	while (stack->next && stack->group > -1)
	{
		if (stack->index == stack->next->index - 1)
			stack = stack->next;
		else
			return (FALSE);
	}
	if (!(stack->next) && stack->index != max)
		return (FALSE);
	return (TRUE);
}

BOOL	is_sortable(t_list *stack, int max)
{
	int	i;

	i = 0;
	while (stack && stack->group > -1)
	{
		if (i > 1)
		{
			if (is_sorted_increas(stack, max))
			{
				return (TRUE);
			}
			else
				return (FALSE);
		}
		i++;
		stack = stack->next;
	}
	return (TRUE);
}
