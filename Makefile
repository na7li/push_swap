CC                  = cc
CFLAGS              = -Wall -Werror -Wextra
RM                  = rm -rf

OBJ_DIR             = obj_files/
NAME                = push_swap

MAIN		= mandatory/MainLogic/push_swap.c
MAIN_OBJ	= $(addprefix $(OBJ_DIR), $(MAIN:.c=.o))

SRCS		= mandatory/MainLogic/pushswap_utils.c \
			  mandatory/Parsing/input_validation.c mandatory/Parsing/parsing.c \
			  mandatory/SortStacks/sort_large_stack_1.c mandatory/SortStacks/sort_large_stack_2.c mandatory/SortStacks/sort_small_stack.c \
			  mandatory/StackUtils/push.c mandatory/StackUtils/rotate.c mandatory/StackUtils/rrotate.c mandatory/StackUtils/stack_utils.c mandatory/StackUtils/swap.c \
			  mandatory/Utilities/ft_atol.c mandatory/Utilities/ft_split.c
SRCS_OBJ	= $(addprefix $(OBJ_DIR), $(SRCS:%.c=%.o))

all: $(NAME)

bonus:
	@make -C bonus

$(NAME): $(MAIN_OBJ) $(SRCS_OBJ)
	@$(CC) $(CFLAGS) $(MAIN_OBJ) $(SRCS_OBJ) -o $(NAME)
	@echo "push_swap is compiled successfully 🎉"

$(OBJ_DIR)%.o: %.c push_swap.h
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C bonus
	@$(RM) $(SRCS_OBJ) $(MAIN_OBJ)
	@$(RM) $(OBJ_DIR)

fclean: clean
	@make fclean -C bonus
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean bonus