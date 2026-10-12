#ifndef FILE_H
#define FILE_H
#include<stdio.h>

FILE *open_file(const char *filename); //Declared function pointer for opening file.
int read_character(FILE *fp); //Declared function pointer for reading file.
void close_file(FILE *fp);//Declared function pointer for closing file.

#endif
