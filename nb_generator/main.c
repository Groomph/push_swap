/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:27:57 by rsanchez          #+#    #+#             */
/*   Updated: 2021/09/11 03:09:13 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "buffer.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>

int	*convert_big_to_small(int *tab, int size)
{
	int	i;
	int	i2;
	int	index;
	int	*tab2;

	tab2 = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		i2 = 0;
		index = 0;
		while (i2 < size)
		{
			if (tab[i] > tab[i2])
				index++;
			i2++;
		}
		tab2[i] = index;
		i++;
	}
	free(tab);
	return (tab2);
}

BOOL	check_double(int *tab, int size, int tmp)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tmp == tab[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	display_numbers(int *tab, int size)
{
	int	i;

	init_buffer();
	i = 0;
	while (i < size)
	{
		write_int_buffer(tab[i]);
		write_char_buffer(' ', 1);
		i++;
	}
	free(tab);
	print_buffer(1);
}

void	exit_error(void)
{
	write(1, "error\n", 6);
	exit(1);
}

int	main(int ac, char **av)
{
	int	size;
	int	*tab;
	int	tmp;
	int	i;

	if (ac == 1 || ac > 2)
		exit_error();
	size = ft_atoi(av[1]);
	tab = malloc(sizeof(int) * size);
	if (!tab)
		exit_error();
	i = 0;
	srand(time(NULL));
	while (i < size)
	{
		tmp = rand();
		while (!check_double(tab, i, tmp))
			tmp = rand();
		tab[i] = tmp;
		i++;
	}
	tab = convert_big_to_small(tab, size);
	display_numbers(tab, size);
	return (1);
}
