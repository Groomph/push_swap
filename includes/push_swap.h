/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:13:01 by romain            #+#    #+#             */
/*   Updated: 2021/08/07 01:51:27 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

 typedef struct  s_swap
 {
	t_list  *numbers;
	int     size;
	t_list  *numbers2;
	int     size2;
	int	total_size;
	BOOL	do_display;
	int	count_test;
	int	extra;
}		t_swap;

typedef struct s_lookfornumber
{
	int	nb;
	int	index;
	int	i;
}		t_lfnb;

BOOL	build_list(t_swap *swap, int ac, char **av);
BOOL	check_doubles(t_swap *swap, t_list *list);
void	exit_program(t_swap *swap, BOOL error);
void	select_algo(t_swap *swap);

void	display_stacks(t_swap *swap);
BOOL	lf_index_dir(t_list *stack, int size, int index, int *dir);
void	move_rotate(t_swap *swap, int dir, void (*rot)(t_swap *swap), void (*rev)(t_swap *swap));
BOOL	checkifsort(t_swap *swap);
t_list	*duplicate_list(t_swap *swap, t_list *original);


void	swap_a(t_swap *swap);
void	swap_b(t_swap *swap);
void	swap_ss(t_swap *swap);
//void	swap_current(t_swap *swap, t_list **current);
void	push_a(t_swap *swap);
void	push_b(t_swap *swap);
//void	push_current(t_swap *swap, t_list **current);
void	rotate_a(t_swap *swap);
void	rotate_b(t_swap *swap);
void	rotate_rr(t_swap *swap);
void	rev_rotate_a(t_swap *swap);
void	rev_rotate_b(t_swap *swap);
void	rev_rotate_rrr(t_swap *swap);

void	algo_1(t_swap *swap);
void	sort_a(t_swap *swap, int size_group);
BOOL	lf_smaller_dir(t_list *stack, int size, int index, int *dir);
BOOL	lf_greater_dir(t_list *stack, int size, int index, int *dir);

void	algo_15(t_swap *swap);
void	sort_a_15(t_swap *swap, int size_group);

void	algo_2(t_swap *swap);
void	sort_a2(t_swap *swap, int size_group);

void	algo_25(t_swap *swap);
void	sort_a25(t_swap *swap, int size_group);

void	algo_3(t_swap *swap);

void	algo_35(t_swap *swap);
void	sort_a35(t_swap *swap, int size_group);
