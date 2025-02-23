#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <ctype.h>

#include "types.h"
#include "my.h"

Lexer *init_lexer(char const *filepath) {
    if (filepath == NULL) {
        fprintf(stderr, "Erreur : fichier source manquant\n");
        return NULL;
    }

    Lexer *lexer = malloc(sizeof(Lexer));

    if (lexer == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return NULL;
    }

    lexer->source = get_file_content(filepath);

    if (lexer->source == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        return NULL;
    }

    lexer->position = 0;
    lexer->line = 1;
    lexer->column = 1;

    return lexer;
}
