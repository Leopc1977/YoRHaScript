#include "types.h"

Lexer *init_lexer(char const *filepath);
void free_lexer(Lexer *lexer);

char lexer_advance(Lexer* lexer);
Token lexer_identifier(Lexer* lexer);
Token lexer_next_token(Lexer* lexer);
Token lexer_number(Lexer* lexer);
char lexer_peek(Lexer* lexer);

void lexer_skip_whitespace(Lexer* lexer);
