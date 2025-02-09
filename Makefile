CC                  = cc
CFLAGS              = -Wall -Werror -Wextra
RM                  = rm -rf

SRC_DIR             = mandatory/
NAME                = push_swap

MAIN		= $(SRC_DIR)MainLogic/push_swap.c
MAIN_OBJ	= $(MAIN:%.c=%.o)

SRCS		= $(SRC_DIR)MainLogic/pushswap_utils.c \
			  $(SRC_DIR)Parsing/input_validation.c $(SRC_DIR)Parsing/parsing.c \
			  $(SRC_DIR)SortStacks/sort_large_stack_1.c $(SRC_DIR)SortStacks/sort_large_stack_2.c $(SRC_DIR)SortStacks/sort_small_stack.c \
			  $(SRC_DIR)StackUtils/push.c $(SRC_DIR)StackUtils/rotate.c $(SRC_DIR)StackUtils/rrotate.c $(SRC_DIR)StackUtils/stack_utils.c $(SRC_DIR)StackUtils/swap.c \
			  $(SRC_DIR)Utilities/ft_atol.c $(SRC_DIR)Utilities/ft_split.c $(SRC_DIR)Utilities/number_of_digits.c
SRCS_OBJ	= $(SRCS:%.c=%.o)

all: $(NAME) clean

$(NAME): $(SRCS_OBJ) $(MAIN_OBJ)
	@$(CC) $(SRCS_OBJ) $(MAIN_OBJ) -o $(NAME)
	@echo "push_swap is compiled successfully 🎉"

%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(SRCS_OBJ) $(MAIN_OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re