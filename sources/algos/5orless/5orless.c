/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5orless.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 20:44:57 by rsanchez          #+#    #+#             */
/*   Updated: 2021/09/10 20:39:32 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	sort_topthree(t_stacks *stacks)
{
	int	tmp[3];

	tmp[0] = stacks->a->index;
	tmp[1] = stacks->a->next->index;
	tmp[2] = stacks->a->next->next->index;
	if (tmp[0] + 2 == tmp[2])
		tmp[0] = 0;
	else if (tmp[0] + 2 == tmp[1])
		topthree_132(stacks);
	else if (tmp[1] + 2 == tmp[2])
		topthree_213(stacks);
	else if (tmp[2] + 2 == tmp[1])
		topthree_231(stacks);
	else if (tmp[1] + 2 == tmp[0])
		topthree_312(stacks);
	else if (tmp[2] + 2 == tmp[0])
		topthree_321(stacks);
	else
		write(1, "sort_top_a: not supposed to happen\n", 35);
}

static void	sort_three(t_stacks *stacks)
{
	int	tmp[3];

	tmp[0] = stacks->a->index;
	tmp[1] = stacks->a->next->index;
	tmp[2] = stacks->a->next->next->index;
	if (tmp[0] + 2 == tmp[2])
		tmp[0] = 0;
	else if (tmp[0] + 2 == tmp[1])
		three_132(stacks);
	else if (tmp[1] + 2 == tmp[2])
		three_213(stacks);
	else if (tmp[2] + 2 == tmp[1])
		three_231(stacks);
	else if (tmp[1] + 2 == tmp[0])
		three_312(stacks);
	else if (tmp[2] + 2 == tmp[0])
		three_321(stacks);
	else
		write(1, "sort_a: not supposed to happen\n", 31);
}

static void	sort_five2(t_stacks *stacks, int size, int i, BOOL top)
{
	if (size == 2 && stacks->a->index > stacks->a->next->index)
		swap_a(stacks);
	else if (size > 1)
	{
		if (top)
		{
			back_to_bot(stacks, -1, 'a');
			sort_topthree(stacks);
		}
		else
			sort_three(stacks);
	}
	while (i-- > 0)
		push_a(stacks);
}

void	sort_five(t_stacks *stacks, int size, int group, BOOL top)
{
	int	i;
	int	index;
	int	dir;

	i = 0;
	while (i < size - 3)
	{
		index = lf_smallest_index_ingroup(stacks->a, group,
				&dir, stacks->size_a);
		if ((size == 5 && dir == 1 && stacks->a->index == index + 1)
			|| (size == 4 && dir == 1))
			swap_a(stacks);
		else
			move_rotate(stacks, dir, &rotate_a, &rev_rotate_a);
		push_b(stacks);
		i++;
	}
	sort_five2(stacks, size, i, top);
}
