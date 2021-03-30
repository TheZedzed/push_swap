# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azeraoul <azeraoul@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/30 17:48:03 by azeraoul          #+#    #+#              #
#    Updated: 2021/03/30 21:57:43 by azeraoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP	:= push_swap
CHECKER		:= checker
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
LDFLAGS		:= -L ./libft
LDLIBS		:= -lft
RM			:= rm -rf

SRCS_1	:= push_swap.c
OBJS_1	:= $(SRCS_1:.c=.o)
SRCS_2	:= checker.c
OBJS_2	:= $(SRCS_2:.c=.o)
INC_LIB	:= ./libt/include

.Phony:	all libft clean fclean re

all:	libft $(PUSH_SWAP) $(CHECKER)

%.o:	%.c
	@$(CC) $(CFLAGS) -I$(INC_LIB) -c $< -o $@

$(PUSH_SWAP):	libft $(OBJS_1)
	@$(CC) $(CFLAGS) $(OBJS_1) $(LDFLAGS) $(LDLIBS) -o $@

$(CHECKER):	libft $(OBJS_2)
	@$(CC) $(CFLAGS) $(OBJS_2) -o $@

clean:
	@make clean --silent -C .libft/
	@$(RM) $(OBJS_1)
	@$(RM) $(OBJS_2)

fclean:	clean
	@make fclean --silent -C .libft/
	@$(RM) $(PUSH_SWAP) $(CHECKER)

re:	fclean all

libft:
	@make --silent -C .libft/
