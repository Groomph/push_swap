/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:08:04 by rsanchez          #+#    #+#             */
/*   Updated: 2021/10/14 16:32:10 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
static void	sort_final(t_stacks *stacks, int size, int index, int last)
{
	int	size_last;
	int	dir;

	size_last = get_size_first_group(stacks->b);
	while (size_last > 5)
	{
		if (lf_index_dir(stacks->b, stacks->size_b, index, &dir))
		{
			move_rotate(stacks, dir, &rotate_b, &rev_rotate_b);
			push_a(stacks);
		}
		index--;
		size_last--;

	}
	sort_five_b(stacks, last, size_last);
	while (stacks->size_b > 0)
	{
		last--;
		sort_five_b(stacks, last, size);
	}
}
*/

static void	sort_final(t_stacks *stacks, int index)
{
	int	dir;

	while (stacks->size_b > 0)
	{
		if (lf_index_dir(stacks->b, stacks->size_b, index, &dir))
		{
			move_rotate(stacks, dir, &rotate_b, &rev_rotate_b);
			push_a(stacks);
		}
		index--;
	}
}

static BOOL	find_best_dir(t_stacks *stacks, int *t, char c, int *dir)
{
	int		tmp[2];
	BOOL	check;
	BOOL	check2;

	if (c == 'a')
	{
		check = lf_group_dir(stacks->a, stacks->size_a, t[0], &tmp[0]);
		check2 = lf_group_dir(stacks->a, stacks->size_a, t[1], &tmp[1]);
	}
	else
	{
		check = lf_group_dir(stacks->b, stacks->size_b, t[0], &tmp[0]);
		check2 = lf_group_dir(stacks->b, stacks->size_b, t[1], &tmp[1]);
	}
	if (check || check2)
	{
		if ((check2 && !check) || (check && check2
				&& valeur_absolue(tmp[1]) < valeur_absolue(tmp[0])))
			*dir = tmp[1];
		else
			*dir = tmp[0];
		return (TRUE);
	}
	return (FALSE);
}

static void	sort_b(t_stacks *stacks, int size_group)
{
	int	dir;
	int	t[2];

	set_target(stacks, size_group, t, 'b');
	while (stacks->size_b > 0)
	{
		if (find_best_dir(stacks, t, 'b', &dir))
		{
			move_rotate(stacks, dir, &rotate_b, &rev_rotate_b);
			push_a(stacks);
			if (stacks->a->group == t[0] && stacks->size_a > 1)
				rotate_a(stacks);
		}
		else
		{
			t[0]++;
			t[1]--;
		}
	}
	sort_a(stacks, size_group / stacks->extra, FALSE);
}

void	sort_a(t_stacks *stacks, int size_group, BOOL first)
{
	int	dir;
	int	t[2];

	set_target(stacks, size_group, t, 'a');
	while (stacks->size_a > 0)
	{
		if (find_best_dir(stacks, t, 'a', &dir))
		{
			move_rotate(stacks, dir, &rotate_a, &rev_rotate_a);
			push_b(stacks);
			if (stacks->b->group == t[0] && stacks->size_b > 1)
				rotate_b(stacks);
		}
		else
		{
			t[0]--;
			t[1]++;
		}
	}
	if (first)
		sort_b(stacks, size_group / stacks->extra);
	else
		sort_final(stacks, stacks->total_size - 1);
}

void	double_insert(t_stacks *stacks)
{
	int	i;

	if (stacks->total_size < 15000)
		i = 10;
	else
		i = stacks->total_size / 120;
	while (i > 1 && stacks->total_size / (i * i * i) < 15)
		i--;
	stacks->extra = i;
	if (i == 1)
		sort_a(stacks, stacks->total_size / 5, FALSE);
	else
		sort_a(stacks, stacks->total_size / i, TRUE);
	stacks->extra = 0;
}
