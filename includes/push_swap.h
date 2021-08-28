/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:16:13 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/28 08:18:55 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

 typedef struct  s_stacks
 {
	t_list  *a;
	int     size_a;
	t_list  *b;
	int     size_b;
	int	total_size;
	t_list2	*cmd;
	t_list2	*last_cmd;
	int	count;
	int	extra;
}		t_stacks;

typedef struct s_lookfornumber
{
	int	nb;
	int	index;
	int	i;
}		t_lfnb;

enum	e_command
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

void	build_list(t_stacks *stacks, int ac, char **av);
void	check_doubles(t_stacks *stacks);
void	exit_program(t_stacks *stacks, BOOL error);
void	select_algo(t_stacks *stacks);

void	display_commands(t_list2 *cmd);
void	display_all(t_stacks *stacks);
void	display_stacks(t_stacks *stacks);

void	swap_a(t_stacks *stacks);
void	swap_b(t_stacks *stacks);
void	swap_ss(t_stacks *stacks);
void	push_a(t_stacks *stacks);
void	push_b(t_stacks *stacks);
void	rotate_a(t_stacks *stacks);
void	rotate_b(t_stacks *stacks);
void	rotate_rr(t_stacks *stacks);
void	rev_rotate_a(t_stacks *stacks);
void	rev_rotate_b(t_stacks *stacks);
void	rev_rotate_rrr(t_stacks *stacks);
void	add_command(t_stacks *stacks, char cmd);
void	remove_command(t_stacks *stacks, t_list2 *list);

void	move_rotate(t_stacks *stacks, int dir, void (*rot)(t_stacks *stacks), void (*rev)(t_stacks *stacks));
int	lf_smallest_index_ingroup(t_list *tmp, int group);
BOOL	lf_index_dir(t_list *stack, int size, int index, int *dir);

BOOL	checkifsort(t_stacks *stacks);

int	get_size_first_group(t_list *stack);
BOOL	group_ispresent(t_list *stack, int group);
void	set_group(t_list *stack, int group);
int	attrib_group(t_list *stacks, int size_stack, int size_group);
BOOL	lf_group_dir(t_list *stack, int size, int group, int *dir);

BOOL	is_sorted_increas(t_list *stack, int max);
BOOL	is_sortable(t_list *stack, int max);

void	sort_five(t_stacks *stacks);

void	quicksort_rec(t_stacks *stacks);
int	get_previous_group(t_stacks *stack, int group);

