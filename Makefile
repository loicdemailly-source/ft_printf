
CC = cc
INC = ft_printf.h
CC_FLAGS = -Werror -Wall -Wextra
SRC = ft_bzero.c\
		ft_calloc.c\
		ft_itoa.c\
		ft_printf.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putstr_nil_fd.c\
		ft_uitoa.c\
		ft_strlen.c

OBJ = $(SRC:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME) : ${OBJ} Makefile $(INC)
	ar -rcs $(NAME) $(OBJ) $(INC)

%.o: %.c 
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	$(RM) -rf $(OBJ)

fclean: clean
	$(RM) -rf $(NAME) a.out

re: fclean all

.PHONY: all clean fclean re