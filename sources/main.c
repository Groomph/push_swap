/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:17:50 by rsanchez          #+#    #+#             */
/*   Updated: 2021/09/11 00:27:52 by rsanchez         ###   ########.fr       */
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
	exit(1);
}

int	main(int ac, char **av)
{
	t_stacks	stacks;

	init_zero(&stacks, sizeof(stacks));
	build_list(&stacks, ac - 1, &(av[1]));
	check_doubles(&stacks);
	if (stacks.total_size > 1 && stacks.total_size <= 5000
		&& !checkifsort(&stacks))
		select_algo(&stacks);
	exit_program(&stacks, FALSE);
	return (1);
}
