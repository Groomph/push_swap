/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:58:16 by rsanchez          #+#    #+#             */
/*   Updated: 2021/07/25 14:48:59 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*pt;

	pt = malloc(sizeof(t_list));
	if (pt)
	{
		pt->object = content;
		pt->next = NULL;
	}
	return (pt);
}
