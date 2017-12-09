
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"

extern int head(char** args){
    size_t argc = strlen(*args);
    if(argc<2){
        printf("Not enough arguements\n");
        return 0;
    }
    
    //Initialize values
    int i=0; //used for printing loop
    int max; //Lines to print
    char*filename; //Filename
    
    //Determine number of lines to print
    if(argc==3&&args[2]==NULL){
        char*maxString = args[1];
        filename=args[2];
        max = atoi(maxString);
    }
    else{
        max = 10;
        filename=args[1];
    }
    
    //Open file
    FILE *file;
    file = fopen(filename,"r");
    if(file==NULL){
        printf("Cannot open file.\n");
        return 0;
    }
    
    
    //Print the file's contents
    char c = fgetc(file);
    while(i<max){
        //If end of file, exit loop
        if(c ==EOF)
            break;
        printf("%c",c);
        c = fgetc(file);
        if(c=='\n')
            i++;
    }
    printf("\n");
    fclose(file);
    return 1;
}

