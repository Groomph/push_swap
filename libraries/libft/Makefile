# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/15 14:25:42 by rsanchez          #+#    #+#              #
#    Updated: 2021/08/30 14:48:22 by rsanchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC	= clang

CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

HEADER	= includes

NB_STR	= convert_nb_string

DISPLAY	= display

FD	= file_descriptor

IS_FCT	= is?_functions

STRING	= string

LIST	= linked_list

LIST2	= linked_list2

DIR_S	= sources

DIR_O	= temporary

SOURCES	= init_zero.c valeur_absolue.c \
	  ${IS_FCT}/is_double_signed.c ${IS_FCT}/is_infinite.c \
	  ${IS_FCT}/is_not_number.c $(IS_FCT)/is_whitespace.c \
	  ${STRING}/shift_left_erase.c ${STRING}/shift_right_add.c \
	  ${STRING}/str_n_comp.c ${STRING}/str_nstr_comp.c \
	  ${STRING}/string_len.c ${STRING}/strjoin_free.c ${STRING}/substr_free.c \
	  ${NB_STR}/utoa_len.c ${NB_STR}/utoa_base.c \
	  $(NB_STR)/itoa_base.c $(NB_STR)/atoi.c \
	  $(NB_STR)/atoli.c ${NB_STR}/atodoub_windex.c \
	  $(LIST)/ft_lstadd_back.c $(LIST)/ft_lstadd_front.c \
	  $(LIST)/ft_lstclear.c $(LIST)/ft_lstlast.c \
	  $(LIST)/ft_lstsecondlast.c $(LIST)/lst_duplicate.c \
	  $(LIST2)/lst2_addback.c $(LIST2)/lst2_addfront.c \
	  $(LIST2)/lst2_clear.c $(LIST2)/lst2_getlast.c \
	  $(LIST2)/lst2_getsecondlast.c $(LIST2)/lst2_duplicate.c \
	  ${FD}/get_next_line.c \
	  $(DISPLAY)/buffer.c $(DISPLAY)/buffer_conversion.c

SRCS	= $(addprefix $(DIR_S)/,$(SOURCES))

OBJS	= $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

#OBJS	= ${SRCS:.c=.o}
#BOBJS	= ${BSRCS:.c=.o}

$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS}

$(DIR_O)/%.o: $(DIR_S)/%.c
	mkdir -p $(DIR_O)
	mkdir -p $(DIR_O)/$(NB_STR)
	mkdir -p $(DIR_O)/$(DISPLAY)
	mkdir -p $(DIR_O)/$(FD)
	mkdir -p $(DIR_O)/$(IS_FCT)
	mkdir -p $(DIR_O)/$(STRING)
	mkdir -p $(DIR_O)/$(LIST)
	mkdir -p $(DIR_O)/$(LIST2)
	$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

all:		${NAME}

clean:
		${RM} ${OBJS}
		${RM}r $(DIR_O)

fclean:		clean
		${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
