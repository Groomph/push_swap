/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:00:17 by rsanchez          #+#    #+#             */
/*   Updated: 2021/10/11 17:28:32 by romain           ###   ########.fr       */
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
	unsigned long int	nb;
	int					n;

	nb = 0;
	n = 1;
	if (str[(*i)] == '-' && ++(*i))
		n = -1;
	else if (str[(*i)] == '+')
		(*i)++;
	while (str[(*i)] >= '0' && str[(*i)] <= '9')
	{
		if ((nb > 2147483648 && n == -1) || (nb > 2147483647 && n == 1))
			exit_program(stacks, TRUE);
		nb *= 10;
		nb += str[(*i)] - '0';
		(*i)++;
	}
	if ((nb > 2147483648 && n == -1) || (nb > 2147483647 && n == 1))
		exit_program(stacks, TRUE);
	if (str[*i] && !is_whitespace(str[*i]))
		exit_program(stacks, TRUE);
	while (is_whitespace(str[*i]))
		(*i)++;
	return (nb * n);
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
