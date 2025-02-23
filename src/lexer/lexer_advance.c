#include "types.h"

char lexer_advance(Lexer* lexer) {
    char current = lexer->source[lexer->position];
    lexer->position++;
    lexer->column++;

    if (current == '\n') {
        lexer->line++;
        lexer->column = 1;
    }

    return current;
}
