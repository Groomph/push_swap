/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 09:51:19 by rsanchez          #+#    #+#             */
/*   Updated: 2021/09/10 20:57:53 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_group_b(t_list2 *stack, int group)
{
	int		min;
	int		max;
	int		mid;
	t_list2	*stock;

	stock = stack;
	min = 999999999;
	max = 0;
	while (stack && stack->group == group)
	{
		if (min > stack->index)
			min = stack->index;
		if (max < stack->index)
			max = stack->index;
		stack = stack->next;
	}
	mid = min + ((max - min) / 2);
	while (stock && stock->group == group)
	{
		if (stock->index > mid)
			stock->group = group + 1;
		else
			stock->group = group;
		stock = stock->next;
	}
}

void	quicksort_b(t_stacks *stacks)
{
	int	group;
	int	dir;
	int	size;

	group = stacks->b->group;
	size = get_size_first_group(stacks->b);
	if (size <= 5)
	{
		sort_five_b(stacks, group, size);
		stacks->first_locked_a = stacks->a;
		set_group(stacks->a, -1);
		if (stacks->size_b > 0)
			quicksort_b(stacks);
	}
	else
	{
		split_group_b(stacks->b, group++);
		while (lf_group_dir(stacks->b, stacks->size_b, group, &dir))
		{
			move_rotate(stacks, dir, &rotate_b, &rev_rotate_b);
			push_a(stacks);
		}
		back_to_bot(stacks, 0, 'b');
		quicksort_a(stacks, group);
	}
}
