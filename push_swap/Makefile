# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 17:05:37 by junseole          #+#    #+#              #
#    Updated: 2021/10/19 17:14:03 by junseole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = libft
LIBFT_LIB = libft.a

SRCS		= func_oper.c \
				func_oper_a.c \
				func_oper_b.c \
				func_sorted_three.c \
				func_sorted.c \
				main.c \
				push_swap.C
OBJS		= $(SRCS:.c = .o)
HEADER		= push_swap.h
RM			= rm -f
LIBC		= ar rc
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

