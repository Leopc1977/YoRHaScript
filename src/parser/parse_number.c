#include "lexer.h"

#include <stdio.h>
#include <stdlib.h>

ASTNode* parse_number(Lexer* lexer) {
    Token token = lexer_next_token(lexer);

    if (token.type != TOKEN_INT) {
        printf("Erreur : attendu un nombre, trouvé %s\n", token.value);
        exit(1);
    }
    
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = AST_INT;
    node->value = atoi(token.value);
    node->left = node->right = NULL;
    
    return node;
}
