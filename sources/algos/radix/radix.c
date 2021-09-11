/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:20:33 by rsanchez          #+#    #+#             */
/*   Updated: 2021/09/10 23:54:48 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	radix_sort_b(t_stacks *stacks, int expo)
{
	int	target[2];
	int	dir;

	attrib_group_radix(stacks->b, expo, target);
	set_target_radix(target);
	while (stacks->size_b > 0)
	{
		if (find_best_dir(stacks, target, 'b', &dir))
		{
			move_rotate(stacks, dir, &rotate_b, &rev_rotate_b);
			push_a(stacks);
			if (stacks->a->group == target[1] && stacks->size_a > 1)
				rotate_a(stacks);
		}
		else
		{
			target[0]--;
			target[1]++;
		}
	}
	radix_sort_a(stacks, expo / 10);
}

void	radix_sort_a(t_stacks *stacks, int expo)
{
	int	target[2];
	int	dir;

	attrib_group_radix(stacks->a, expo, target);
	set_target_radix(target);
	while (stacks->size_a > 0)
	{
		if (find_best_dir(stacks, target, 'a', &dir))
		{
			move_rotate(stacks, dir, &rotate_a, &rev_rotate_a);
			push_b(stacks);
			if (stacks->b->group == target[0] && stacks->size_b > 1)
				rotate_b(stacks);
		}
		else
		{
			target[0]--;
			target[1]++;
		}
	}
	if (expo > 10)
		radix_sort_b(stacks, expo / 10);
	else
		sort_final(stacks, stacks->total_size - 1);
}

void	radix(t_stacks *stacks)
{
	int	i;
	int	expo;
	int	tmp;

	i = 0;
	expo = 1;
	tmp = stacks->total_size - 1;
	while (tmp / expo >= 10)
		expo *= 10;
	while (tmp > 0)
	{
		tmp /= 10;
		i++;
	}
	if (i % 2 == 1)
	{
		while (stacks->size_a > 0)
			push_b(stacks);
		if (stacks->total_size > 10)
			radix_sort_b(stacks, expo);
		else
			sort_final(stacks, stacks->total_size - 1);
	}
	else
		radix_sort_a(stacks, expo);
}
