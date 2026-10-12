#ifndef TOKEN_H
#define TOKEN_H

typedef enum{
    KEYWORD,
    IDENTIFIER,CONSTANT,
    OPERATOR,SPECIAL_CHAR,
    STRING,CHARACTER,PREPROCESSOR
}TokenType; //Defined tokentypes
typedef struct{
    TokenType type;
    char lexeme[1000];
    int linenumber;
}Token;
TokenType identify_token(char *lexeme);//Function for identifying token(tokenaization).
void print_token(Token token);//Function for Printing token

#endif
