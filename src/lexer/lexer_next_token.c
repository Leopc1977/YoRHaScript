#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "lexer.h"

Token lexer_next_token(Lexer* lexer) {
    lexer_skip_whitespace(lexer);

    char current = lexer_peek(lexer);

    if (isalpha(current) || current == '_') return lexer_identifier(lexer);
    if (isdigit(current)) return lexer_number(lexer);

    switch (current) {
        case '[': lexer_advance(lexer); return (Token){TOKEN_LBRACKET, "[", lexer->line, lexer->column, lexer->position};
        case ']': lexer_advance(lexer); return (Token){TOKEN_RBRACKET, "]", lexer->line, lexer->column, lexer->position};
        case ',': lexer_advance(lexer); return (Token){TOKEN_COMMA, ",", lexer->line, lexer->column, lexer->position};
        case '(': lexer_advance(lexer); return (Token){TOKEN_LPAREN, "(", lexer->line, lexer->column, lexer->position};
        case ')': lexer_advance(lexer); return (Token){TOKEN_RPAREN, ")", lexer->line, lexer->column, lexer->position};
        case '{': lexer_advance(lexer); return (Token){TOKEN_LBRACE, "{", lexer->line, lexer->column, lexer->position};
        case '}': lexer_advance(lexer); return (Token){TOKEN_RBRACE, "}", lexer->line, lexer->column, lexer->position};
        case ';': lexer_advance(lexer); return (Token){TOKEN_SEMICOLON, ";", lexer->line, lexer->column, lexer->position};
        case '+': case '-': case '*': case '/': case '=': case '<': case '>':
            lexer_advance(lexer);
            return (Token){TOKEN_OPERATOR, strndup(&current, 1), lexer->line, lexer->column, lexer->position};
        case '\0': return (Token){TOKEN_EOF, "EOF", lexer->line, lexer->column, lexer->position};
        default:
            printf("Erreur lexicale à la ligne %d, colonne %d\n", lexer->line, lexer->column);
            printf("Caractère: %c\n", current);
            exit(1);
    }
}
