/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   topthree_b_123.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 08:46:07 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/29 11:34:41 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	topthree_b_123(t_stacks *stacks)
{
	which_swap(stacks, 'b');
	push_a(stacks);
	swap_b(stacks);
	push_a(stacks);
	swap_a(stacks);
	push_a(stacks);
}

void	topthree_b_132(t_stacks *stacks)
{
	which_swap(stacks, 'b');
	push_a(stacks);
	swap_b(stacks);
	push_a(stacks);
	push_a(stacks);
}

void	topthree_b_213(t_stacks *stacks)
{
	push_a(stacks);
	which_swap(stacks, 'b');
	push_a(stacks);
	swap_a(stacks);
	push_a(stacks);
}

void	topthree_b_231(t_stacks *stacks)
{
	which_swap(stacks, 'b');
	push_a(stacks);
	push_a(stacks);
	push_a(stacks);
}

void	topthree_b_312(t_stacks *stacks)
{
	push_a(stacks);
	which_swap(stacks, 'b');
	push_a(stacks);
	push_a(stacks);
}
