/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:37:24 by rsanchez          #+#    #+#             */
/*   Updated: 2021/09/02 17:17:47 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

BOOL	is_sorted_inc(t_list2 *stack, int size, t_list2 *locked, t_list2 *last)
{
	int	max;

	max = size - 1;
	if (last->group == -1)
		max = locked->index;
	while (stack->next && stack->group > -1)
	{
		if (stack->index + 1 == stack->next->index)
			stack = stack->next;
		else
			return (FALSE);
	}
	if (stack->index != max)
		return (FALSE);
	return (TRUE);
}

/*
BOOL	is_sortable(t_list *stack, int max_index)
{
	int	i;

	i = 0;
	while (stack && stack->group > -1)
	{
		if (i >= 5)
		{
			if (is_sorted_increas(stack, max_index))
				return (TRUE);
			else
				return (FALSE);
		}
		i++;
		stack = stack->next;
	}
	return (TRUE);
}
*/

t_list2	*lock_sorted(t_list2 *stack, int size, t_list2 *locked, t_list2 *last)
{
	int	max;

	max = size - 1;
	if (last->group == -1)
		max = locked->index;
	while (stack->next && stack->group > -1)
	{
		if (is_sorted_inc(stack, size, locked, last))
		{
			set_group(stack, -1);
			return (stack);
		}
		stack = stack->next;
	}
	if (!stack->next && stack->index == max)
	{
		stack->group = -1;
		return (stack);
	}
	return (locked);
}

void	back_to_bot(t_stacks *stacks, int group, char c)
{
	if (c == 'a')
	{
		while (stacks->last_a->group != group)
			rev_rotate_a(stacks);
	}
	else
	{
		while (stacks->last_b->group != group)
			rev_rotate_b(stacks);
	}
}

/*
void	back_to_bot(t_stacks *stacks, t_list2 *stack, int group, char c)
{
	BOOL	reached;
	int	dir;

	reached = -1;
	dir = 0;
	while (stack)
	{
		if (reached == -1 && stack->group == group)
			reached = FALSE;
		else if (reached == FALSE && stack->group != group)
		{
			reached = TRUE;
			dir--;
		}
		else if (reached == TRUE)
			dir--;
		stack = stack->next;
	}
	if (c == 'a')
		move_rotate(stacks, dir, &rotate_a, &rev_rotate_a);
	else
		move_rotate(stacks, dir, &rotate_b, &rev_rotate_b);
}
*/
