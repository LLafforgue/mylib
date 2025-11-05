#Variables
NAME = libft.a
SRC = ft_*.c
OBJ = $(SRC:%.c=%.o)
AR = ar rcs
N = norminette
CFLAG = -Werror -Wall -Wextra 

#regles
all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ) 

%.o: %.c libft.h
	gcc $(CFLAG) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

n :
	$(N)

.PHONY: all clean fclean re n