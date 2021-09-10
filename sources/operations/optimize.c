/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 03:39:01 by rsanchez          #+#    #+#             */
/*   Updated: 2021/09/10 20:25:17 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	same(int cmd)
{
	static int	same[11] = {SA, SB, ZZZ, ZZZ, ZZZ,
					RA, RB, ZZZ, RRA, RRB, ZZZ};

	return (same[cmd]);
}

static int	mirror(int cmd)
{
	static int	mirror[11] = {SB, SA, ZZZ, ZZZ, ZZZ,
					RB, RA, ZZZ, RRB, RRA, ZZZ};

	return (mirror[cmd]);
}

static int	both(int cmd)
{
	static int	both[11] = {SS,	SS, SS,	ZZZ, ZZZ,
					RR, RR, RR, RRR, RRR, RRR};

	return (both[cmd]);
}

static BOOL	is_optimizable(int origin, t_list2 *cmd, t_list2 **tmp)
{
	if (origin == mirror(cmd->index))
	{
		*tmp = cmd;
		return (TRUE);
	}
	else if ((origin == same(cmd->index) || origin == both(cmd->index))
		&& cmd->next)
		return (is_optimizable(origin, cmd->next, tmp));
	else
		return (FALSE);
}

void	optimize_command(t_stacks *stacks)
{
	t_list2	*cmd;
	t_list2	*tmp;

	cmd = stacks->cmd;
	while (cmd->next)
	{
		if (is_optimizable(cmd->index, cmd->next, &tmp))
		{
			remove_command(stacks, tmp);
			cmd->index = both(cmd->index);
		}
		cmd = cmd->next;
	}
}
