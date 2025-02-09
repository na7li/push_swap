CC                  = cc
CFLAGS              = -Wall -Werror -Wextra
RM                  = rm -rf

SRC_DIR             = ../mandatory/

NAME                = ../checker

SRCS		= checker.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
			  $(SRC_DIR)MainLogic/pushswap_utils.c \
			  $(SRC_DIR)Parsing/input_validation.c $(SRC_DIR)Parsing/parsing.c \
			  $(SRC_DIR)SortStacks/sort_large_stack_1.c $(SRC_DIR)SortStacks/sort_large_stack_2.c $(SRC_DIR)SortStacks/sort_small_stack.c \
			  $(SRC_DIR)StackUtils/push.c $(SRC_DIR)StackUtils/rotate.c $(SRC_DIR)StackUtils/rrotate.c $(SRC_DIR)StackUtils/stack_utils.c $(SRC_DIR)StackUtils/swap.c \
			  $(SRC_DIR)Utilities/ft_atol.c $(SRC_DIR)Utilities/ft_split.c $(SRC_DIR)Utilities/number_of_digits.c
SRCS_OBJ	= $(SRCS:%.c=%.o)


all: $(NAME) clean

$(NAME): $(SRCS_OBJ)
	@$(CC) $(SRCS_OBJ) -o $(NAME)
	@echo "checker is compiled successfully 🎉"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(SRCS_OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re