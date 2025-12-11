
CC = cc
INC = ft_printf.h
CC_FLAGS = -Werror -Wall -Wextra -MMD -MP
SRC = ft_calloc.c\
		ft_itoa.c\
		ft_printf.c\
		ft_putstr_fd.c

OBJ = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)
NAME = libftprintf.a

all: $(NAME)

$(NAME) : ${OBJ} Makefile $(INC)
	ar -rcs $(NAME) $(OBJ) $(INC)

%.o: %.c $(INC)
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	$(RM) -rf $(OBJ)

fclean: clean
	$(RM) -rf $(NAME) $(DEP) a.out

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)
