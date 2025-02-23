#include "types.h"

#include "lexer.h"

void lexer_skip_whitespace(Lexer* lexer) {
    while (lexer_peek(lexer) == ' ' || lexer_peek(lexer) == '\t' || lexer_peek(lexer) == '\n') {
        lexer_advance(lexer);
    }
}
