/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:52:52 by rsanchez          #+#    #+#             */
/*   Updated: 2021/09/06 17:08:26 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
t_list2	*get_link_from_dir(t_list2 *first, t_list2 *last, int dir)
{
	if (dir >= 0)
	{
		while (--dir >= 0)
			first = first->next;
		return (first);
	}
	if (dir < 0)
	{
		while (++dir <= 0)
			last = last->prev;
		return (last);
	}
}
*/

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

int      lf_greatest_index_ingroup(t_list2 *tmp, int group, int *dir, int size)
{
        int     index;
	int	i;

	*dir = 0;
        index = -1;
	i = 0;
        while (tmp)
        {
                if ((index == -1 || tmp->index > index) && tmp->group == group)
		{
                        index = tmp->index;
			if (i <= size / 2 || size == 1)
				*dir = i;
			else
				*dir = i - size;
		}
                tmp = tmp->next;
		i++;
        }
        return (index);
}

int      lf_smallest_index_ingroup(t_list2 *tmp, int group, int *dir, int size)
{
        int     index;
	int	i;

	*dir = 0;
        index = -1;
	i = 0;
        while (tmp)
        {
                if ((index == -1 || tmp->index < index) && tmp->group == group)
		{
                        index = tmp->index;
			if (i <= size / 2 || size == 1)
				*dir = i;
			else
				*dir = i - size;
		}
                tmp = tmp->next;
		i++;
        }
        return (index);
}

BOOL	lf_index_dir(t_list2 *stack, int size, int index, int *dir)
{
	int	i;
	int	check;

	*dir = 0;
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
