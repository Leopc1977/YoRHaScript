#include <stdlib.h>

#include "types.h"

void free_lexer(Lexer *lexer) {
    free(lexer->source);
    free(lexer);
}
