/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:17:50 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/05 18:37:08 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "buffer.h"

BOOL    checkifsort(t_swap *swap)
{
	t_list  *tmp_list;
	int             tmp_int;
	int             tmp_int2;

	tmp_list = swap->numbers;
	if (swap->size2 > 0)
	{
		return (FALSE);
	//	write(1, "Error: wrong sort\n", 18);
	//	exit_program(swap, FALSE);
	}
	while (tmp_list->next)
	{
		tmp_int = *((int *)(tmp_list->object));
		tmp_int2 = *((int *)(tmp_list->next->object));
		if (tmp_int > tmp_int2)
		{
			return (FALSE);
//			write(1, "Error: not sorted\n", 18);
//			exit_program(swap, FALSE);
		}
		tmp_list = tmp_list->next;
	}
	return (TRUE);
}

void	exit_program(t_swap *swap, BOOL error)
{
	ft_lstclear(&(swap->numbers), &free);
	if (error)
		write(2, "Error\n", 6);
	exit(1);
}

int	main(int ac, char **av)
{
	t_swap	swap;

	init_buffer();
	init_zero(&swap, sizeof(swap));
	if (!build_list(&swap, ac - 1, &(av[1]))
			|| !check_doubles(&swap, swap.numbers))
		exit_program(&swap, TRUE);
	select_algo(&swap);
	checkifsort(&swap);
	exit_program(&swap, FALSE);
	return (1);
}
