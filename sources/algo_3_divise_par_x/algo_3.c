/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 00:40:05 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/07 18:43:05 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void    sort_a3(t_swap *swap, int size_group)
{
	int	dir;
	int	index;

	index = size_group;
	while (swap->size > 0)
	{
		if (lf_smaller_dir(swap->numbers, swap->size, index, &dir))
		{
			move_rotate(swap, dir, &rotate_a, &rev_rotate_a);
//			if (swap->size2 > 1 && lf_index_dir(swap->numbers2, swap->size2, swap->numbers->index - 1, &dir))
//				move_rotate(swap, dir, &rotate_b, &rev_rotate_b);
			push_b(swap);
		}
		else
			index += size_group;
//		display_stacks(swap);
	}
	final_from_b(swap);
}

#include <stdio.h>

static void	test_algo3(t_swap *swap, t_list *stock, int size_group, int stop)
{
        int     results[2];

	results[0] = 2000000000;
	while (size_group <= stop)
        {
                swap->numbers = duplicate_list(swap, stock);
		sort_a3(swap, size_group); 
                if (checkifsort(swap) && swap->count_test < results[0])
		{
                        results[0] = swap->count_test;
			results[1] = size_group;
		}
		printf("Test 4, size_group: %i cmd: %i\n", size_group, swap->count_test);
                swap->count_test = 0;
                ft_lstclear(&(swap->numbers), &free);
                ft_lstclear(&(swap->numbers2), &free);
                size_group++;
        }
        swap->numbers = stock;
	swap->count_test = results[0];
	swap->extra = results[1];
}

void	algo_3(t_swap *swap)
{
	if (!(swap->do_display))
		test_algo3(swap, swap->numbers, swap->total_size / 25, swap->total_size / 5);
	else
	{
		sort_a3(swap, swap->extra);
	}

}
