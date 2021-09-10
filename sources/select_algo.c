/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 12:44:09 by rsanchez          #+#    #+#             */
/*   Updated: 2021/09/10 14:36:59 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void (*g_algo_functions[6])(t_stacks *stacks) =
{
	&quicksort_rec,
	&insert_opti,
	&insert_opti_presort,
	&double_insert,
	&radix,
	NULL
};

static char	*str[6] =
{
	"1: algo pivot/quicksort: ",
	"2: algo insertion optimisee: ",
	"3: algo insertion optimisee avec prétri: ",
	"4: algo insertion mid/extremite: ",
	"5: algo radix: ",
	NULL
};

#include <stdio.h>

void	init_copy(t_stacks *stacks, t_stacks *copy)
{
	lst2_clear(&(copy->a), &free);
	lst2_clear(&(copy->b), &free);
	copy->a = lst2_duplicate(stacks->a);
	if (!copy->a && stacks->a)
		exit_program(stacks, 2);
	copy->b = lst2_duplicate(stacks->b);
	if (!copy->b && stacks->b)
		exit_program(stacks, 2);
	copy->size_a = stacks->size_a;
	copy->size_b = stacks->size_b;
	copy->last_a = lst2_getlast(copy->a);
	copy->last_b = lst2_getlast(copy->b);
	copy->total_size = stacks->total_size;
	copy->count = 0;
	copy->cmd = NULL;
}

static void	select_algo2(t_stacks *stacks)//, void (*f[])(t_stacks *))
{
	int	i;
	int	results;
	t_stacks	copy;

	i = 0;
	results = 2000000000;
	init_zero(&copy, sizeof(copy));
	while (g_algo_functions[i] != NULL)
	{
		init_copy(stacks, &copy);
		g_algo_functions[i](&copy);
		optimize_command(&copy);
		if (copy.count < results && checkifsort(&copy))
		{
			results = copy.count;
			if (stacks->cmd)
				lst2_clear(&(stacks->cmd), &free);
			stacks->cmd = copy.cmd;
		}
		else
			lst2_clear(&(copy.cmd), &free);
		printf("\n%s %i\n", str[i], copy.count);
		if (!checkifsort(&copy))
		{
			write(1, "Error: not sorted\n", 18);
//			display_stacks(&copy);
		}
		if (copy.extra == 0)
			i++;
	}
	lst2_clear(&(copy.a), &free);
	lst2_clear(&(copy.b), &free);
}

void	select_algo(t_stacks *stacks)
{
	if (stacks->size_a == 2)
		swap_a(stacks);
	else if (stacks->size_a <= 5)
	{
		set_group(stacks->a, 0);
		sort_five(stacks, stacks->size_a, 0, FALSE);
	}
	else
		select_algo2(stacks);
//	if (checkifsort(stacks))
//	display_commands(stacks->cmd);
//	display_stacks(stacks);
//	display_stacks_rev(stacks);
//	else
//		write(1, "Error: not sorted\n", 18);
}
