/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:13:57 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/06 23:08:48 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "buffer.h"

#include <stdio.h>
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

static void	sort_b(t_swap *swap, int size_group)
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
		sort_a(swap, size_group / 2);
//	else
//		final_from_a(swap);
}

void    sort_a(t_swap *swap, int size_group)
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
		sort_b(swap, size_group / 2);
	else
		final_from_b(swap);
}

void	algo_1(t_swap *swap)
{
	sort_a(swap, swap->total_size / 2);
}
