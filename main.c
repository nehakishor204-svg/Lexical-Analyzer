//Excecuting whole functions
#include<stdio.h>
#include "file.h"
#include "lexer.h"
int main(){
    FILE *fp;
    
    fp = open_file("test.c");
    if(fp == NULL){
        return 1;
    }
     printf("\n%-6s %-18s %-20s\n",
           "LINE", "TOKEN TYPE", "LEXEME");

    printf("------------------------------------------------------\n");//For getting output in a tabular format.

    process_file(fp);
   
    close_file(fp);

}