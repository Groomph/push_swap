/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkifsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:52:52 by rsanchez          #+#    #+#             */
/*   Updated: 2021/09/10 20:34:53 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

BOOL	checkifsort(t_stacks *stacks)
{
	t_list2	*tmp_list;

	tmp_list = stacks->a;
	if (stacks->size_b > 0)
		return (FALSE);
	while (tmp_list->next)
	{
		if (tmp_list->nb > tmp_list->next->nb)
			return (FALSE);
		tmp_list = tmp_list->next;
	}
	return (TRUE);
}
