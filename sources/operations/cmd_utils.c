/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:09:16 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/30 14:56:10 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_command(t_stacks *stacks, char cmd)
{
	t_list2	*tmp;

	tmp = malloc(sizeof(t_list2));
	if (!tmp)
		exit_program(stacks, 2);
	tmp->index = cmd;
	tmp->prev = stacks->last_cmd;
	tmp->next = NULL;
	if (!stacks->cmd)
		stacks->cmd = tmp;
	else
		stacks->last_cmd->next = tmp;
	stacks->last_cmd = tmp;
	stacks->count++;
}

void	remove_command(t_stacks *stacks, t_list2 *list)
{
	list->prev->next = list->next;
	if (list->next)
		list->next->prev = list->prev;
	else
		stacks->last_cmd = list->prev;
	stacks->count--;
	free(list);
}
