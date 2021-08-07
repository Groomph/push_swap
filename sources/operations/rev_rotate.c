/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 01:22:24 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/05 13:53:17 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "buffer.h"
#include <unistd.h>

static void	apply_rev_rotate(t_list **numbers)
{
	t_list	*tmp;

	tmp = ft_lstsecondlast(*numbers);
	tmp->next->next = *numbers;
	*numbers = tmp->next;
	tmp->next = NULL;
}

void	rev_rotate_a(t_swap *swap)
{
	if (swap->size > 1)
	{
		apply_rev_rotate(&(swap->numbers));
		if (swap->do_display)
			write_str_buffer("rra\n", 4);
		else
			swap->count_test++;
	}
	else
		write(1, "rra: not supposed to happen\n", 28);
}

void	rev_rotate_b(t_swap *swap)
{
	if (swap->size2 > 1)
	{
		apply_rev_rotate(&(swap->numbers2));
		if (swap->do_display)
			write_str_buffer("rrb\n", 4);
		else
			swap->count_test++;
	}
	else
		write(1, "rrb: not supposed to happen\n", 28);
}

void	rev_rotate_rrr(t_swap *swap)
{
	int	check;

	check = 0;
	if (swap->size > 1)
	{
		apply_rev_rotate(&(swap->numbers));
		check++;
	}
	if (swap->size2 > 1)
	{
		apply_rev_rotate(&(swap->numbers2));
		check++;
	}
	if (check != 2)
		write(1, "rrr: not supposed to happen\n", 28);
	if (swap->do_display)
		write_str_buffer("rrr\n", 4);
	else
		swap->count_test++;
}
