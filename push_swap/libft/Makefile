CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
HEADER = libft.h
SRCS = ft_split.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strlen2.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_atoi.c \
		ft_free.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	ar cr $@ $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean
