/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_123.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 08:46:07 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/29 11:33:21 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_132(t_stacks *stacks)
{
	which_swap(stacks, 'a');
	rotate_a(stacks);
}

void	three_213(t_stacks *stacks)
{
	which_swap(stacks, 'a');
}

void	three_231(t_stacks *stacks)
{
	rev_rotate_a(stacks);
}

void	three_312(t_stacks *stacks)
{
	rotate_a(stacks);
}

void	three_321(t_stacks *stacks)
{
	which_swap(stacks, 'a');
	rev_rotate_a(stacks);
}
