/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:29:55 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/27 18:05:25 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size_first_group(t_list *stack)
{
        int	group;
        int	i;

        group = stack->group;
        i = 0;
        while (stack && stack->group == group)
        {
                i++;
                stack = stack->next;
        }
        return (i);
}

BOOL	group_ispresent(t_list *stack, int group)
{
        while (stack)
        {
                if (stack->group == group)
                        return (TRUE);
                stack = stack->next;
        }
        return (FALSE);
}

void	set_group(t_list *stack, int group)
{
        while (stack)
        {
                stack->group = group;
                stack = stack->next;
        }
}

int	attrib_group(t_list *stack, int size_stack, int size_group)
{
	int	last_group;

	last_group = (size_stack - 1) / size_group;
	if (size_stack - last_group * size_group <= size_group / 2)
		last_group--;
	while (stack)
	{
		stack->group = stack->index / size_group;
		if (stack->group > last_group)
			stack->group = last_group;
		stack = stack->next;
	}
	return (last_group);
}

static int	lf_group_back(t_list *stack, int size, int group, int i)
{
	int	i2;

	while (stack)
	{
		if (stack->group == group)
			i2 = i;
		stack = stack->next;
		i++;
	}
	return (i2 - size);
}

BOOL	lf_group_dir(t_list *stack, int size, int group, int *dir)
{
	int	i;
	int	i2;

	i = 0;
	while (stack)
	{
		if (stack->group == group)
		{
			i2 = lf_group_back(stack, size, group, i);
			if (i <= valeur_absolue(i2))
				*dir = i;
			else
				*dir = i2;
			return (TRUE);
		}
		stack = stack->next;
		i++;
	}
	return (FALSE);
}
