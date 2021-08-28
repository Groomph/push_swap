/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 01:22:24 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/28 08:15:19 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	apply_rotate(t_list **numbers)
{
	t_list	*tmp;

	tmp = *numbers;
	*numbers = (*numbers)->next;
	ft_lstadd_back(numbers, tmp);
	tmp->next = NULL;
}

void	rotate_a(t_stacks *stacks)
{
	if (stacks->size_a > 1)
	{
		apply_rotate(&(stacks->a));
		add_command(stacks, RA);
	}
	else
		write(1, "ra: not supposed to happen\n", 27);
}

void	rotate_b(t_stacks *stacks)
{
	if (stacks->size_b > 1)
	{
		apply_rotate(&(stacks->b));
		add_command(stacks, RB);
	}
	else
		write(1, "rb: not supposed to happen\n", 27);
}

void	rotate_rr(t_stacks *stacks)
{
	int	check;

	check = 0;
	if (stacks->size_a > 1 && ++check)
		apply_rotate(&(stacks->a));
	if (stacks->size_b > 1)
	{
		apply_rotate(&(stacks->b));
		check += 2;
	}
	if (check != 3)
	{
		write(1, "rr: not supposed to happen\n", 27);
		if (check == 1)
			add_command(stacks, RA);
		else if (check == 2)
			add_command(stacks, RB);
	}
	else
		add_command(stacks, RR);
}
