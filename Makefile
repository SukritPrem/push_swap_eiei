NAME =push_swap

SRC= push_swap.c bubblesort.c ft_atoi_pushswap.c \
	Libft/ft_split.c Libft/ft_isdigit.c Libft/ft_lstnew.c \
	Libft/ft_substr.c Libft/ft_strdup.c Libft/ft_strlen.c \
	sort_3.c operation.c operation1.c utils.c utils1.c simple_sort.c \
	utils_simple_sort.c radix_sort.c check_error_char.c \
	init_arg.c free_list.c init_arg1.c utils_operation.c

OBJ = $(SRC:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror

all:$(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $@ 

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re : fclean all
