/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:50:52 by rsanchez          #+#    #+#             */
/*   Updated: 2021/09/10 21:01:53 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_radix(int *target)
{
	if (target[1] % 2 == 0)
	{
		target[1] = target[1] / 2;
		target[0] = target[1] - 1;
	}
	else
	{
		target[0] = target[1] / 2;
		target[1] = target[0] + 1;
	}
}

void	attrib_group_radix(t_list2 *stack, int expo, int *tar)
{
	tar[0] = 9;
	tar[1] = 0;
	while (stack)
	{
		stack->group = stack->index / expo;
		stack->group %= 10;
		if (stack->group < tar[0])
			tar[0] = stack->group;
		if (stack->group > tar[1])
			tar[1] = stack->group;
		stack = stack->next;
	}
}
