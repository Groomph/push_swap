/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:17:50 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/28 03:56:10 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	exit_program(t_stacks *stacks, BOOL error)
{
	ft_lstclear(&(stacks->a), &free);
	ft_lstclear(&(stacks->b), &free);
	lst2_clear(&(stacks->cmd), &free);
	if (error)
	{
		if (error == 2)
			write(2, "Malloc error\n", 13);
		else
			write(2, "Error\n", 6);
	}
	exit(1);
}

int	main(int ac, char **av)
{
	t_stacks	stacks;

	init_zero(&stacks, sizeof(stacks));
	build_list(&stacks, ac - 1, &(av[1]));
	check_doubles(&stacks);
	if (!checkifsort(&stacks))
	{
		select_algo(&stacks);
		printf("size a: %i\n", stacks.size_a);
		printf("size b: %i\n", stacks.size_b);
		printf("total size : %i\n", stacks.total_size);
	}
	exit_program(&stacks, FALSE);
	return (1);
}
