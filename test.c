#include "pipex.h"

#include <stdio.h>

int main(int ac, char **av, char **env) {
    (void)ac; // Suppress unused variable warning
    (void)av;

    for (int i = 0; env[i] != NULL; i++) {
        printf("%s\n", env[i]);
    }
    return 0;
}

