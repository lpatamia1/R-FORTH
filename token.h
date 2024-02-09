#ifndef TOKEN_H
#define TOKEN_H

#include <string.h>

typedef enum {
    NUMBER,
    OPERATOR,
    SYMBOL,
    WORD
} token_type_t;

typedef struct {
    token_type_t type;
    char* text;
} token_t;


token_t create_token(token_type_t type, const char* text);
void print_token(const token_t token);


#endif
