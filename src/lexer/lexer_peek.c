#include "types.h"

char lexer_peek(Lexer* lexer) {
    return lexer->source[lexer->position];
}
