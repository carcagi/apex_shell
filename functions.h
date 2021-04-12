void apex_call(char **args) {

    pid_t the_kid_id = fork();

    if (the_kid_id == 0) {
        execvp(args[0], args);
        perror("Hey stop with the errors:");
        exit(1);
    } else if (the_kid_id > 0) {
        int status;
        do {
            waitpid(the_kid_id, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    } else {
        perror("I don't really know what else to say. another error:");
    }
}


char** apex_split_it(char *line) {
    int length = 0;
    int capacity = 16;

    char **tokens = malloc(capacity * sizeof(char*));
    if (!tokens) {
        perror("You are doing it all wrong, shame on you:");
        exit(1);
    }

    char *delimiters = " \t\r\n";
    char *token = strtok(line, delimiters);

    while (token != NULL) {
        tokens[length] = token;
        length++;

        if (length >= capacity) {
            capacity = (int) (capacity * 1.5);
            tokens = realloc(tokens, capacity * sizeof(char*));
            if (!tokens) {
                perror("Another error, really?");
                exit(1);
            }
        }

        token = strtok(NULL, delimiters);
    }

    tokens[length] = NULL;
    return tokens;
}

char* apex_read_the_thing() {
    char *theLine = NULL;
    size_t bufferLength = 0;
    errno = 0;
    ssize_t strlen = getline(&theLine, &bufferLength, stdin);
    if (strlen < 0) {
        if (errno) {
            perror("Hey, you did something wrong!");
        }
        exit(1);
    }
    return theLine;
}
