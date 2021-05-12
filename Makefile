# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azeraoul <azeraoul@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/30 17:48:03 by azeraoul          #+#    #+#              #
#    Updated: 2021/05/06 17:08:35 by azeraoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP	:= push_swap
CHECKER		:= checker
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g
LDFLAGS		:= -L ./libft
LDLIBS		:= -lft
RM			:= rm -rf
LIBFT	:= libft.a

SRCS_1	:= $(addprefix ./srcs/, push_swap.c)
SRCS_2	:= $(addprefix ./srcs/, checker.c parse.c parse_utils.c print_n_free.c sort.c sort_func.c)
OBJS_1	:= $(SRCS_1:.c=.o)
OBJS_2	:= $(SRCS_2:.c=.o)
INC_LIB	:= -I./libft/include -I./include

.Phony:	all clean fclean re all

all:	$(LIBFT) $(PUSH_SWAP) $(CHECKER)

%.o:	%.c
	$(CC) $(CFLAGS) $(INC_LIB) -c $< -o $@

$(LIBFT):
	make --silent -C libft/

$(PUSH_SWAP): $(OBJS_1)
	$(CC) $(CFLAGS) $(OBJS_1) $(LDFLAGS) $(LDLIBS) -o $@

$(CHECKER): $(OBJS_2)
	$(CC) $(CFLAGS) $(OBJS_2) $(LDFLAGS) $(LDLIBS) -o $@

clean:
	make clean --silent -C libft/
	$(RM) $(OBJS_1)
	$(RM) $(OBJS_2)

fclean:	clean
	make fclean --silent -C libft/
	$(RM) $(PUSH_SWAP) $(CHECKER)

re:	fclean all
