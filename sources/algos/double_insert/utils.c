/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:15:02 by rsanchez          #+#    #+#             */
/*   Updated: 2021/09/10 20:52:24 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_target(t_stacks *stacks, int size_group, int *tar, char c)
{
	int	last;

	if (size_group == 0)
		size_group = 1;
	if (c == 'a')
	{
		last = attrib_group(stacks->a, stacks->size_a, size_group);
		if (last % 2 == 0)
		{
			tar[1] = last / 2;
			tar[0] = tar[1] - 1;
		}
		else
		{
			tar[0] = last / 2;
			tar[1] = tar[0] + 1;
		}
		return (last);
	}
	else
	{
		tar[1] = attrib_group(stacks->b, stacks->size_b, size_group);
		tar[0] = 0;
		return (tar[1]);
	}
}
