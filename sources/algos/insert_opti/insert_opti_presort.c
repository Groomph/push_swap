/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_opti_presort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:27:12 by rsanchez          #+#    #+#             */
/*   Updated: 2021/09/05 03:48:45 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <unistd.h>

static void	find_place(int index, t_list2 *list, int size, int *move)
{
	int	dist;
	int	mid;

	mid = size / 2;
	dist = find_nearest_greater(index, list);
	if (dist == -1)
	{
		dist = find_nearest_smaller(index, list);
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

	list = stacks->first_locked_b;
	tmp_ab[3] = stacks->size_b - tmp_ab[2];
	tmp_ab[2] = 0;
	while (list)
	{
		tmp_ab[0] = 0;
		tmp_ab[1] = 0;
		find_place(list->index, stacks->a, stacks->size_a, tmp_ab);
		result[0] = calcul_result(tmp_ab);
		if (result[0] < result[1])
			save_result(move_ab, tmp_ab, result);
		tmp_ab[3]--;
		list = list->next;
	}
}

static void	find_best_move(t_stacks *stacks, int *move_ab)
{
	int	mid;
	t_list2	*list;
	int	tmp_ab[4];
	int	result[2];

	mid = stacks->size_b / 2;
	list = stacks->b;
	tmp_ab[2] = 0;
	tmp_ab[3] = 0;
	result[1] = 2000000000;
	while (tmp_ab[2] <= mid)
	{
		tmp_ab[0] = 0;
		tmp_ab[1] = 0;
		find_place(list->index, stacks->a, stacks->size_a, tmp_ab);
		result[0] = calcul_result(tmp_ab);
		if (result[0] < result[1])
			save_result(move_ab, tmp_ab, result);
		tmp_ab[2]++;
		list = list->next;
	}
	stacks->first_locked_b = list;
	find2(stacks, move_ab, tmp_ab, result);
}

static void	set_stacks(t_stacks *stacks)
{
	presort_x_a(stacks, stacks->total_size / 3, FALSE);
	while (stacks->size_a > 0)
		push_b(stacks);
	push_a(stacks);
	push_a(stacks);
	if (stacks->a->index > stacks->a->next->index)
		swap_a(stacks);
}

void	insert_opti_presort(t_stacks *stacks)
{
	int	move_ab[4];
	int	dir;

	set_stacks(stacks);
	while (stacks->size_b > 0)
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
		push_a(stacks);
	}
	lf_index_dir(stacks->a, stacks->size_a, 0, &dir);
	move_rotate(stacks, dir, &rotate_a, &rev_rotate_a);
}
