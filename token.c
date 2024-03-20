#include "token.h"
#include <string.h>

token_t* create_token(token_type_t type, const char* text) {
    token_t* token = (token_t*)malloc(sizeof(token_t));
    if (!token) return NULL;

    token->type = type;
    token->text = strdup(text); // Copy text to ensure the token owns its text
    return token;
}

void print_token(const token_t token) {
    const char* type_str = "";
    switch (token.type) {
        case NUMBER: type_str = "Number"; break;
        case OPERATOR: type_str = "Operator"; break;
        case SYMBOL: type_str = "Symbol"; break;
        case WORD: type_str = "Word"; break;
        default: type_str = "Unknown";
    }
    printf("Type: %s, Text: %s\n", type_str, token.text);
}

void free_token(token_t* token) {
    if (token->text) {
        free(token->text);
        token->text = NULL;
    }
}
void over(const IntStack* s) {
    if (s->top < 1) {
        printf("Error: insufficient items for 'over'\n");
        return;
    }
    int item = s->items[s->top - 1];
    push(s, item);
}

// Implement the DROP operation
void drop(IntStack* s) {
    if (!isEmpty(s)) {
        pop(s);
    }
}

// Implement the DUP (duplicate) operation
void dup(IntStack* s) {
    if (!isEmpty(s)) {
        int item = peek(s);
        push(s, item);
    }
}

// Add two top items
void add(IntStack* s) {
    if (s->top < 1) {
        printf("Error: insufficient items for 'add'\n");
        return;
    }
    int a = pop(s);
    int b = pop(s);
    push(s, a + b);
}