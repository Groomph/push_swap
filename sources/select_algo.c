/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 12:44:09 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/28 08:15:49 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void (*g_algo_functions[2])(t_stacks *stacks) =
{
	&quicksort_rec,
	NULL
};

static char	*str[2] =
{
	"1: algo pivot/quicksort: ",
	NULL
};

#include <stdio.h>

void	init_copy(t_stacks *stacks, t_stacks *copy)
{
	ft_lstclear(&(copy->a), &free);
	ft_lstclear(&(copy->b), &free);
	copy->a = lst_duplicate(stacks->a);
	if (!copy->a && stacks->a)
		exit_program(stacks, 2);
	copy->b = lst_duplicate(stacks->b);
	if (!copy->b && stacks->b)
		exit_program(stacks, 2);
	copy->size_a = stacks->size_a;
	copy->size_b = stacks->size_b;
	copy->total_size = stacks->total_size;
	copy->count = 0;
	copy->cmd = NULL;
}

static void	select_algo2(t_stacks *stacks)//, void (*f[])(t_stacks *))
{
	int	i;
	int	results;
	t_stacks	copy;

	i = -1;
	results = 2000000000;
	init_zero(&copy, sizeof(copy));
	while (g_algo_functions[++i] != NULL)
	{
		init_copy(stacks, &copy);
		g_algo_functions[i](&copy);
		if (copy.count < results)
		{
			results = copy.count;
			if (stacks->cmd)
				lst2_clear(&(stacks->cmd), &free);
			stacks->cmd = copy.cmd;
		}
		else
			lst2_clear(&(copy.cmd), &free);
		printf("\n%s %i\n", str[i], copy.count);
	}
	ft_lstclear(&(copy.a), &free);
	ft_lstclear(&(copy.b), &free);
}

void	select_algo(t_stacks *stacks)
{
	if (stacks->size_a == 2)
		swap_a(stacks);
	else if (stacks->size_a <= 5)
		sort_five(stacks);
	else
		select_algo2(stacks);
//	if (checkifsort(stacks))
//		display_commands(stacks->cmd);
//	else
//		write(1, "Error: not sorted\n", 18);
}
