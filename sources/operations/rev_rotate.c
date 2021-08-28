/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 01:22:24 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/28 08:15:38 by rsanchez         ###   ########.fr       */
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

void	rev_rotate_a(t_stacks *stacks)
{
	if (stacks->size_a > 1)
	{
		apply_rev_rotate(&(stacks->a));
		add_command(stacks, RRA);
	}
	else
		write(1, "rra: not supposed to happen\n", 28);
}

void	rev_rotate_b(t_stacks *stacks)
{
	if (stacks->size_b > 1)
	{
		apply_rev_rotate(&(stacks->b));
		add_command(stacks, RRB);
	}
	else
		write(1, "rrb: not supposed to happen\n", 28);
}

void	rev_rotate_rrr(t_stacks *stacks)
{
	int	check;

	check = 0;
	if (stacks->size_a > 1 && ++check)
		apply_rev_rotate(&(stacks->a));
	if (stacks->size_b > 1)
	{
		apply_rev_rotate(&(stacks->b));
		check += 2;
	}
	if (check != 3)
	{
		write(1, "rrr: not supposed to happen\n", 28);
		if (check == 1)
			add_command(stacks, SA);
		else if (check == 2)
			add_command(stacks, SB);
	}
	else
		add_command(stacks, RRR);
}
