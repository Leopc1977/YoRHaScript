#include <stdio.h>
#include <stdlib.h>

#include "types.h"

#include "lexer.h"
#include "parser.h"

int yohra(const char *filename) {
    Lexer *lexer = NULL;

    if ((lexer = init_lexer(filename)) == NULL) {
        return 1;
    }

    ASTNode* ast = parse_function(lexer);
    print_ast(ast, 0);

    free_lexer(lexer);

    return 0;
}
