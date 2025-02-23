#include <stdio.h>

#include "lexer.h"

void print_ast(ASTNode* node, int indent) {
    for (int i = 0; i < indent; i++) printf("  ");
    
    switch (node->type) {
        case AST_FUNCTION:
            printf("Function: %s\n", node->name);
            print_ast(node->left, indent + 1);
            break;
        case AST_BINARY_OP:
            printf("BinaryOp: %c\n", node->op);
            print_ast(node->left, indent + 1);
            print_ast(node->right, indent + 1);
            break;
        case AST_INT:
            printf("Number: %d\n", node->value);
            break;
        default:
            printf("Unknown node\n");
    }
}
