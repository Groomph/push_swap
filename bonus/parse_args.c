/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:00:17 by rsanchez          #+#    #+#             */
/*   Updated: 2021/09/11 00:46:18 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_doubles(t_stacks *stacks)
{
	t_list2	*list;
	t_list2	*list2;

	list = stacks->a;
	while (list)
	{
		list->index = 0;
		list->group = 0;
		list2 = stacks->a;
		while (list2)
		{
			if (list != list2 && list->nb == list2->nb)
				exit_program(stacks, TRUE);
			if (list->nb > list2->nb)
				list->index++;
			list2 = list2->next;
		}
		list = list->next;
	}
}

static int	new_atoi(t_stacks *stacks, char *str, int *i)
{
	unsigned int	nb;
	int				neg;

	nb = 0;
	neg = 1;
	if (str[(*i)] == '-' && ++(*i))
		neg *= -1;
	else if (str[(*i)] == '+')
		(*i)++;
	while (str[(*i)] >= '0' && str[(*i)] <= '9')
	{
		if (nb >= 1000000000
			|| (nb >= 214748364
				&& (str[(*i)] > '8' || (neg == 1 && str[(*i)] > '7'))))
			exit_program(stacks, TRUE);
		nb *= 10;
		nb += str[(*i)] - '0';
		(*i)++;
	}
	if (str[*i] && !is_whitespace(str[*i]))
		exit_program(stacks, TRUE);
	while (is_whitespace(str[*i]))
		(*i)++;
	return (nb * neg);
}

static void	add_link(t_stacks *stacks, char *str, int *i)
{
	t_list2	*tmp_list;

	if ((str[*i] == '+' || str[*i] == '-')
		&& !(str[(*i) + 1] >= '0' && str[*(i) + 1] <= '9'))
	{
		exit_program(stacks, TRUE);
	}
	tmp_list = malloc(sizeof(t_list2));
	if (!tmp_list)
		exit_program(stacks, 2);
	tmp_list->nb = new_atoi(stacks, str, i);
	lst2_addback(&(stacks->a), tmp_list, stacks->last_a);
	stacks->last_a = tmp_list;
	stacks->size_a++;
	stacks->total_size++;
}

void	build_list(t_stacks *stacks, int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			while (is_whitespace(av[i][j]))
				j++;
			if (av[i][j] == '+' || av[i][j] == '-'
				|| (av[i][j] >= '0' && av[i][j] <= '9'))
			{
				add_link(stacks, av[i], &j);
			}
			else
				exit_program(stacks, TRUE);
		}
		i++;
	}
}
