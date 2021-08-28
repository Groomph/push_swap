/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 09:51:19 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/28 08:19:16 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	split_group_b(t_list *stack, int group)
{
	int	min;
	int	max;
	int	mid;
	t_list *stock;

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

int	get_previous_group(t_stacks *stacks, int group)
{
	int	dir;
	int	total_dir;

	total_dir = 0;
	while (!group_ispresent(stacks->b, group))
		group--;
	if (get_size_first_group(stacks->b) > 2)//meilleur resultat qu'avec < 3
	{
		if (get_size_first_group(stacks->b) == 3 && stacks->b->index > stacks->b->next->index && stacks->b->index > stacks->b->next->next->index)
		{
		while (stacks->b && stacks->b->group == group)
			push_a(stacks);

		}
		else
		{
			split_group_b(stacks->b, group++);
			while (lf_group_dir(stacks->b, stacks->size_b, group, &dir))
			{
				move_rotate(stacks, dir, &rotate_b, &rev_rotate_b);
				push_a(stacks);
				if (dir < 0)
					dir++;
				total_dir += dir * -1;
			}
			move_rotate(stacks, total_dir, &rotate_b, &rev_rotate_b);
		}
	}
	else
	{
		while (stacks->b && stacks->b->group == group)
			push_a(stacks);
	}
//	display_all(stacks);
	return (group);
}
