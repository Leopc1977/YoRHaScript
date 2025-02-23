#include "lexer.h"
#include "parser.h"

#include <stdlib.h>

ASTNode* parse_expression(Lexer* lexer) {
    ASTNode* left = parse_number(lexer);

    Token token = lexer_next_token(lexer);
    if (token.type == TOKEN_OPERATOR) {
        ASTNode* node = malloc(sizeof(ASTNode));
        node->type = AST_BINARY_OP;
        node->op = token.value[0]; // e.g. '+'
        node->left = left;
        node->right = parse_number(lexer);
        
        return node;
    }

    return left;
}
