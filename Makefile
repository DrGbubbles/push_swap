NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = push_swap.c \
		ins_swap.c \
		ins_push.c \
		ins_rotate.c \
		ins_reverse.c \
		sort_simple.c \
		sort_medium.c \
		sort_complex.c \
		sort_adaptive.c \
		input_parsing.c \
		stack_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	cc -Wall -Wextra -Werror $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean


re: fclean all

.PHONY: fclean re clean