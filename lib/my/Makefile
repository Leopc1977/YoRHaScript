SRC			=	$(wildcard *.c)

OBJ			=	$(SRC:.c=.o)

ARFLAGS 	=	rc

NAME		=	libmy.a

CFLAGS		=	-Wall -Wextra -Werror  # Ajout des flags de compilation
CPPFLAGS	=	-I./include/

NAME_MY_H	=	my.h

all:		$(NAME)

$(NAME):	$(OBJ)
			@mkdir -p ../
			@mkdir -p ../../include/
			$(AR) $(ARFLAGS) $(NAME) $(OBJ)
			cp $(NAME) ./../$(NAME)
			cp ./include/$(NAME_MY_H) ./../../include/$(NAME_MY_H)

clean:
			$(RM) $(OBJ)

fclean: 	clean
			$(RM) ../../include/$(NAME_MY_H)
			$(RM) ../$(NAME)
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
