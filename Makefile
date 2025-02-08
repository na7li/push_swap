CC                  = cc
CFLAGS              = -Wall -Werror -Wextra
RM                  = rm -rf

SRC_DIR             = srcs/
OBJ_DIR             = obj/
BONUS_DIR			= bonus/

NAME                = push_swap
BONUS				= checker

MAIN		= $(SRC_DIR)MainLogic/push_swap.c
MAIN_OBJ	= $(MAIN:%.c=$(OBJ_DIR)%.o)

SRCS		= $(SRC_DIR)MainLogic/pushswap_utils.c \
			  $(SRC_DIR)Parsing/input_validation.c $(SRC_DIR)Parsing/parsing.c \
			  $(SRC_DIR)SortStacks/sort_large_stack_1.c $(SRC_DIR)SortStacks/sort_large_stack_2.c \
			  $(SRC_DIR)SortStacks/sort_small_stack.c \
			  $(SRC_DIR)StackUtils/push.c $(SRC_DIR)StackUtils/rotate.c \
			  $(SRC_DIR)StackUtils/rrotate.c $(SRC_DIR)StackUtils/stack_utils.c \
			  $(SRC_DIR)StackUtils/swap.c \
			  $(SRC_DIR)Utilities/ft_atol.c $(SRC_DIR)Utilities/ft_split.c $(SRC_DIR)Utilities/number_of_digits.c
SRCS_OBJ	= $(SRCS:%.c=$(OBJ_DIR)%.o)

BONUS_SRCS	=	$(BONUS_DIR)checker \
				$(BONUS_DIR)get_next_line/get_next_line.c \
				$(BONUS_DIR)get_next_line/get_next_line_utils.c
BONUS_OBJ	=	$(BONUS_SRCS:%.c=$(OBJ_DIR)%.o)


all: $(NAME)
bonus: $(SRCS_OBJ) $(BONUS_OBJ)
	@$(CC) $(SRCS_OBJ) $(BONUS_OBJ) -o $(BONUS)


$(NAME): $(SRCS_OBJ) $(MAIN_OBJ)
	@$(CC) $(SRCS_OBJ) $(MAIN_OBJ) -o $(NAME)

$(OBJ_DIR)%.o: %.c push_swap.h
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(SRCS_OBJ) $(BONUS_OBJ) $(MAIN_OBJ)
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME) $(BONUS)

re: fclean all

de: all clean

.PHONY: all bonus clean fclean re de