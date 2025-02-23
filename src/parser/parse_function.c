#include "lexer.h"
#include "parser.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

ASTNode* parse_function(Lexer* lexer) {
    Token token = lexer_next_token(lexer);
    if (token.type != TOKEN_KEYWORD || strcmp(token.value, "def") != 0) {
        printf("Erreur : attendu 'def', trouvé %s\n", token.value);
        exit(1);
    }

    // Read le nom de la fonction
    token = lexer_next_token(lexer);
    if (token.type != TOKEN_ID) {
        printf("Erreur : attendu un nom de fonction\n");
        exit(1);
    }
    printf("Nom de la fonction : %s\n", token.value);

    ASTNode* functionNode = malloc(sizeof(ASTNode));
    functionNode->type = AST_FUNCTION;
    functionNode->name = strdup(token.value);

    // Read '('
    token = lexer_next_token(lexer);
    if (token.type!= TOKEN_LPAREN) {
        printf("Erreur : attendu '('\n");
        exit(1);
    }

    // Read parameters
    // token = lexer_next_token(lexer);
    // if (token.type != TOKEN_ID) {
    //     printf("Erreur : attendu un paramètre\n");
    //     exit(1);
    // }

    // Read ')'
    token = lexer_next_token(lexer);
    if (token.type!= TOKEN_RPAREN) {
        printf("Erreur : attendu ')'\n");
        exit(1);
    }

    // Read '{'
    token = lexer_next_token(lexer);
    if (token.type != TOKEN_LBRACE) {
        printf("Erreur : attendu '{'\n");
        exit(1);
    }

    // Read return statement
    token = lexer_next_token(lexer);
    printf("token: %s\n",token.value);
    printf("token type: %d\n",token.type);
    if (token.type != TOKEN_KEYWORD || strcmp(token.value, "return") != 0) {
        printf("Erreur : attendu 'return'\n");
        exit(1);
    }

    functionNode->left = parse_expression(lexer);

    // Read ';' and '}'
    lexer_next_token(lexer);
    lexer_next_token(lexer);

    return functionNode;
}
