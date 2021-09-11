/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:52:46 by rsanchez          #+#    #+#             */
/*   Updated: 2021/09/10 20:18:18 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "buffer.h"

void	display_commands(t_list2 *cmd)
{
	static char	*cmd_str[11] = {"sa\n", "sb\n", "ss\n",
					"pa\n", "pb\n",
					"ra\n", "rb\n", "rr\n",
					"rra\n", "rrb\n", "rrr\n"};

	init_buffer();
	while (cmd)
	{
		write_str_buffer(cmd_str[cmd->index], -1);
		cmd = cmd->next;
	}
	print_buffer(1);
}

static void	display_stacks3(t_list2 *tmp)
{
	write_int_buffer(tmp->nb);
	write_char_buffer(' ', 2);
	write_int_buffer(tmp->index);
	write_char_buffer(' ', 2);
	write_int_buffer(tmp->group);
}

static void	display_stacks2(t_list2 *tmp, t_list2 *tmp2)
{
	while (tmp || tmp2)
	{
		if (tmp)
		{
			display_stacks3(tmp);
			tmp = tmp->next;
		}
		else
			write_char_buffer(' ', 2);
		write_char_buffer(' ', 10);
		if (tmp2)
		{
			display_stacks3(tmp2);
			tmp2 = tmp2->next;
		}
		else
			write_char_buffer(' ', 2);
		write_char_buffer('\n', 1);
	}
}

void	display_stacks(t_stacks *stacks)
{
	init_buffer();
	write_char_buffer('\n', 2);
	display_stacks2(stacks->a, stacks->b);
	print_buffer(1);
}
