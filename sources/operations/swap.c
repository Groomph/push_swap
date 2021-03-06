/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 01:21:50 by rsanchez          #+#    #+#             */
/*   Updated: 2021/09/10 20:28:52 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	apply_swap(t_list2 **stack)
{
	t_list2	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
	(*stack)->prev = NULL;
	if (tmp->next)
		tmp->next->prev = tmp;
}

void	swap_a(t_stacks *stacks)
{
	if (stacks->size_a > 1)
	{
		if (stacks->size_a == 2)
			stacks->last_a = stacks->a;
		apply_swap(&(stacks->a));
		add_command(stacks, SA);
	}
	else
		write(1, "sa: not supposed to happen\n", 27);
}

void	swap_b(t_stacks *stacks)
{
	if (stacks->size_b > 1)
	{
		if (stacks->size_b == 2)
			stacks->last_b = stacks->b;
		apply_swap(&(stacks->b));
		add_command(stacks, SB);
	}
	else
		write(1, "sb: not supposed to happen\n", 27);
}

void	swap_ss(t_stacks *stacks)
{
	int	check;

	check = 0;
	if (stacks->size_a > 1 && ++check)
	{
		if (stacks->size_a == 2)
			stacks->last_a = stacks->a;
		apply_swap(&(stacks->a));
	}
	if (stacks->size_b > 1)
	{
		if (stacks->size_b == 2)
			stacks->last_b = stacks->b;
		apply_swap(&(stacks->b));
		check += 2;
	}
	if (check != 3)
	{
		if (check == 1)
			add_command(stacks, SA);
		else if (check == 2)
			add_command(stacks, SB);
	}
	else
		add_command(stacks, SS);
}

void	which_swap(t_stacks *stacks, char c)
{
	if (c == 'a')
	{
		if (stacks->size_b > 1
			&& stacks->b->index < stacks->b->next->index)
			swap_ss(stacks);
		else
			swap_a(stacks);
	}
	else
	{
		if (stacks->size_a > 1
			&& stacks->a->index > stacks->a->next->index)
			swap_ss(stacks);
		else
			swap_b(stacks);
	}
}
