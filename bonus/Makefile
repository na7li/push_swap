CC                  = cc
CFLAGS              = -Wall -Werror -Wextra
RM                  = rm -rf

BONUS_DIR			= ../bonus/
MANDATORY_DIR		= ../mandatory/
OBJ_DIR             = ../obj_files/bonus/

NAME                = ../checker

BONUS_SRCS			= checker.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
MANDATORY_SRCS		= MainLogic/pushswap_utils.c \
					  Parsing/input_validation.c Parsing/parsing.c \
			  		  SortStacks/sort_large_stack_1.c SortStacks/sort_large_stack_2.c SortStacks/sort_small_stack.c \
			  		  StackUtils/push.c StackUtils/rotate.c StackUtils/rrotate.c StackUtils/stack_utils.c StackUtils/swap.c \
			  		  Utilities/ft_atol.c Utilities/ft_split.c
SRCS				= $(addprefix $(BONUS_DIR), $(BONUS_SRCS)) \
					  $(addprefix $(MANDATORY_DIR), $(MANDATORY_SRCS))

SRCS_OBJ	= $(SRCS:../%.c=$(OBJ_DIR)%.o)


all: $(NAME)

$(NAME): $(SRCS_OBJ)
	@$(CC) $(CFLAGS) $(SRCS_OBJ) -o $(NAME)
	@echo "checker is compiled successfully 🎉"

$(OBJ_DIR)%.o: ../%.c checker.h
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(SRCS_OBJ)
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean