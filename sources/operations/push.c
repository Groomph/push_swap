/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 01:22:09 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/05 13:50:43 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "buffer.h"
#include <unistd.h>

static void	push(t_list **numbers, t_list **numbers2)
{
	t_list	*tmp;

	tmp = *numbers;
	*numbers = *numbers2;
	*(numbers2) = (*numbers2)->next;
	(*numbers)->next = tmp;
}

void	push_a(t_swap *swap)
{
	if (swap->size2 > 0)
	{
		push(&(swap->numbers), &(swap->numbers2));
		swap->size++;
		swap->size2--;
		if (swap->do_display)
			write_str_buffer("pa\n", 3);
		else
			swap->count_test++;
	}
	else
		write(1, "pa: not supposed to happen\n", 27);
}

void	push_b(t_swap *swap)
{
	if (swap->size > 0)
	{
		push(&(swap->numbers2), &(swap->numbers));
		swap->size--;
		swap->size2++;
		if (swap->do_display)
			write_str_buffer("pb\n", 3);
		else
			swap->count_test++;
	}
	else
		write(1, "pb: not supposed to happen\n", 27);
}

/*
void	push_current(t_swap *swap, t_list **current)
{
	if (current == &(swap->numbers))
		push_b(swap);
	else
		push_a(swap);
}
*/
