#Variables
NAME = libftprintf.a
SRC = printf.c
AR = ar rcs
OBJ = $(SRC:%.c=%.o)
N = norminette
CFLAG = -Werror -Wall -Wextra

#regles
all : $(NAME) 

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o : %.c printf.h
	gcc $(CFLAG) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

n :
	$(N)
