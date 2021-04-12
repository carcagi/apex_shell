// I am using the standard library just because Guillaume and Alexandre can not see me.
// Don't tell them I use the comments to gosip about them, they will send betty after me
// apex, just the tip of a shell.

#define _GNU_SOURCE
#include <string.h> 
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "functions.h"

int main() {
    while (1) {
        printf("\n>>> ");
        char *line = apex_read_the_thing();
        char **tokens = apex_split_it(line);

        if (tokens[0] != NULL) {
            apex_call(tokens);
        }

        free(tokens);
        free(line);
    }
}
