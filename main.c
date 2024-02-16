// main.c
#include "token.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>


token_type_t classify_token(const char* text);

int main() {
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Enter FORTH code (CTRL+D to stop):\n");
    while ((read = getline(&line, &len, stdin)) != -1) {

        char* token_text = strtok(line, " \n");
        while (token_text != NULL) {

            token_type_t type = classify_token(token_text);
            token_t* token = create_token(type, token_text);
            printf("Token: %s, Type: %d\n", token->text, token->type);


            free_token(token);
            token_text = strtok(NULL, " \n");
        }
    }
    free(line);

    return 0;
}

token_type_t classify_token(const char* text) {
    if (isdigit(text[0])) {
        return NUMBER;
    } else if (strchr("+-*/", text[0]) != NULL) {
        return OPERATOR;
    } else if (strchr(":;", text[0]) != NULL) {
        return SYMBOL;
    } else {
        return WORD;
    }
}
