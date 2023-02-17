CFLAGS = -Wall -Werror -Wextra
SRCS = push_swap.c radix.c operations.c mid_sort.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap
CC = gcc
LIB = ./sources/ft_printf/libftprintf.a ./sources/libft/libft.a
RM = rm -rf
all: $(NAME) 


$(NAME): $(LIB) $(OBJS)
	$(CC)  $(OBJS) $(LIB) -o $(NAME)

$(LIB):
	@make -C ./sources/ft_printf/
	@echo "printf compiled"
	@make -C ./sources/libft/
	@echo "libft compiled"

fclean : clean
	$(RM) ./*.a
	$(RM) ./sources/libft/*.a
	$(RM) ./sources/ft_printf/*.a

clean :
	$(RM) ./*.o
	$(RM) ./sources/libft/*.o
	$(RM) ./sources/ft_printf/*.o

re : fclean all

norm:
	@norminette

.PHONY : all clean fclean re
