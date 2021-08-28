/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:52:52 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/27 18:24:45 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    move_rotate(t_stacks *stacks, int dir, void (*rot)(t_stacks *stacks),
		void (*rev)(t_stacks *stacks))
{
	while (dir != 0)
	{
		if (dir < 0)
		{
			rev(stacks);
			dir++;
		}
		else
		{
			rot(stacks);
			dir--;
		}
	}
}

int      lf_smallest_index_ingroup(t_list *tmp, int group)
{
        int     index;

        index = -1;
        while (tmp)
        {
                if ((index == -1 || tmp->index < index) && tmp->group == group)
                        index = tmp->index;
                tmp = tmp->next;
        }
        return (index);
}

BOOL	lf_index_dir(t_list *stack, int size, int index, int *dir)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (stack)
	{
		if (index == stack->index)
		{
			if (i <= size / 2 || size == 1)
				*dir = i;
			else
				*dir = i - size;
			return (TRUE);
		}
		stack = stack->next;
		i++;
	}
	return (FALSE);
}
