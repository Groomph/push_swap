/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 09:51:19 by rsanchez          #+#    #+#             */
/*   Updated: 2021/09/10 20:57:26 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_group_a(t_list2 *stack, int group)
{
	int		min;
	int		max;
	int		mid;
	t_list2	*stock;

	stock = stack;
	min = 999999999;
	max = 0;
	while (stack && stack->group > -1)
	{
		if (min > stack->index)
			min = stack->index;
		if (max < stack->index)
			max = stack->index;
		stack = stack->next;
	}
	mid = min + ((max - min) / 2);
	while (stock && stock->group > -1)
	{
		if (stock->index <= mid)
			stock->group = group;
		else
			stock->group = group + 1;
		stock = stock->next;
	}
}

static void	split_unsorted(t_stacks *stacks, int group)
{
	int	dir;

	split_group_a(stacks->a, group);
	while (lf_group_dir(stacks->a, stacks->size_a, group, &dir))
	{
		move_rotate(stacks, dir, &rotate_a, &rev_rotate_a);
		push_b(stacks);
	}
	if (group_ispresent(stacks->a, -1))
		back_to_bot(stacks, -1, 'a');
	back_to_bot(stacks, 0, 'b');
	stacks->first_locked_a = lock_sorted(stacks->a, stacks->total_size,
			stacks->first_locked_a, stacks->last_a);
	quicksort_a(stacks, group + 1);
}

void	quicksort_a(t_stacks *stacks, int group)
{
	int		size;
	BOOL	check;

	size = get_size_first_group(stacks->a);
	check = is_sorted_inc(stacks->a, stacks->total_size,
			stacks->first_locked_a, stacks->last_a);
	if (stacks->a->group == -1)
		quicksort_b(stacks);
	else if (size <= 5 || check)
	{
		if (!check)
		{
			if (size == stacks->size_a)
				sort_five(stacks, size, group, FALSE);
			else
				sort_five(stacks, size, group, TRUE);
		}
		stacks->first_locked_a = stacks->a;
		set_group(stacks->a, -1);
		if (stacks->size_b > 0)
			quicksort_b(stacks);
	}
	else
		split_unsorted(stacks, group);
}

void	quicksort_rec(t_stacks *stacks)
{
	int	group;

	group = 2;
	if (stacks->extra == 0)
	{
		presort_2_a(stacks);
		group = 1;
	}
	else if (stacks->extra == 1)
		presort_x_a(stacks, stacks->total_size / 3, FALSE);
	else if (stacks->extra == 2)
		presort_x_a(stacks, stacks->total_size / 4, TRUE);
	else if (stacks->extra == 3)
		presort_x_a(stacks, stacks->total_size / 5, TRUE);
	stacks->extra++;
	if (stacks->extra == 4)
		stacks->extra = 0;
	quicksort_a(stacks, group);
}
