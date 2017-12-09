#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"

extern int tail(char** args){
    size_t argc = strlen(*args);
    
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
    while(1){
        //If end of file, exit loop
        if(c ==EOF)
            break;
        c = fgetc(file);
        if(c=='\n')
            i++;
    }
    //Print i-10 lines
    rewind(file);
    if(i>10)
        i=i-max;
    
    int linenumber = 0;
    
    while(1){
        c = fgetc(file);

        if(c==EOF)
            break;
        if(c=='\n')
            linenumber++;
        if(linenumber>=i)
            printf("%c",c);
    }
    
    fclose(file);
    return 1;
}

