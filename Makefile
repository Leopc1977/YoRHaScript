SRC         =       src/main.c \
					src/yohra.c \
					src/lexer/init_lexer.c \
					src/lexer/free_lexer.c \
					src/lexer/lexer_skip_whitespace.c \
					src/lexer/lexer_peek.c \
					src/lexer/lexer_number.c \
					src/lexer/lexer_next_token.c \
					src/lexer/lexer_identifier.c \
					src/lexer/lexer_advance.c \
					src/parser/print_ast.c \
					src/parser/parse_number.c \
					src/parser/parse_function.c \
					src/parser/parse_expression.c

OBJ         =       $(SRC:.c=.o)

NAME        =       yohra

CFLAGS      =       -Wall -Wextra
CPPFLAGS    =       -I./include/
LDFLAGS     =       -L./lib/
LDLIBS      =       -lmy

all:        lib $(NAME)

lib:
			$(MAKE) -C ./lib/my

$(NAME):    $(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

clean:
			$(RM) $(OBJ)
			$(MAKE) -C lib/my clean

fclean:     clean
			$(RM) $(NAME)
			$(MAKE) -C lib/my fclean

re:         fclean all

.PHONY:     all clean fclean re lib
