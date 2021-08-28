/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2_getsecondlast.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:57:00 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/24 17:42:52 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list2	*lst2_getsecondlast(t_list2 *lst)
{
	if (!lst || !lst->next->next)
		return (lst);
	return (lst2_getsecondlast(lst->next));
}
