/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:52:52 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/05 13:27:17 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	lf_greater_back(t_list *stack, int size, int index, int i)
{
	int	i2;

	while (stack)
	{
		if (stack->index >= index)
			i2 = i;
		stack = stack->next;
		i++;
	}
	return (i2 - size);
}

BOOL	lf_greater_dir(t_list *stack, int size, int index, int *dir)
{
	int	i;
	int	i2;
	int	check;

	i = 0;
	check = 0;
	while (stack)
	{
		if (stack->index >= index)
		{
			i2 = lf_greater_back(stack, size, index, i);
			if (i <= i2 * -1)
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

static int	lf_smaller_back(t_list *stack, int size, int index, int i)
{
	int	i2;

	while (stack)
	{
		if (stack->index < index)
			i2 = i;
		stack = stack->next;
		i++;
	}
	return (i2 - size);
}

BOOL	lf_smaller_dir(t_list *stack, int size, int index, int *dir)
{
	int	i;
	int	i2;
	int	check;

	i = 0;
	check = 0;
	while (stack)
	{
		if (stack->index < index)
		{
			i2 = lf_smaller_back(stack, size, index, i);
			if (i <= i2 * -1)
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
