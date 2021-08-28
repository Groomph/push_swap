/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 09:51:19 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/28 08:19:07 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void     sort_stack_a(t_stacks *stacks)
{
        int     tmp;
        int     tmp2;
//        int     tmp3;

        tmp = stacks->a->index;
	if (stacks->a->next)
      		tmp2 = stacks->a->next->index;
	else
		tmp2 = 999999999;
  //      	tmp3 = stacks->a->next->next->index;
        if (tmp2 < tmp)
	{
		if (stacks->size_b > 1 && stacks->b->index < stacks->b->next->index)
               		swap_ss(stacks);
		else
               		swap_a(stacks);
        }
  /*      else if (tmp < tmp2 && tmp < tmp3 && tmp2 > tmp3)
	{
		rotate_a(stacks);
                swap_a(stacks);
		rev_rotate_a(stacks);
	}
        else if (tmp < tmp2 && tmp > tmp3)
	{
                rotate_a(stacks);
                swap_a(stacks);
                rev_rotate_a(stacks);
                swap_a(stacks);
	}
        else if (tmp > tmp2 && tmp2 < tmp3)
        {
                swap_a(stacks);
                rotate_a(stacks);
                swap_a(stacks);
                rev_rotate_a(stacks);
        }
        else if (tmp > tmp2 && tmp2 > tmp3)
	{
                swap_a(stacks);
                rotate_a(stacks);
                swap_a(stacks);
                rev_rotate_a(stacks);
                swap_a(stacks);
	}
	*/
}

static void	split_group_a(t_list *stack, int group)
{
	int	min;
	int	max;
	int	mid;
	t_list *stock;

	stock = stack;
	min = 999999999;
	max = 0;
	while (stack && stack->group > -1)
	{
		if (min > stack->index)
			min = stack->index;
		if (max < stack->index)
			max = stack->index;
		stack = stack->next;
	}
	mid = min + ((max - min) / 2);
	while (stock && stock->group > -1)
	{
		if (stock->index <= mid)
			stock->group = group;
		else
			stock->group = group + 1;
		stock = stock->next;
	}
}

static void	sort_a20(t_stacks *stacks, int group)//, int stop)
{
	int	dir;
	int	total_dir;

	if (is_sortable(stacks->a, stacks->total_size - 1))// && stop < 11)
	{
		sort_stack_a(stacks);
		set_group(stacks->a, -1);
		if (stacks->size_b > 0)
		{
			group = get_previous_group(stacks, group - 1);
			sort_a20(stacks, group);//, stop + 1);
		}
	}
	else //if (stop < 11)
	{
		split_group_a(stacks->a, group);
		total_dir = 0;
		while (lf_group_dir(stacks->a, stacks->size_a, group, &dir))
		{
			move_rotate(stacks, dir, &rotate_a, &rev_rotate_a);
			push_b(stacks);
			if (dir < 0)
				dir++;
			total_dir += dir * -1;
		}
		move_rotate(stacks, total_dir, &rotate_a, &rev_rotate_a);
		sort_a20(stacks, group + 1);//, stop + 1);
	}
}

static void	presort_a20(t_stacks *stacks, int size_group)
{
	int     dir;
	int     dir2;
	BOOL    check;
	BOOL    check2;

	attrib_group(stacks->a, stacks->size_a, size_group);
	check = 1;
	while (check || check2)
	{
		check = lf_group_dir(stacks->a, stacks->size_a, 0, &dir);
		check2 = lf_group_dir(stacks->a, stacks->size_a, 1, &dir2);
		if (!check)
			dir = 999999999;
		if (!check2)
			dir2 = 999999999;
		if (check || check2)
		{
			if (valeur_absolue(dir2) < valeur_absolue(dir))
				dir = dir2;
			move_rotate(stacks, dir, &rotate_a, &rev_rotate_a);
			push_b(stacks);
			if (stacks->b->group == 0 && stacks->size_b > 1)
				rotate_b(stacks);
		}
	}
	sort_a20(stacks, 2);//, 0);
//	display_all(stacks);
}


void	quicksort_rec(t_stacks *stacks)
{
	presort_a20(stacks, stacks->total_size / 3);

}
