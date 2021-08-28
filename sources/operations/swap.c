/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 01:21:50 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/28 08:14:50 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	apply_swap(t_list **numbers)
{
	t_list	*tmp;

	tmp = *numbers;
	*numbers = (*numbers)->next;
	tmp->next = (*numbers)->next;
	(*numbers)->next = tmp;
}

void	swap_a(t_stacks *stacks)
{
	if (stacks->size_a > 1)
	{
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
		apply_swap(&(stacks->a));
	if (stacks->size_b > 1)
	{
		apply_swap(&(stacks->b));
		check += 2;
	}
	if (check != 3)
	{
		write(1, "ss: not supposed to happen\n", 27);
		if (check == 1)
			add_command(stacks, SA);
		else if (check == 2)
			add_command(stacks, SB);
	}
	else
		add_command(stacks, SS);
}
