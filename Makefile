NAME = push_swap
CC = cc
LIBFT = lib/libft/libft.so
FLAGS = -Werror -Wall -Wextra -g
DIROBJS = .objs
OBJS = $(SRCS:%.c=$(DIROBJS)/%.o)
HEADER = -I lib/libft -I includes/
SRCS = src/push_swap.c \
	   src/clear_stack.c \
	   src/parsing/parsing_utils.c \
	   src/parsing/parsing.c \
	   src/algo/big_sort_utils.c \
	   src/algo/big_sort_utils2.c \
	   src/algo/big_sort.c \
	   src/algo/small_sort.c \
	   src/algo/sort.c \
	   src/stack_move.c \
	   src/stack_move2.c \

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(HEADER) -o $@
$(DIROBJS)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(HEADER) $< -c -o $@
$(LIBFT):
	make -C lib/libft/ 

	
clean:
	@rm -rf $(DIROBJS)
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean all re fclean
