#include "types.h"

ASTNode* parse_expression(Lexer* lexer);
ASTNode* parse_function(Lexer* lexer);
ASTNode* parse_number(Lexer* lexer);

void print_ast(ASTNode* node, int indent);
