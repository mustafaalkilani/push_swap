

NAME	= libftprintf.a

SRC = ft_printf.c ft_putchar.c ft_puthex_small.c ft_puthex_caps.c ft_putnbr.c ft_putptr.c ft_putstr.c ft_put_unsigned_nbr.c get_size.c

OBJS = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re