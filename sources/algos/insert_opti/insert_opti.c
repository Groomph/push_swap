/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_opti.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:27:12 by rsanchez          #+#    #+#             */
/*   Updated: 2021/09/10 20:53:25 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_place(int index, t_list2 *list, int size, int *move)
{
	int	dist;
	int	mid;

	mid = size / 2;
	dist = find_nearest_smaller(index, list);
	if (dist == -1)
	{
		dist = find_nearest_greater(index, list);
		if (dist < mid)
			move[0] = dist + 1;
		else if (dist >= mid)
			move[1] = size - dist - 1;
	}
	else
	{
		if (dist <= mid)
			move[0] = dist;
		else if (dist > mid)
			move[1] = size - dist;
	}
}

static void	find2(t_stacks *stacks, int *move_ab, int *tmp_ab, int *result)
{
	t_list2	*list;

	list = stacks->first_locked_a;
	tmp_ab[1] = stacks->size_a - tmp_ab[0];
	tmp_ab[0] = 0;
	while (list)
	{
		tmp_ab[2] = 0;
		tmp_ab[3] = 0;
		find_place(list->index, stacks->b, stacks->size_b, &(tmp_ab[2]));
		result[0] = calcul_result(tmp_ab);
		if (result[0] < result[1])
			save_result(move_ab, tmp_ab, result);
		tmp_ab[1]--;
		list = list->next;
	}
}

static void	find_best_move(t_stacks *stacks, int *move_ab)
{
	int		mid;
	t_list2	*list;
	int		tmp_ab[4];
	int		result[2];

	mid = stacks->size_a / 2;
	list = stacks->a;
	tmp_ab[0] = 0;
	tmp_ab[1] = 0;
	result[1] = 2000000000;
	while (tmp_ab[0] <= mid)
	{
		tmp_ab[2] = 0;
		tmp_ab[3] = 0;
		find_place(list->index, stacks->b, stacks->size_b, &tmp_ab[2]);
		result[0] = calcul_result(tmp_ab);
		if (result[0] < result[1])
			save_result(move_ab, tmp_ab, result);
		tmp_ab[0]++;
		list = list->next;
	}
	stacks->first_locked_a = list;
	find2(stacks, move_ab, tmp_ab, result);
}

void	insert_opti(t_stacks *stacks)
{
	int	move_ab[4];
	int	dir;

	push_b(stacks);
	push_b(stacks);
	if (stacks->b->index < stacks->b->next->index)
		swap_b(stacks);
	while (stacks->size_a > 0)
	{
		move_ab[0] = 0;
		move_ab[1] = 0;
		move_ab[2] = 0;
		move_ab[3] = 0;
		find_best_move(stacks, move_ab);
		move_rotate(stacks, move_ab[0], &rotate_a, &rev_rotate_a);
		move_rotate(stacks, move_ab[2], &rotate_b, &rev_rotate_b);
		move_rotate(stacks, move_ab[1] * -1, &rotate_a, &rev_rotate_a);
		move_rotate(stacks, move_ab[3] * -1, &rotate_b, &rev_rotate_b);
		push_b(stacks);
	}
	lf_index_dir(stacks->b, stacks->size_b, stacks->total_size - 1, &dir);
	move_rotate(stacks, dir, &rotate_b, &rev_rotate_b);
	while (stacks->size_b > 0)
		push_a(stacks);
}
