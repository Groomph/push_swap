/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5orless.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 20:44:57 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/28 03:54:13 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void     sort_three(t_stacks *stacks)
{
	int	tmp;
	int	tmp2;
	int	tmp3;

	tmp = stacks->a->index;
	tmp2 = stacks->a->next->index;
	tmp3 = stacks->a->next->next->index;
	if (tmp < tmp2 && tmp < tmp3 && tmp2 > tmp3)
	{
		rev_rotate_a(stacks);
		swap_a(stacks);
	}
	else if (tmp > tmp2 && tmp < tmp3)
		swap_a(stacks);
	else if (tmp < tmp2 && tmp > tmp3)
		rev_rotate_a(stacks);
	else if (tmp > tmp2 && tmp2 > tmp3)
	{
		swap_a(stacks);
		rev_rotate_a(stacks);
	}
	else if (tmp > tmp2 && tmp2 < tmp3)
		rotate_a(stacks);
}

void    sort_five(t_stacks *stacks)
{
	int	i;
	int	index;
	int	dir;

	i = 0;
	set_group(stacks->a, 0);
	while (stacks->size_a > 3)
	{
		index = lf_smallest_index_ingroup(stacks->a, 0);
		if (stacks->size_a == 5 && stacks->a->next->index == index
				&& stacks->a->index == index + 1)
			swap_a(stacks);
		else
		{
			lf_index_dir(stacks->a, stacks->size_a, index, &dir);
			move_rotate(stacks, dir, &rotate_a, &rev_rotate_a);
		}
		push_b(stacks);
		i++;
	}
	sort_three(stacks);
	while (i-- > 0)
		push_a(stacks);
}
