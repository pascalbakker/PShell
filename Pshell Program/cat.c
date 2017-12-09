#include <stdio.h>
#include <stdlib.h>
#include "commands.h"

extern int cat(char**args){
	

	//Open file
	FILE *file;
	char* filename = args[1];
	file = fopen(filename,"r");
	if(file==NULL){
		printf("Cannot open file.\n");
		exit(0);
	}
	
	char c = fgetc(file);
	while(c!=EOF){
		printf("%c",c);
		c = fgetc(file);
	}

	fclose(file);
	return 0;

}
