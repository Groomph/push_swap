# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 16:05:34 by rsanchez          #+#    #+#              #
#    Updated: 2021/08/26 19:04:31 by rsanchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = clang

#CFLAGS = -Wall -Wextra -Werror

FLAGSHARD = -Weverything

LIB	= libraries

LIBFT	= -L $(LIB)/libft/ -lft

HEADER = includes

DIR_S = sources

DIR_OPE = operations

DIR_A1 = 5orless

DIR_A2 = quick_sort

DIR_UTILS = algo_utils

DIR_O = temporary

SOURCES = main.c parse_args.c select_algo.c display.c \
	  $(DIR_OPE)/cmd_utils.c $(DIR_OPE)/swap.c $(DIR_OPE)/push.c \
	  $(DIR_OPE)/rotate.c $(DIR_OPE)/rev_rotate.c \
	  $(DIR_UTILS)/checkifsort.c $(DIR_UTILS)/group.c \
	  $(DIR_UTILS)/is_sorted.c $(DIR_UTILS)/search_move.c \
	  $(DIR_A1)/5orless.c \
	  $(DIR_A2)/quick_sort.c \
	  $(DIR_A2)/sort_b.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIB)/libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(DIR_O)/%.o: $(DIR_S)/%.c
	mkdir -p $(DIR_O)
	mkdir -p $(DIR_O)/$(DIR_OPE)
	mkdir -p $(DIR_O)/$(DIR_UTILS)
	mkdir -p $(DIR_O)/$(DIR_A1)
	mkdir -p $(DIR_O)/$(DIR_A2)
	$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

norme:
	@echo
	norminette $(HEADER)/
	@echo
	norminette $(DIR_S)/

clean:
	rm -f $(OBJS)
	rm -rf $(DIR_O)
	make fclean -C $(LIB)/libft

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re bonus
