/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:25:29 by rsanchez          #+#    #+#             */
/*   Updated: 2021/08/02 16:07:55 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

# define BOOL int
# define TRUE 1
# define FALSE 0

# define DOFREE 1
# define DONTFREE 0

typedef struct s_list
{
	void			*object;
	int		index;
	struct s_list	*next;
}					t_list;

/*
 ******************   BYTEWISE & MEMORY  ******************
*/

void	init_zero(void *pt, size_t i);

/*
 *******************  IS? FONCTIONS  *******************
*/

int		is_double_signed(long double doub);
int		is_not_number(long double doub);
int		is_infinite(long double doub);
int		is_whitespace(char c);

/*
 *******************  CHAR & STRING  *******************
*/

char	*substr_free(char *s, size_t start, size_t len, int freestr);
char	*strjoin_free(char *s1, char *s2, int freestr1,	int freestr2);
size_t	string_len(const char *s);
int		shift_right_add(char *str, char c, int i);
int		shift_left_erase(char *str, int i);
int		str_n_comp(char *str, char *str2, int stop);
char	*str_nstr_comp(char *str1, char *str2, size_t size_str2);

/*
 *******************  NB & STRING CONVERSION  *******************
*/

int		utoa_len(unsigned long long nb, int sizebase);
int		utoa_base(unsigned long long nb, char *dest, char *base, int sizebase);
int		itoa_base(long long nb, char *dest, char *base, int sizebase);
int		atoi_windex(const char *str, int *i);
int		ft_atoi(const char *str);
long int		atoli_windex(const char *str, int *i);
long int		ft_atoli(const char *str);
double	atodoub_windex(const char *str, int *i);

/*
 *******************  LINKED LIST  *******************
*/


t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstsecondlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*
 *******************  FILE DESCRIPTOR  *******************
*/

int		get_next_line(int fd, char **line);

#endif
