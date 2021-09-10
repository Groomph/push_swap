/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 12:52:10 by rsanchez          #+#    #+#             */
/*   Updated: 2021/09/10 20:54:43 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	presort_2(t_stacks *stacks, BOOL *check)
{
	int	dir;
	int	dir2;

	check[0] = lf_group_dir(stacks->a, stacks->size_a, 0, &dir);
	check[1] = lf_group_dir(stacks->a, stacks->size_a, 1, &dir2);
	if (!check[0])
		dir = 999999999;
	if (!check[1])
		dir2 = 999999999;
	if (check[0] || check[1])
	{
		if (valeur_absolue(dir2) < valeur_absolue(dir))
			dir = dir2;
		move_rotate(stacks, dir, &rotate_a, &rev_rotate_a);
		push_b(stacks);
		if (stacks->b->group == 0 && stacks->size_b > 1)
			rotate_b(stacks);
	}
}

void	presort_x_a(t_stacks *stacks, int size_group, BOOL reset_group)
{
	BOOL	check[2];

	attrib_group(stacks->a, stacks->size_a, size_group);
	check[0] = 1;
	while (check[0] || check[1])
	{
		presort_2(stacks, check);
	}
	if (reset_group)
		set_group(stacks->a, 2);
}

void	presort_2_a(t_stacks *stacks)
{
	int	dir;

	attrib_group(stacks->a, stacks->size_a, stacks->total_size / 2);
	while (lf_group_dir(stacks->a, stacks->size_a, 0, &dir))
	{
		move_rotate(stacks, dir, &rotate_a, &rev_rotate_a);
		push_b(stacks);
	}
}
