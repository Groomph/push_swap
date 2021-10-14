/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 01:21:50 by rsanchez          #+#    #+#             */
/*   Updated: 2021/10/14 16:26:48 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	apply_swap(t_list2 **stack)
{
	t_list2	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
	(*stack)->prev = NULL;
	if (tmp->next)
		tmp->next->prev = tmp;
}

void	swap_a(t_stacks *stacks)
{
	if (stacks->size_a > 1)
	{
		if (stacks->size_a == 2)
			stacks->last_a = stacks->a;
		apply_swap(&(stacks->a));
	}
}

void	swap_b(t_stacks *stacks)
{
	if (stacks->size_b > 1)
	{
		if (stacks->size_b == 2)
			stacks->last_b = stacks->b;
		apply_swap(&(stacks->b));
	}
}

void	swap_ss(t_stacks *stacks)
{
	if (stacks->size_a > 1)
	{
		if (stacks->size_a == 2)
			stacks->last_a = stacks->a;
		apply_swap(&(stacks->a));
	}
	if (stacks->size_b > 1)
	{
		if (stacks->size_b == 2)
			stacks->last_b = stacks->b;
		apply_swap(&(stacks->b));
	}
}
