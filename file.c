#include<stdio.h>
#include "file.h"
FILE *open_file(const char *filename){
    FILE *fp;
    fp = fopen(filename,"r");//Opens file and enabled only for reading.
    if(fp==NULL){
        printf("Error:File opening failed for %s\n",filename);

    }
    return fp;
}
int read_character(FILE *fp){
    return fgetc(fp); //Reads character by character from file.

}
void close_file(FILE *fp){
    if(fp != NULL){
        fclose(fp);
    }
}