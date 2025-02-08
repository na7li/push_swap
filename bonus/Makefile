CC                  = cc
CFLAGS              = -Wall -Werror -Wextra
RM                  = rm -rf

SRC_DIR             = srcs/
OBJ_DIR             = obj/

NAME                = ../checker

SRCS		= checker.c checker_utils.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
				../srcs/Parcing/parcing.c ../srcs/Utilities/ft_split.c ../srcs/Utilities/number_of_digits.c \
				../srcs/Utilities/atol.c ../srcs/Parcing/input_validation.c ../srcs/StackUtils/stack_utils.c \
				
SRCS_OBJ	= $(SRCS:%.c=%.o)


all: $(NAME)

$(NAME): $(SRCS_OBJ)
	@$(CC) $(SRCS_OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(SRCS_OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re de