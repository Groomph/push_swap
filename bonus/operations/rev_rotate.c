/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 01:22:24 by rsanchez          #+#    #+#             */
/*   Updated: 2021/09/11 02:42:22 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "buffer.h"
#include <unistd.h>

static void	apply_rev_rotate(t_list2 **stack, t_list2 *last)
{
	last->prev->next = NULL;
	lst2_addfront(stack, last);
}

void	rev_rotate_a(t_stacks *stacks)
{
	t_list2	*tmp;

	if (stacks->size_a > 1)
	{
		tmp = stacks->last_a->prev;
		apply_rev_rotate(&(stacks->a), stacks->last_a);
		stacks->last_a = tmp;
	}
	else
		write(1, "rra: not supposed to happen\n", 28);
}

void	rev_rotate_b(t_stacks *stacks)
{
	t_list2	*tmp;

	if (stacks->size_b > 1)
	{
		tmp = stacks->last_b->prev;
		apply_rev_rotate(&(stacks->b), stacks->last_b);
		stacks->last_b = tmp;
	}
	else
		write(1, "rrb: not supposed to happen\n", 28);
}

void	rev_rotate_rrr(t_stacks *stacks)
{
	int		check;
	t_list2	*tmp;

	check = 0;
	if (stacks->size_a > 1 && ++check)
	{
		tmp = stacks->last_a->prev;
		apply_rev_rotate(&(stacks->a), stacks->last_a);
		stacks->last_a = tmp;
	}
	if (stacks->size_b > 1)
	{
		tmp = stacks->last_b->prev;
		apply_rev_rotate(&(stacks->b), stacks->last_b);
		check += 2;
		stacks->last_b = tmp;
	}
	if (check != 3)
		write(1, "rrr: not supposed to happen\n", 28);
}
