/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 12:44:09 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/07 18:58:22 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "buffer.h"

static void (*g_algo_functions[6])(t_swap *swap) =
{
	&algo_1,
	&algo_15,
	&algo_2,
	&algo_25,
	&algo_3,
//	&algo_35,
	NULL
};

static void	sort_three(t_swap *swap)
{
	int	tmp;
	int	tmp2;
	int	tmp3;

	tmp = swap->numbers->index;
	tmp2 = swap->numbers->next->index;
	tmp3 = swap->numbers->next->next->index;
	if (tmp < tmp2 && tmp < tmp3 && tmp2 > tmp3)
	{
		rev_rotate_a(swap);
		swap_a(swap);
	}
	else if (tmp > tmp2 && tmp < tmp3)
		swap_a(swap);
	else if (tmp < tmp2 && tmp > tmp3)
		rev_rotate_a(swap);
	else if (tmp > tmp2 && tmp2 > tmp3)
	{
		swap_a(swap);
		rev_rotate_a(swap);
	}
	else if (tmp > tmp2 && tmp2 < tmp3)
		rotate_a(swap);
}

static void	sort_five(t_swap *swap)
{
	int	index;
	int	dir;

	while (swap->size > 3)
	{
		index = swap->size - 4;
		lf_index_dir(swap->numbers, swap->size, index, &dir);
		move_rotate(swap, dir, &rotate_a, &rev_rotate_a);
		push_b(swap);
	}
	sort_three(swap);
	while (swap->size2 > 0)
		push_a(swap);
}

#include <stdio.h>

static int	test_algo(t_swap *swap)
{
	int	i;
	int	results[2];
	t_list	*stock_a;

	i = 0;
	results[0] = 2000000000;
	stock_a = swap->numbers;
	while (g_algo_functions[i] != NULL)
	{
		swap->numbers = duplicate_list(swap, stock_a);
		g_algo_functions[i](swap);
		if (checkifsort(swap) && swap->count_test < results[0])
		{
			results[0] = swap->count_test;
			results[1] = i;
		}
		printf("Algo test %i: %i\n", i, swap->count_test);
		swap->count_test = 0;
		ft_lstclear(&(swap->numbers), &free);
		ft_lstclear(&(swap->numbers2), &free);
		i++;
	}
	swap->numbers = stock_a;
	return (results[1]);
}

void	select_algo(t_swap *swap)
{
	int	i;

	init_buffer();
	if (swap->size == 2)
	{
		swap->do_display = TRUE;
		swap_a(swap);
	}
	else if (swap->size <= 5)
	{
		swap->do_display = TRUE;
		sort_five(swap);
	}
	else
	{
		i = test_algo(swap);
		write_str_buffer("Algo selectionne: ", 18); 
		write_int_buffer(i);
		write_char_buffer('\n', 1);
		swap->do_display = TRUE;
		g_algo_functions[i](swap);
		write_str_buffer("Algo selectionne: ", 18); 
		write_int_buffer(i);
		write_char_buffer('\n', 1);
	}
	print_buffer(1);
	if (!checkifsort(swap))
		write(1, "Error: not sorted\n", 18);
}
