/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valeur_absolue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:56:45 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/16 18:00:11 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int      valeur_absolue(int nb)
{
        if (nb < 0)
                return (nb * -1);
        return (nb);
}
