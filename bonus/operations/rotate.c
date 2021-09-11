/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 01:22:24 by rsanchez          #+#    #+#             */
/*   Updated: 2021/09/11 02:41:49 by rsanchez         ###   ########.fr       */
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
	else
		write(1, "ra: not supposed to happen\n", 27);
}

void	rotate_b(t_stacks *stacks)
{
	if (stacks->size_b > 1)
	{
		apply_rotate(&(stacks->b), stacks->last_b);
		stacks->last_b = stacks->last_b->next;
	}
	else
		write(1, "rb: not supposed to happen\n", 27);
}

void	rotate_rr(t_stacks *stacks)
{
	int	check;

	check = 0;
	if (stacks->size_a > 1 && ++check)
	{
		apply_rotate(&(stacks->a), stacks->last_a);
		stacks->last_a = stacks->last_a->next;
	}
	if (stacks->size_b > 1)
	{
		apply_rotate(&(stacks->b), stacks->last_b);
		stacks->last_b = stacks->last_b->next;
		check += 2;
	}
	if (check != 3)
		write(1, "rr: not supposed to happen\n", 27);
}
