/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 20:30:35 by rsanchez          #+#    #+#             */
/*   Updated: 2021/09/08 00:08:40 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	save_result(int *move_ab, int *tmp_ab, int *result)
{
	move_ab[0] = tmp_ab[0];
	move_ab[1] = tmp_ab[1];
	move_ab[2] = tmp_ab[2];
	move_ab[3] = tmp_ab[3];
	result[1] = result[0];
}

int	calcul_result(int *tmp_ab)
{
	int	score;

	if (tmp_ab[0] < tmp_ab[2])
		score = tmp_ab[2];
	else
		score = tmp_ab[0];
	if (tmp_ab[1] < tmp_ab[3])
		score += tmp_ab[3];
	else
		score += tmp_ab[1];
	return (score);
}

int	find_nearest_greater(int index, t_list2 *list)
{
	int	tmp;
	int	i;
	int	dist;

	tmp = 2000000000;
	i = 0;
	while (list)
	{
		if (list->index > index && list->index < tmp)
		{
			tmp = list->index;
			dist = i;
		}
		i++;
		list = list->next;
	}
	if (tmp == 2000000000)
		return (-1);
	return (dist);
}

int	find_nearest_smaller(int index, t_list2 *list)
{
	int	tmp;
	int	i;
	int	dist;

	tmp = -1;
	i = 0;
	while (list)
	{
		if (list->index < index && list->index > tmp)
		{
			tmp = list->index;
			dist = i;
		}
		i++;
		list = list->next;
	}
	if (tmp == -1)
		return (-1);
	return (dist);
}
