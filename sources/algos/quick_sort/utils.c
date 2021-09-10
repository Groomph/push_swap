/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 00:06:34 by rsanchez          #+#    #+#             */
/*   Updated: 2021/09/08 00:07:32 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size_first_group(t_list2 *stack)
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

BOOL	group_ispresent(t_list2 *stack, int group)
{
	while (stack)
	{
		if (stack->group == group)
			return (TRUE);
		stack = stack->next;
	}
	return (FALSE);
}
