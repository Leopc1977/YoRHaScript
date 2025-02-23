#include <string.h>
#include <ctype.h>

#include "types.h"
#include "lexer.h"

Token lexer_identifier(Lexer* lexer) {
    int start = lexer->position;

    while (isalnum(lexer_peek(lexer)) || lexer_peek(lexer) == '_') {
        lexer_advance(lexer);
    }

    int length = lexer->position - start;
    char* value = strndup(&lexer->source[start], length);

    // Check if it's a keyword
    if (strcmp(value, "def") == 0 
        || strcmp(value, "if") == 0 
        || strcmp(value, "else") == 0 
        || strcmp(value, "return") == 0
    ) {
        return (Token){TOKEN_KEYWORD, value, lexer->line, lexer->column, lexer->position};
    }

    return (Token){TOKEN_ID, value, lexer->line, lexer->column, lexer->position};
}
