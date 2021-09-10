/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5orless_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:13:52 by romain            #+#    #+#             */
/*   Updated: 2021/09/10 20:41:28 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	sort_topthree_b(t_stacks *stacks)
{
	int	tmp[3];

	tmp[0] = stacks->b->index;
	tmp[1] = stacks->b->next->index;
	tmp[2] = stacks->b->next->next->index;
	if (tmp[0] + 2 == tmp[2])
		topthree_b_123(stacks);
	else if (tmp[0] + 2 == tmp[1])
		topthree_b_132(stacks);
	else if (tmp[1] + 2 == tmp[2])
		topthree_b_213(stacks);
	else if (tmp[2] + 2 == tmp[1])
		topthree_b_231(stacks);
	else if (tmp[1] + 2 == tmp[0])
		topthree_b_312(stacks);
	else if (tmp[2] + 2 == tmp[0])
	{
		push_a(stacks);
		push_a(stacks);
		push_a(stacks);
	}
	else
		write(1, "sort_top_b: not supposed to happen\n", 35);
}

static void	sort_five_b2(t_stacks *stacks, int size)
{
	if (size == 2)
	{
		if (size == 2 && stacks->b->index < stacks->b->next->index)
			swap_b(stacks);
		push_a(stacks);
		push_a(stacks);
	}
	else if (size == 1)
		push_a(stacks);
	else
		sort_topthree_b(stacks);
}

void	sort_five_b(t_stacks *stacks, int group, int size)
{
	int	i;
	int	index;
	int	dir;

	i = 0;
	while (i < size - 3)
	{
		index = lf_greatest_index_ingroup(stacks->b, group,
				&dir, stacks->size_b);
		if ((size == 5 && dir == 1 && stacks->b->index == index - 1)
			|| (size == 4 && dir == 1))
			swap_b(stacks);
		else
			move_rotate(stacks, dir, &rotate_b, &rev_rotate_b);
		push_a(stacks);
		i++;
	}
	back_to_bot(stacks, 0, 'b');
	sort_five_b2(stacks, size);
}
