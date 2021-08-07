/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_25.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:13:57 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/07 00:31:59 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static void	final_from_a(t_swap *swap)
{
	int	dir;
	int	tmp_dir;
	int	index;

	index = 0;
	while (index < swap->total_size)
	{
		lf_index_dir(swap->numbers, swap->size, index, &dir);
		tmp_dir = dir * -1;
		if (dir != 0)
		{
			move_rotate(swap, dir, &rotate_a, &rev_rotate_a);
			push_b(swap);
			move_rotate(swap, tmp_dir, &rotate_a, &rev_rotate_a);
			push_a(swap);
		}
		rotate_a(swap);
		index++;
	}
	lf_index_dir(swap->numbers, swap->size, 0, &dir);
	move_rotate(swap, dir, &rotate_a, &rev_rotate_a);
}
*/
static void	final_from_b(t_swap *swap)
{
	int	dir;
	int	index;

	index = swap->size2 - 1;
	while (swap->size2 > 0)
	{
		lf_index_dir(swap->numbers2, swap->size2, index, &dir);
		move_rotate(swap, dir, &rotate_b, &rev_rotate_b);
		index--;
		push_a(swap);
	}
}

static void	sort_b25(t_swap *swap, int size_group)
{
	int	dir;
	int	index;

	index = swap->total_size;
	while (swap->size2 > 0)
	{
		if (lf_greater_dir(swap->numbers2, swap->size2, index, &dir))
		{
			move_rotate(swap, dir, &rotate_b, &rev_rotate_b);
			push_a(swap);
		}
		else
			index -= size_group;
	}
//	display_stacks(swap);
//	if (size_group > 20)
		sort_a25(swap, size_group / 2);
//	else
//		final_from_a(swap);
}

void    sort_a25(t_swap *swap, int size_group)
{
	int	dir;
	int	index;

	index = size_group;
	while (swap->size > 0)
	{
		if (lf_smaller_dir(swap->numbers, swap->size, index, &dir))
		{
			move_rotate(swap, dir, &rotate_a, &rev_rotate_a);
			push_b(swap);
		}
		else
			index += size_group;
	}
//	display_stacks(swap);
	if (size_group > 20)
		sort_b25(swap, size_group / 2);
	else
		final_from_b(swap);
}

static void    pre_sort_a25(t_swap *swap, int size_group)
{
	int	dir;
	int	index;

	index = (size_group * 2) / 3;
	while (lf_smaller_dir(swap->numbers, swap->size, index, &dir))
	{
		if (swap->numbers->index < index / 2)
		{
			push_b(swap);
			if (swap->size2 > 1)
				rotate_b(swap);
		}
		else if (swap->numbers->index < index)
			push_b(swap);
		else
			rotate_a(swap);

	}
	while (swap->size > 0)
	{
		push_b(swap);
	}
//	display_stacks(swap);
	if (index > 20)
		sort_b25(swap, index / 4);
	else
		final_from_b(swap);
}

void	algo_25(t_swap *swap)
{
	pre_sort_a25(swap, swap->total_size);
}
