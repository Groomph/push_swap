/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 01:22:24 by rsanchez          #+#    #+#             */
/*   Updated: 2021/10/14 16:27:07 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	apply_rotate(t_list2 **stack, t_list2 *last)
{
	t_list2	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	lst2_addback(stack, tmp, last);
}

void	rotate_a(t_stacks *stacks)
{
	if (stacks->size_a > 1)
	{
		apply_rotate(&(stacks->a), stacks->last_a);
		stacks->last_a = stacks->last_a->next;
	}
}

void	rotate_b(t_stacks *stacks)
{
	if (stacks->size_b > 1)
	{
		apply_rotate(&(stacks->b), stacks->last_b);
		stacks->last_b = stacks->last_b->next;
	}
}

void	rotate_rr(t_stacks *stacks)
{
	if (stacks->size_a > 1)
	{
		apply_rotate(&(stacks->a), stacks->last_a);
		stacks->last_a = stacks->last_a->next;
	}
	if (stacks->size_b > 1)
	{
		apply_rotate(&(stacks->b), stacks->last_b);
		stacks->last_b = stacks->last_b->next;
	}
}
