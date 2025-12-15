NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c ft_atol.c commands/commands_one.c commands/commands_two.c init_stack.c \
		utils/ft_node_add_new.c utils/push_swap_algorithm_2.c utils/math_utils.c \
		utils/push_swap_algorithm_3.c push_swap_algorithm.c utils/utils_functions.c
BONUS_SRCS = bonus/checker_bonus.c bonus/checker_instructions_bonus.c bonus/checker_process_bonus.c \
		ft_atol.c commands/commands_one.c commands/commands_two.c init_stack.c \
		utils/ft_node_add_new.c utils/push_swap_algorithm_2.c utils/math_utils.c \
		utils/push_swap_algorithm_3.c push_swap_algorithm.c get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c utils/utils_functions.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(BONUS_SRCS:.c=.o)
libft_DIR = libft
libft_LIB = $(libft_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(libft_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(libft_LIB) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS)
	$(MAKE) -C $(libft_DIR)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(libft_LIB) -o $(BONUS_NAME)

clean:
	rm -f $(OBJS) $(OBJS_BONUS) $(BONUS_FILE)
	$(MAKE) -C $(libft_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME) $(BONUS_FILE)
	$(MAKE) -C $(libft_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus