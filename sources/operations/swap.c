/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 01:21:50 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/07 18:25:57 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "buffer.h"
#include <unistd.h>

static void	apply_swap(t_list **numbers)
{
	t_list	*tmp;

	tmp = *numbers;
	*numbers = (*numbers)->next;
	tmp->next = (*numbers)->next;
	(*numbers)->next = tmp;
}

void	swap_a(t_swap *swap)
{
	if (swap->size > 1)
	{
		apply_swap(&(swap->numbers));
		if (swap->do_display)
			write_str_buffer("sa\n", 3);
		else
			swap->count_test++;
	}
	else
		write(1, "sa: not supposed to happen\n", 27);
}

void	swap_b(t_swap *swap)
{
	if (swap->size2 > 1)
	{
		apply_swap(&(swap->numbers2));
		if (swap->do_display)
			write_str_buffer("sb\n", 3);
		else
			swap->count_test++;
	}
	else
		write(1, "sb: not supposed to happen\n", 27);
}

void	swap_ss(t_swap *swap)
{
	int	check;

	check = 0;
	if (swap->size > 1)
	{
		apply_swap(&(swap->numbers));
		check++;
	}
	if (swap->size2 > 1)
	{
		apply_swap(&(swap->numbers2));
		check++;
	}
	if (check != 2)
		write(1, "ss: not supposed to happen\n", 27);
	if (swap->do_display)
		write_str_buffer("ss\n", 3);
	else
		swap->count_test++;
}
/*
void	swap_current(t_swap *swap, t_list **current)
{
	if (current == &(swap->numbers))
		swap_a(swap);
	else
		swap_b(swap);
}
*/
