/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 07:56:16 by romain            #+#    #+#             */
/*   Updated: 2021/07/25 10:04:29 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	itoa_base(long long int nb, char *dest, char *base, int sizebase)
{
	unsigned long long int tmp;

	if (nb < 0)
	{
		tmp = nb * -1;
		dest[0] = '-';
		return (utoa_base(tmp, &(dest[1]), base, sizebase) + 1);
	}
	return (utoa_base(nb, dest, base, sizebase));
}
