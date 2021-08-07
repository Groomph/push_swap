/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 01:22:24 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/05 13:52:20 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "buffer.h"
#include <unistd.h>

static void	apply_rotate(t_list **numbers)
{
	t_list	*tmp;

	tmp = *numbers;
	*numbers = (*numbers)->next;
	ft_lstadd_back(numbers, tmp);
	tmp->next = NULL;
}

void	rotate_a(t_swap *swap)
{
	if (swap->size > 1)
	{
		apply_rotate(&(swap->numbers));
		if (swap->do_display)
			write_str_buffer("ra\n", 3);
		else
			swap->count_test++;
	}
	else
		write(1, "ra: not supposed to happen\n", 27);
}

void	rotate_b(t_swap *swap)
{
	if (swap->size2 > 1)
	{
		apply_rotate(&(swap->numbers2));
		if (swap->do_display)
			write_str_buffer("rb\n", 3);
		else
			swap->count_test++;
	}
	else
		write(1, "rb: not supposed to happen\n", 27);
}

void	rotate_rr(t_swap *swap)
{
	int	check;

	check = 0;
	if (swap->size > 1)
	{
		apply_rotate(&(swap->numbers));
		check++;
	}
	if (swap->size2 > 1)
	{
		apply_rotate(&(swap->numbers2));
		check++;
	}
	if (check != 2)
		write(1, "rr: not supposed to happen\n", 27);
	if (swap->do_display)
		write_str_buffer("rr\n", 3);
	else
		swap->count_test++;
}
