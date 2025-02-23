#ifndef YOHRASCRIPT_H
#define YOHRASCRIPT_H

typedef enum {
    TOKEN_KEYWORD,
    TOKEN_ID,
    TOKEN_OPERATOR,
    TOKEN_SEMICOLON,
    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_COMMA,
    TOKEN_LBRACKET,
    TOKEN_RBRACKET,
    TOKEN_INT,
    TOKEN_FLOAT,
    TOKEN_EOF
} TokenType;

typedef enum {
    AST_FUNCTION,
    AST_RETURN,
    AST_BINARY_OP,
    AST_VARIABLE,
    AST_INT
} ASTNodeType;

typedef struct ASTNode {
    ASTNodeType type;

    char* name;
    int value;
    char op;

    struct ASTNode* left;
    struct ASTNode* right;
    
} ASTNode;

typedef struct {
    TokenType type;

    char* value;
    int line;
    int column;
    int position;
} Token;

typedef struct {
    char *source;
    int position;
    int line;
    int column;

    Token token;
} Lexer;

#endif
