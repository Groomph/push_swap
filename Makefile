# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 16:05:34 by rsanchez          #+#    #+#              #
#    Updated: 2021/08/07 02:03:32 by romain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = clang

CFLAGS = -Wall -Wextra -Werror

FLAGSHARD = -Weverything

LIB	= libraries

LIBFT	= -L $(LIB)/libft/ -lft

HEADER = includes

DIR_S = sources

DIR_OPE = operations

DIR_A1 = algo_1_divise_par_2

DIR_A15 = algo_15_divise_par_2

DIR_A2 = algo_2_divise_par_3

DIR_A25 = algo_25_divise_par_3

DIR_A3 = algo_3_divise_par_x

DIR_A35 = algo_35_divise_par_x

DIR_A25 = algo_25_divise_par_3

DIR_A25 = algo_25_divise_par_3

DIR_O = temporary

SOURCES = main.c parse_args.c select_algo.c algo_utils.c \
	  $(DIR_A1)/algo_1.c $(DIR_A1)/algo_1_utils.c \
	  $(DIR_A15)/algo_15.c \
	  $(DIR_A2)/algo_2.c \
	  $(DIR_A25)/algo_25.c \
	  $(DIR_A3)/algo_3.c \
	  $(DIR_OPE)/swap.c $(DIR_OPE)/push.c \
	  $(DIR_OPE)/rotate.c $(DIR_OPE)/rev_rotate.c 

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
	mkdir -p $(DIR_O)/$(DIR_A1)
	mkdir -p $(DIR_O)/$(DIR_A15)
	mkdir -p $(DIR_O)/$(DIR_A2)
	mkdir -p $(DIR_O)/$(DIR_A25)
	mkdir -p $(DIR_O)/$(DIR_A3)
	mkdir -p $(DIR_O)/$(DIR_A35)
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
