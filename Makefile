NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c ft_atol.c commands/commands.c commands/commands_two.c
OBJS = $(SRCS:.c=.o)
ft_printf_DIR = ft_printf
ft_printf_LIB = $(ft_printf_DIR)/libftprintf.a
libft_DIR = libft
libft_LIB = $(libft_DIR)/libft.a
all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(ft_printf_DIR)
	$(MAKE) -C $(libft_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(ft_printf_LIB) $(libft_LIB) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(ft_printf_DIR) clean
	$(MAKE) -C $(libft_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(ft_printf_DIR) fclean
	$(MAKE) -C $(libft_DIR) fclean

re: fclean $(NAME)

.PHONY: all clean fclean re
