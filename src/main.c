#include <stdio.h>

#include "yohra.h"

int main (int argc, char *argv[]) {
    if (argc == 1) {
        // Print usage
        printf("Use : ./yohra <fichier>\n");
        return 0;
    } else if (argc == 2) {
        // Execute the script
        return yohra(argv[1]);
    }
}
