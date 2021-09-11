/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 01:22:09 by rsanchez          #+#    #+#             */
/*   Updated: 2021/09/11 02:41:25 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	apply_push(t_list2 **stack, t_list2 **stack2)
{
	t_list2	*tmp;

	tmp = *stack;
	*stack = *stack2;
	*stack2 = (*stack2)->next;
	if (*stack2)
		(*stack2)->prev = NULL;
	(*stack)->next = tmp;
	(*stack)->prev = NULL;
	if (tmp)
		tmp->prev = *stack;
}

void	push_a(t_stacks *stacks)
{
	if (stacks->size_b > 0)
	{
		apply_push(&(stacks->a), &(stacks->b));
		stacks->size_a++;
		stacks->size_b--;
		if (stacks->size_b == 0)
			stacks->last_b = NULL;
		if (!stacks->last_a)
			stacks->last_a = stacks->a;
	}
	else
		write(1, "pa: not supposed to happen\n", 27);
}

void	push_b(t_stacks *stacks)
{
	if (stacks->size_a > 0)
	{
		apply_push(&(stacks->b), &(stacks->a));
		stacks->size_a--;
		stacks->size_b++;
		if (stacks->size_a == 0)
			stacks->last_a = NULL;
		if (!stacks->last_b)
			stacks->last_b = stacks->b;
	}
	else
		write(1, "pb: not supposed to happen\n", 27);
}
