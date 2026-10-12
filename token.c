//Printing token.
#include<stdio.h>
#include<string.h>
#include "token.h"
TokenType identify_token(char *lexeme){
    //Initialized keywords as array
    char *keywords[] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};

int count;
count = sizeof(keywords) / sizeof(keywords[0]);
for(int i = 0;i < count;i++){
    if(strcmp(lexeme,keywords[i])==0){
        return KEYWORD;
    }
}
return IDENTIFIER;
}
void print_token(Token token) // printing
{
    char *type;

    if(token.type == KEYWORD)
    {
        type = "KEYWORD";
    }
    else if(token.type == IDENTIFIER)
    {
        type = "IDENTIFIER";
    }
    else if(token.type == CONSTANT)
    {
        type = "CONSTANT";
    }
    else if(token.type == OPERATOR)
    {
        type = "OPERATOR";
    }
    else if(token.type == SPECIAL_CHAR)
    {
        type = "SPECIAL_CHAR";
    }
    else if(token.type == STRING)
    {
        type = "STRING";
    }
    else if(token.type == CHARACTER)
    {
        type = "CHARACTER";
    }
    else if(token.type == PREPROCESSOR)
    {
        type = "PREPROCESSOR";
    }
    else
    {
        type = "UNKNOWN";
    }

    printf("%-6d %-18s %-20s\n",
           token.linenumber,
           type,
           token.lexeme);
}
