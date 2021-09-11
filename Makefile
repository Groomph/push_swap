# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 16:05:34 by rsanchez          #+#    #+#              #
#    Updated: 2021/09/11 03:14:43 by rsanchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAMEB = checker

NAMEG = generator

CC = clang

CFLAGS = -Wall -Wextra -Werror

FLAGSHARD = -Weverything

LIB	= libraries

LIBFT	= -L $(LIB)/libft/ -lft

HEADER = includes

DIR_S = sources

DIR_SB = bonus

DIR_SG = nb_generator

DIR_OPE = operations

DIR_ALG = algos

DIR_A1 = $(DIR_ALG)/5orless

DIR_A2 = $(DIR_ALG)/quick_sort

DIR_A3 = $(DIR_ALG)/insert_opti

DIR_A4 = $(DIR_ALG)/double_insert

DIR_A5 = $(DIR_ALG)/radix

DIR_PRE = $(DIR_ALG)/presort

DIR_UTILS = algo_utils

DIR_O = temporary

DIR_OB = temporary_bonus

DIR_OG = temporary_generator

SOURCES = main.c parse_args.c select_algo.c display.c \
	  $(DIR_OPE)/cmd_utils.c $(DIR_OPE)/swap.c $(DIR_OPE)/push.c \
	  $(DIR_OPE)/rotate.c $(DIR_OPE)/rev_rotate.c $(DIR_OPE)/optimize.c \
	  $(DIR_UTILS)/checkifsort.c $(DIR_UTILS)/group.c \
	  $(DIR_UTILS)/is_sorted.c $(DIR_UTILS)/search_move.c \
	  $(DIR_A1)/5orless.c $(DIR_A1)/5orless_b.c $(DIR_A1)/three_123.c \
	  $(DIR_A1)/topthree_123.c $(DIR_A1)/topthree_b_123.c \
	  $(DIR_A2)/quick_sort.c $(DIR_A2)/sort_b.c $(DIR_A2)/utils.c \
	  $(DIR_A3)/insert_opti.c $(DIR_A3)/insert_opti_presort.c \
	  $(DIR_A3)/utils.c \
	  $(DIR_A4)/double_insert.c $(DIR_A4)/utils.c \
	  $(DIR_A5)/radix.c $(DIR_A5)/utils.c \
	  $(DIR_PRE)/presort.c

SOURCESB = main.c parse_args.c checkifsort.c display.c \
	  $(DIR_OPE)/cmd_utils.c $(DIR_OPE)/swap.c $(DIR_OPE)/push.c \
	  $(DIR_OPE)/rotate.c $(DIR_OPE)/rev_rotate.c

SOURCESG = main.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

SRCSB = $(addprefix $(DIR_SB)/,$(SOURCESB))

OBJSB = $(addprefix $(DIR_OB)/,$(SOURCESB:.c=.o))

SRCSG = $(addprefix $(DIR_SG)/,$(SOURCESG))

OBJSG = $(addprefix $(DIR_OG)/,$(SOURCESG:.c=.o))

all: $(NAME)

bonus: $(NAMEB)

$(NAME): $(OBJS)
	make -C $(LIB)/libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(NAMEB): $(OBJSB)
	make -C $(LIB)/libft
	$(CC) $(CFLAGS) -o $(NAMEB) $(OBJSB) $(LIBFT)

$(NAMEG): $(OBJSG)
	make -C $(LIB)/libft
	$(CC) $(CFLAGS) -o $(NAMEG) $(OBJSG) $(LIBFT)

$(DIR_O)/%.o: $(DIR_S)/%.c
	mkdir -p $(DIR_O)
	mkdir -p $(DIR_O)/$(DIR_OPE)
	mkdir -p $(DIR_O)/$(DIR_UTILS)
	mkdir -p $(DIR_O)/$(DIR_ALG)
	mkdir -p $(DIR_O)/$(DIR_A1)
	mkdir -p $(DIR_O)/$(DIR_A2)
	mkdir -p $(DIR_O)/$(DIR_A3)
	mkdir -p $(DIR_O)/$(DIR_A4)
	mkdir -p $(DIR_O)/$(DIR_A5)
	mkdir -p $(DIR_O)/$(DIR_PRE)
	$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

$(DIR_OB)/%.o: $(DIR_SB)/%.c
	mkdir -p $(DIR_OB)
	mkdir -p $(DIR_OB)/$(DIR_OPE)
	$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

$(DIR_OG)/%.o: $(DIR_SG)/%.c
	mkdir -p $(DIR_OG)
	$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

norme:
	@echo
	norminette $(LIB)/
	@echo
	norminette $(HEADER)/
	@echo
	norminette $(DIR_S)/
	@echo
	norminette $(DIR_SB)/
	@echo
	norminette $(DIR_SG)/

clean:
	rm -rf $(DIR_O)
	rm -rf $(DIR_OB)
	rm -rf $(DIR_OG)
	make fclean -C $(LIB)/libft

fclean: clean
	rm -f $(NAME)
	rm -f $(NAMEB)
	rm -f $(NAMEG)

re: fclean all

.PHONY:		all clean fclean re bonus norme
