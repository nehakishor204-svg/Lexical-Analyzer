/*Author : NEHA KISHOR
"LEXICAL ANALYZER"
This part specifically doing spliting lexemes ,tokenaization
includes token.c,main.c,file.c*/
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include "lexer.h"
#include "token.h"
#include "file.h"

void process_file(FILE *fp){
    int ch;
    int linenumber = 1;
    char lexeme[1000];
    int i;
    ch = fgetc(fp);
    while(ch != EOF){
        if(ch == '\n'){
            linenumber++; // Increment linenumber.
            ch = fgetc(fp);
        }
        else if(ch == '#'){ //Checking if it is a preprocessor directives
            int i;
            i = 0;
            while(ch != '\n' && ch != EOF){
                if(i<999){
                    lexeme[i] = ch;
                    i++;
                }
                ch = fgetc(fp);
            }
            lexeme[i] = '\0';
            Token token;
            token.type = PREPROCESSOR;
            strcpy(token.lexeme,lexeme);
            token.linenumber = linenumber;
            print_token(token);
            if(ch == '\n'){
                linenumber++;
                ch = fgetc(fp);
            }
        }
        //Checking or identifying lexeme if valid token or not.
        else if(ch == ' ' || ch == '\t'){
            ch = fgetc(fp);
        }
        else if(isalpha(ch) || ch == '_'){
            i = 0;
            while(isalnum(ch) || ch == '_'){
                if(i<99){
                    lexeme[i] = ch;
                    i++;
                }
                
                ch = fgetc(fp);
            }
            lexeme[i] = '\0';
            Token token;
            token.type = identify_token(lexeme);
            strcpy(token.lexeme,lexeme);
            token.linenumber = linenumber;
            print_token(token);
        }
        //Checking digits and classifies them,if it is valid or not too.
        else if(isdigit(ch)){
            int invalid;
            i=0;
            invalid = 0;
            if(ch == '0'){
                lexeme[i] = ch;
                i++;
                ch = fgetc(fp);
                if(ch == 'x' || ch == 'X'){ // check if it is hexadecimal.
                    lexeme[i] = ch;
                    i++;
                    ch = fgetc(fp);
                    if(!isxdigit(ch)){
                        invalid = 1; //if it is not it is invalid.
                    }
                    while(isxdigit(ch)){
                        if(i<99){
                            lexeme[i] = ch;
                            i++;
                        }
                        ch = fgetc(fp);
                    }
                    if(isalpha(ch) || ch == '_'){ // checks number containing alphabets
                        invalid = 1;
                        while(isalnum(ch) || ch == '_'){//checks number containing alphabets or numbers.
                            if(i<99){
                                lexeme[i] = ch;
                                i++;
                            }
                            ch = fgetc(fp);
                        }
                    }
                    lexeme[i] = '\0';
                    if(invalid){
                        printf("%-6d %-18s Invalid number '%s'\n",linenumber,"LEXICAL ERROR",lexeme);//printing the error message
                    }
                    else{
                        Token token;
                        token.type = CONSTANT;
                        strcpy(token.lexeme,lexeme);
                        token.linenumber = linenumber;
                        print_token(token);
                    }
                }
                else{
                    while(isdigit(ch)){
                        if(i<99){
                            lexeme[i] = ch;
                            i++;
                        }
                        ch = fgetc(fp);
                    }
                    if(ch == '.'){ // checks for floating decimals
                        lexeme[i] = ch;
                        i++;
                        ch = fgetc(fp);
                        if(!isdigit(ch)){
                           invalid = 1;
                        }
                        while(isdigit(ch)){
                            if(i<99){
                            lexeme[i] = ch;
                            i++;
                            }
                           ch = fgetc(fp);
                        }
                        if(ch == '.'){ // if point exceed certain number of limit it is considered as inalid number
                           invalid = 1;
                           lexeme[i] = ch;
                           i++;
                           ch = fgetc(fp);
                           while(isdigit(ch)){
                                if(i<99){
                                   lexeme[i] = ch;
                                   i++;
                                }
                                ch = fgetc(fp);
                            }
                        }
                    }
                    //Check if number containing any scientific notations.
                    if(ch == 'e' || ch == 'E'){
                        lexeme[i] = ch;
                        i++;
                        ch = fgetc(fp);
                        if(ch == '+' || ch == '-'){ //  +- are valid in between such numbers.
                            lexeme[i] = ch;
                            i++;
                            ch = fgetc(fp);
                        }
                        if(!isdigit(ch)){
                            invalid = 1;
                        }
                        while(isdigit(ch)){
                            if(i<99){
                                lexeme[i] = ch;
                                i++;
                            }
                            ch = fgetc(fp);
                        }
                    }
                
            
            
                    if(isalpha(ch) || ch == '_'){
                        invalid = 1;
                        while(isalnum(ch) || ch == '_'){
                            if(i<99){
                               lexeme[i] = ch;
                               i++;
                            }
                            ch = fgetc(fp);
                        }
                    }
                    lexeme[i] = '\0';
                    if(invalid){
                        printf("%-6d %-18s Invalid number '%s'\n",linenumber,"LEXICAL ERROR",lexeme);
                    }
            
                    else{
                
                        Token token;
                        token.type = CONSTANT;
                        strcpy(token.lexeme,lexeme);
                        token.linenumber = linenumber;
                        print_token(token);

                    }
                }
            }
            else{
                while(isdigit(ch)){ // checking for normal decimals and if that contains scientific notations.
                    if(i<99){
                        lexeme[i] = ch;
                        i++;
                    }
                    ch = fgetc(fp);
                }
                if(ch == '.'){
                    lexeme[i] = ch;
                    i++;
                    ch = fgetc(fp);
                    if(!isdigit(ch)){
                        invalid = 1;
                    }
                    while(isdigit(ch)){
                        if(i<99){
                            lexeme[i] = ch;
                            i++;
                        }
                        ch = fgetc(fp);
                    }
                    if(ch == '.'){
                        invalid = 1;
                        lexeme[i] = ch;
                        i++;
                        ch = fgetc(fp);
                        while(isdigit(ch)){
                            if(i<99){
                                lexeme[i] = ch;
                                i++;
                            }
                            ch = fgetc(fp);
                        }
                    }
                }
                if(ch == 'e' || ch == 'E'){
                    lexeme[i] = ch;
                    i++;
                    ch = fgetc(fp);
                    if(ch == '+' || ch == '-'){
                        lexeme[i] = ch;
                        i++;
                        ch = fgetc(fp);
                    }
                    if(!isdigit(ch)){
                        invalid = 1;
                    }
                    while(isdigit(ch)){
                        if(i<99){
                            lexeme[i] = ch;
                            i++;
                        }
                        ch = fgetc(fp);
                    }
                }
                
            
            
                if(isalpha(ch) || ch == '_'){
                    invalid = 1;
                    while(isalnum(ch) || ch == '_'){
                        if(i<99){
                            lexeme[i] = ch;
                            i++;
                        }
                        ch = fgetc(fp);
                    }
                }
                lexeme[i] = '\0';
                if(invalid){
                    printf("%-6d %-18s Invalid number '%s'\n",linenumber,"LEXICAL ERROR",lexeme);
                }
            
                else{
                
                    Token token;
                    token.type = CONSTANT;
                    strcpy(token.lexeme,lexeme);
                    token.linenumber = linenumber;
                    print_token(token);

                }
            }
        }

        
    
    
        else if(ch == '.'){
            i=0;
            lexeme[i] = ch;
            i++;
            ch = fgetc(fp);
            if(isdigit(ch)){
                while(isdigit(ch)){
                    if(i<99){
                        lexeme[i] = ch;
                        i++;
                    }
                    ch = fgetc(fp);
                }
                lexeme[i] = '\0';
                Token token;
                token.type = CONSTANT;
                strcpy(token.lexeme,lexeme);
                token.linenumber = linenumber;
                print_token(token);
            }
            else{
                lexeme[i] = '\0';
                printf("%-6d %-18s Invalid number '%s'\n",linenumber,"LEXICAL ERROR",lexeme);
            }
        }
        //Checks if program contains operators,single and double operators.
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '<' || ch == '>' || ch == '!' || ch == '&' || ch == '|'){
            int next;
            Token token;
            next = fgetc(fp);
            if(ch == '/' && next == '/'){
                while(next != '\n' && next != EOF){
                    next = fgetc(fp);
                }
                if(next == '\n'){
                    linenumber++;
                    ch = fgetc(fp);
                }
                else{
                    ch = next;
                }
                continue;
            }
            if(ch == '/' && next == '*'){
                ch = fgetc(fp);
                next = fgetc(fp);
                while(ch != EOF){
                    if(ch == '\n'){
                        linenumber++;
                    }
                    if(ch == '*' && next == '/'){
                        ch = fgetc(fp);
                        break;
                    }
                    ch = next;
                    next = fgetc(fp);
                }
                continue;
            }
            //Check for double operators.
            if((ch == '=' && next == '=') ||
              (ch == '!' && next == '=') ||
              (ch == '<' && next == '=') ||
              (ch == '>' && next == '=') ||
              (ch == '+' && next == '+') ||
              (ch == '-' && next == '-') ||
              (ch == '&' && next == '&') ||
              (ch == '|' && next == '|') ||
              (ch == '+' && next == '=') ||
              (ch == '-' && next == '=') ||
              (ch == '*' && next == '=') ||
              (ch == '/' && next == '=')){
            token.type = OPERATOR;
            token.lexeme[0] = ch;
            token.lexeme[1] = next;
            token.lexeme[2] = '\0';
            token.linenumber = linenumber;
            print_token(token);
            ch = fgetc(fp);
        }
        else{
            token.type = OPERATOR;
            token.lexeme[0] = ch;
            token.lexeme[1] = '\0';
            token.linenumber = linenumber;
            print_token(token);
            ch = next;
        }
    }
    //Check for special character
        else if(ch == ';' || ch == ',' || ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']'){
            Token token;
            token.type = SPECIAL_CHAR;
            token.lexeme[0] = ch;
            token.lexeme[1] = '\0';
            token.linenumber = linenumber;
            print_token(token);
            ch = fgetc(fp);
        }
        //check if it contains string.
        else if(ch == '"'){
            int i;
            i=0;
            lexeme[i] = ch;
            i++;
            ch = fgetc(fp);
            while(ch != '"' && ch != '\n' && ch != EOF){
                if(i<99){
                    lexeme[i] = ch;
                    i++;
                }
                ch = fgetc(fp);
            }
            if(ch == '"'){
                lexeme[i] = ch;
                i++;
                lexeme[i] = '\0';
                Token token;
                token.type = STRING;
                strcpy(token.lexeme,lexeme);
                token.linenumber = linenumber;
                print_token(token);
                ch = fgetc(fp);
            }
            else{
                printf("%-6d %-18s Unterminated string\n",linenumber,"LEXICAL ERROR");//if any '"' missing it tends to unterminated string
                if(ch == '\n'){
                    linenumber++;
                }
                ch = fgetc(fp);
            }
        }
        else if(ch == '\''){
            int i;
            int count;
            int valid;
            i = 0;
            count = 0;
            valid = 1;
            lexeme[i] = ch;
            i++;
            ch = fgetc(fp);
            
            if(ch == '\\'){
                lexeme[i] = ch;
                i++;
                count++;
                ch = fgetc(fp);
                //Checks for escape sequences
                if(ch == 'n' || ch == 't' || ch == 'r' ||
                   ch == 'b' || ch == 'f' || ch == 'v' ||
                   ch == 'a' || ch == '0' ||
                   ch == '\\' || ch == '\'' || ch == '"'){
                    
                    lexeme[i] = ch;
                    i++;
                    
                    count++;
                    ch = fgetc(fp);
                }
                else{
                    valid = 0;
                    if(ch != '\n' && ch != EOF){
                        lexeme[i] = ch;
                        i++;
                        ch = fgetc(fp);
                    }
                }
            }
            //Checks if it contain character constants.
            else if(ch != '\'' && ch != '\n' && ch != EOF){
                lexeme[i] = ch;
                i++;
                count++;
                ch = fgetc(fp);
                while(ch != '\'' && ch != '\n' && ch != EOF){
                    valid = 0;
                    if(i<99){
                        lexeme[i] = ch;
                        i++;
                    }
                    ch = fgetc(fp);
                }

           
            }
            else{
                valid = 0;
            }
            if(ch == '\''){
                lexeme[i] = ch;
                i++;
                lexeme[i] = '\0';
                if(valid && (count == 1 || (count ==2 && lexeme[1] == '\\'))){
                    Token token;
                    token.type = CHARACTER;
                    strcpy(token.lexeme,lexeme);
                    token.linenumber = linenumber;
                    print_token(token);
                }
                else{
                    printf("%-6d %-18s Invalid character %s\n",linenumber,"LEXICAL ERROR",lexeme);//if it misses ' it termed as invalid.
                }
                ch = fgetc(fp);
            }
            else{
                lexeme[i] = '\0';
                printf("%-6d %-18s Unterminated character\n",linenumber,"LEXICAL ERROR");
                if(ch == '\n'){
                    linenumber++;
                }
                ch = fgetc(fp);
            }

        }
        else{

            printf("%-6d %-18s Invalid character '%c'\t\n",linenumber,"LEXICAL ERROR",ch);
            ch = fgetc(fp);
        }
    }
}
//tokenaization , error checking ,and checking validity done in this part.
