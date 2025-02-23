#include <string.h>
#include <ctype.h>

#include "types.h"
#include "lexer.h"

Token lexer_number(Lexer* lexer) {
    int start = lexer->position;
    int has_dot = 0;

    while (isdigit(lexer_peek(lexer)) || lexer_peek(lexer) == '.') {
        if (lexer_peek(lexer) == '.') {
            if (has_dot) break; // Only one dot is allowed
            has_dot = 1;
        }
        lexer_advance(lexer);
    }

    int length = lexer->position - start;
    char* value = strndup(&lexer->source[start], length);

    return (Token){has_dot ? TOKEN_FLOAT : TOKEN_INT, value, lexer->line, lexer->column, lexer->position};
}
