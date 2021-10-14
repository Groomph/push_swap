/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:17:50 by rsanchez          #+#    #+#             */
/*   Updated: 2021/10/14 19:25:28 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	exit_program(t_stacks *stacks, BOOL error)
{
	lst2_clear(&(stacks->a), &free);
	lst2_clear(&(stacks->b), &free);
	lst2_clear(&(stacks->cmd), &free);
	if (error == TRUE)
		write(2, "Error\n", 6);
	else if (error == 2)
		write(2, "Malloc error\n", 13);
	exit(1);
}

static void	apply_commands(t_stacks *stacks)
{
	static void	(*f[11])(t_stacks *stacks) =
	{
		&swap_a, &swap_b, &swap_ss,
		&push_a, &push_b,
		&rotate_a, &rotate_b, &rotate_rr,
		&rev_rotate_a, &rev_rotate_b, &rev_rotate_rrr
	};
	t_list2		*cmd;

	cmd = stacks->cmd;
	while (cmd)
	{
		f[cmd->index](stacks);
		cmd = cmd->next;
	}
}

static BOOL	get_command(t_stacks *stacks, char *buffer)
{
	static char	*cmd_str[11] =
	{
		"sa", "sb", "ss",
		"pa", "pb",
		"ra", "rb", "rr",
		"rra", "rrb", "rrr"
	};
	int			i;

	i = 0;
	while (i < 11)
	{
		if ((i < 8 && str_n_comp(cmd_str[i], buffer, 3) == 0)
			|| (i < 11 && str_n_comp(cmd_str[i], buffer, 4) == 0))
		{
			add_command(stacks, i);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

void	build_command_list(t_stacks *stacks)
{
	char	*line;
	char	*buffer;
	BOOL	eof;

	buffer = NULL;
	eof = FALSE;
	while (!eof)
	{
		get_next_line(0, &buffer, &line, &eof);
		if (!eof && !get_command(stacks, line))
		{
			free(buffer);
			free(line);
			exit_program(stacks, TRUE);
		}
		free(line);
	}
}

int	main(int ac, char **av)
{
	t_stacks	stacks;

	init_zero(&stacks, sizeof(stacks));
	build_list(&stacks, ac - 1, &(av[1]));
	check_doubles(&stacks);
	if (stacks.total_size > 1 && stacks.total_size <= 5000)
	{
		build_command_list(&stacks);
		apply_commands(&stacks);
		if (checkifsort(&stacks))
			write(1, "OK\n", 3);
		else
			write(2, "KO\n", 3);
	}
	exit_program(&stacks, FALSE);
	return (1);
}
