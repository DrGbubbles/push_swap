NAME = push_swap

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

$(NAME): $(OBJS)
	cc -Wall -Wextra -Werror -o $(NAME) $(OBJS) -L./libft -lft

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean re clean