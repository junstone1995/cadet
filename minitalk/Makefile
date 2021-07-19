# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/17 19:03:31 by junseole          #+#    #+#              #
#    Updated: 2021/07/19 18:59:20 by junseole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wextra -Wall -Werror
AR = ar rcs

TARGET1 = server
TARGET2 = client

S_SRC = server.c \
		subtool.c

C_SRC = client.c \
		subtool.c

BS_SRC = server_bonus.c \
		subtool.c

OBJS1 = $(S_SRC:.c=.o)
OBJS2 = $(C_SRC:.c=.o)
BOBJS1 = $(BS_SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I.

$(TARGET1): $(OBJS1)
	$(CC) $(CFLAGS) $^ -o $@

$(TARGET2): $(OBJS2)
	$(CC) $(CFLAGS) $^ -o $@

bonus : $(BOBJS1)
	rm -rf $(TARGET1)
	$(AR) $(TARGET1) $^

all: $(TARGET1) $(TARGET2)

fclean: clean
	rm -rf $(TARGET1) $(TARGET2)

clean:
	rm -rf $(OBJS1) $(OBJS2) $(BOBJS1) $(BOBJS2)

re: fclean all

.PHONY : all fclean clean re
