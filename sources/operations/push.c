/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 01:22:09 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/28 08:15:00 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	apply_push(t_list **numbers, t_list **numbers2)
{
	t_list	*tmp;

	tmp = *numbers;
	*numbers = *numbers2;
	*numbers2 = (*numbers2)->next;
	(*numbers)->next = tmp;
}

void	push_a(t_stacks *stacks)
{
	if (stacks->size_b > 0)
	{
		apply_push(&(stacks->a), &(stacks->b));
		stacks->size_a++;
		stacks->size_b--;
		add_command(stacks, PA);
	}
	else
		write(1, "pa: not supposed to happen\n", 27);
}

void	push_b(t_stacks *stacks)
{
	if (stacks->size_a > 0)
	{
		apply_push(&(stacks->b), &(stacks->a));
		stacks->size_a--;
		stacks->size_b++;
		add_command(stacks, PB);
	}
	else
		write(1, "pb: not supposed to happen\n", 27);
}
