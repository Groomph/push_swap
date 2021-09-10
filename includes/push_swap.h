/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:16:13 by rsanchez          #+#    #+#             */
/*   Updated: 2021/09/10 17:54:58 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

 typedef struct  s_stacks
 {
	t_list2	*a;
	t_list2	*last_a;
	t_list2	*first_locked_a;
	int     size_a;
	t_list2  *b;
	t_list2	*last_b;
	t_list2	*first_locked_b;
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
	RRR,
	ZZZ
};

void	build_list(t_stacks *stacks, int ac, char **av);
void	check_doubles(t_stacks *stacks);
void	exit_program(t_stacks *stacks, BOOL error);
void	select_algo(t_stacks *stacks);

void	display_commands(t_list2 *cmd);
void	display_all(t_stacks *stacks);
void	display_stacks(t_stacks *stacks);
void	display_stacks_rev(t_stacks *stacks);

void	swap_a(t_stacks *stacks);
void	swap_b(t_stacks *stacks);
void	swap_ss(t_stacks *stacks);
void	which_swap(t_stacks *stacks, char c);
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
void	optimize_command(t_stacks *stacks);

t_list2	*get_link_from_dir(t_list2 *first, t_list2 *last, int dir);
void	move_rotate(t_stacks *stacks, int dir, void (*rot)(t_stacks *stacks), void (*rev)(t_stacks *stacks));
int	lf_greatest_index_ingroup(t_list2 *tmp, int group, int *dir, int size);
int	lf_smallest_index_ingroup(t_list2 *tmp, int group, int *dir, int size);
BOOL	lf_index_dir(t_list2 *stack, int size, int index, int *dir);

BOOL	checkifsort(t_stacks *stacks);

int	get_size_first_group(t_list2 *stack);
BOOL	group_ispresent(t_list2 *stack, int group);
void	set_group(t_list2 *stack, int group);
int	attrib_group(t_list2 *stacks, int size_stack, int size_group);
BOOL	lf_group_dir(t_list2 *stack, int size, int group, int *dir);

//BOOL	is_sortable(t_list2 *stack, int max_index);
BOOL	is_sorted_inc(t_list2 *stack, int size, t_list2 *locked, t_list2 *last);
t_list2	*lock_sorted(t_list2 *stack, int size, t_list2 *locked, t_list2 *last);
void	back_to_bot(t_stacks *stacks, int group, char c);

void	sort_five(t_stacks *stacks, int size, int group, BOOL top);
void	three_132(t_stacks *stacks);
void	three_213(t_stacks *stacks);
void	three_231(t_stacks *stacks);
void	three_312(t_stacks *stacks);
void	three_321(t_stacks *stacks);
void	topthree_132(t_stacks *stacks);
void	topthree_213(t_stacks *stacks);
void	topthree_231(t_stacks *stacks);
void	topthree_312(t_stacks *stacks);
void	topthree_321(t_stacks *stacks);
void	sort_five_b(t_stacks *stacks, int size, int group);
void	topthree_b_123(t_stacks *stacks);
void	topthree_b_132(t_stacks *stacks);
void	topthree_b_213(t_stacks *stacks);
void	topthree_b_231(t_stacks *stacks);
void	topthree_b_312(t_stacks *stacks);

void	quicksort_rec(t_stacks *stacks);
void	quicksort_a(t_stacks *stacks, int group);
void	quicksort_b(t_stacks *stack);

void	insert_opti(t_stacks *stacks);
void	insert_opti_presort(t_stacks *stacks);
void	save_result(int *move_ab, int *tmp_ab, int *result);
int	calcul_result(int *tmp_ab);
int	find_nearest_greater(int index, t_list2 *list);
int	find_nearest_smaller(int index, t_list2 *list);

void	double_insert(t_stacks *stacks);
void	sort_a(t_stacks *stacks, int size_group, BOOL first);
int	set_target(t_stacks *stacks, int size_group, int *tar, char c);

void	radix(t_stacks *stacks);
void	radix_sort_a(t_stacks *stacks, int expo);
void	set_target_radix(int *target);
void	attrib_group_radix(t_list2 *stack, int expo, int *tar);

void	presort_2_a(t_stacks *stacks);
void	presort_x_a(t_stacks *stacks, int size_group, BOOL reset_group);
