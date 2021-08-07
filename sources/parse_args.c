/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:00:17 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/03 00:44:08 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static BOOL	check_doubles2(t_list *list, t_list *list2, int tmp_int, int *count)
{
	int	check;
	int	is_passed;

	check = 0;
	is_passed = FALSE;
	list->index = 0;
	while (list2)
	{
		if (list != list2 && tmp_int == *((int *)(list2->object)))
			return (FALSE);
		if (tmp_int > *((int *)(list2->object)))
		{
			if (is_passed)
				check++;
			list->index++;
		}
		if (list == list2)
			is_passed = TRUE;
		list2 = list2->next;
	}
	if (!check)
		(*count)++;
	return (TRUE);
}

BOOL	check_doubles(t_swap *swap, t_list *list)
{
	int		tmp_int;
	int		count;

	count = 0;
	while (list)
	{
		tmp_int = *((int *)(list->object));
		if (!check_doubles2(list, swap->numbers, tmp_int, &count))
			return (FALSE);
		list = list->next;
	}
	if (count == swap->size)
		exit_program(swap, FALSE);
	return (TRUE);
}

static int	new_atoi(t_swap *swap, char *str, int *i)
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
		if (nb >= 2000000000
			|| (nb >= 214748364
				&& (str[(*i)] > '8' || (neg == 1 && str[(*i)] > '7'))))
			exit_program(swap, TRUE);
		nb *= 10;
		nb += str[(*i)] - '0';
		(*i)++;
	}
	if (str[*i] && !is_whitespace(str[*i]))
		exit_program(swap, TRUE);
	while (is_whitespace(str[*i]))
		(*i)++;
	return (nb * neg);
}

static BOOL	add_link(t_swap *swap, char *str, int *i)
{
	int		*tmp_object;
	t_list	*tmp_list;

	if ((str[*i] == '+' || str[*i] == '-')
		&& !(str[(*i) + 1] >= '0' && str[*(i) + 1] <= '9'))
		return (FALSE);
	tmp_object = malloc(sizeof(int));
	if (!tmp_object)
		return (FALSE);
	*tmp_object = new_atoi(swap, str, i);
	tmp_list = ft_lstnew(tmp_object);
	if (!tmp_list)
	{
		free(tmp_object);
		return (FALSE);
	}
	ft_lstadd_back(&(swap->numbers), tmp_list);
	swap->size++;
	swap->total_size++;
	return (TRUE);
}

BOOL	build_list(t_swap *swap, int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		if (!av[i][j])
			return (FALSE);
		while (av[i][j])
		{
			while (is_whitespace(av[i][j]))
				j++;
			if (av[i][j] == '+' || av[i][j] == '-'
				|| (av[i][j] >= '0' && av[i][j] <= '9'))
			{
				if (!add_link(swap, av[i], &j))
					return (FALSE);
			}
			else
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}
