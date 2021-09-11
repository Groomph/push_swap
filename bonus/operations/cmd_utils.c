/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:09:16 by rsanchez          #+#    #+#             */
/*   Updated: 2021/09/11 02:24:22 by rsanchez         ###   ########.fr       */
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
	if (!(stacks->cmd))
		stacks->cmd = tmp;
	else
		stacks->last_cmd->next = tmp;
	stacks->last_cmd = tmp;
	stacks->count++;
}
