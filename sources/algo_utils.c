/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:52:52 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/07 18:27:11 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "buffer.h"

t_list	*duplicate_list(t_swap *swap, t_list *original)
{
	t_list  *new;
	t_list  *first;

	first = NULL;
	while (original)
	{
		new = malloc(sizeof(t_list));
		if (!new)
			exit_program(swap, FALSE);
		new->object = malloc(sizeof(void *));
		if (!(new->object))
		{
			free(new);
			exit_program(swap, FALSE);
		}
		*((int *)(new->object)) = *((int *)(original->object));
		new->index = original->index;
		ft_lstadd_back(&first, new);
		original = original->next;
	}
	return (first);
}

static void     display_stacks2(t_list *tmp, t_list *tmp2)
{
	while (tmp || tmp2)
	{
		if (tmp)
		{
			write_int_buffer(*((int *)(tmp->object)));
//			write_char_buffer(' ', 2); 
//			write_int_buffer(tmp->index);
			tmp = tmp->next;
		}
		else
			write_char_buffer(' ', 2); 
		write_char_buffer(' ', 10);
		if (tmp2)
		{
			write_int_buffer(*((int *)(tmp2->object)));
//			write_char_buffer(' ', 2); 
//			write_int_buffer(tmp2->index);
			tmp2 = tmp2->next;
		}
		else
			write_char_buffer(' ', 2); 
		write_char_buffer('\n', 1); 
	}
}

void    display_stacks(t_swap *swap)
{
	print_buffer(1);
	write_char_buffer('\n', 2); 
	display_stacks2(swap->numbers, swap->numbers2);
	print_buffer(1);
}

void    move_rotate(t_swap *swap, int dir, void (*rot)(t_swap *swap),
		void (*rev)(t_swap *swap))
{
	while (dir != 0)
	{
		if (dir < 0)
		{
			rev(swap);
			dir++;
		}
		else
		{
			rot(swap);
			dir--;
		}
	}
}

BOOL	lf_index_dir(t_list *stack, int size, int index, int *dir)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (stack)
	{
		if (index == stack->index)
		{
			if (i < size / 2 || size == 1)
				*dir = i;
			else
				*dir = i - size;
			return (TRUE);
		}
		stack = stack->next;
		i++;
	}
	return (FALSE);
}
