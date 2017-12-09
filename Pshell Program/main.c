#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "commands.h"

//Current directory
char*workingDirectory;


/*
 All commands taken from commands.h
 */
extern int head(char**args);
extern int tail(char**args);
extern int pwd();
extern int ls(char**args);
extern int cd(char**args);
extern int mkdirectory(char**args);
extern int rm(char**args);
extern int mkdirShell(char**args);


//Runs the command
int run_command(char **args)
{
    
    pid_t pid, wpid;
    int status;
    
    if (args[0] == NULL) {
        return 0;
    }
    
    //Parent commands
    char*command = args[0];
    if(strcmp(command, "cd")==0)
        return cd(args);

    
    

    
    pid = fork();
    //Child
    if (pid == 0) {
        if (tryCommands(args) == -1) {
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
        //Error
    } else if (pid < 0) {
        perror("shell error");
        //parent
    } else {
        //Wait for child to complete
        while ((wpid = wait(&status)) > 0);
    }


    return 1;
}



//tries any of the commands below in the child process.
// head
// pwd
// cat
int tryCommands(char** args){
    if(args[0]==NULL)
        return 0;
    
    char * command = args[0];

    if(strcmp(command, "head")==0)
            return head(args);
    else if(strcmp(command, "tail")==0)
        return tail(args);
    else if(strcmp(command, "pwd")==0)
            return pwd();
    else if(strcmp(command, "cat")==0)
        return cat(args);
    else if(strcmp(command,"mkdir")==0)
        return mkdirShell(args);
    else if(strcmp(command,"rm")==0)
        return rm(args);
    else if (strcmp(command, "ls")==0)
        return ls(args);
    else{
        printf("Not a valid command.\n");
        return 0;
    }
    
    return 1;
}


//Converts userinput to char array for arguements
char **convertToCharArray(char *line){
    char **charArray = malloc(128 * sizeof(char*));
    
    char*temp = strtok (line," \n");
    
    int pos=0;
    
    while (temp != NULL)
    {
        charArray[pos]=temp;
        pos++;
        temp = strtok (NULL, " \n");
    }
    
    charArray[pos]=NULL;
    
    return charArray;
}

//Gets the header for each line(i.e. "Desktop pascal$")
char* changeHeader(){
    char cwd[1024];
    
    getcwd(cwd, sizeof(cwd));
    char*pch = strtok (cwd,"/");
    char*temp=pch;
    
    while (pch != NULL)
    {
        pch = strtok (NULL, "/");
        if (pch!=NULL) {
            temp=pch;
        }
    }
    workingDirectory=temp;
    return temp;
    
}

void shellprogram(void){

}


//Main method
int main(int argc, char **argv)
{
    char *userinput;
    char **args;
    
    while(1) {
        workingDirectory=changeHeader();
        
        printf("%s pascal$ ",workingDirectory);
        
        //Get user input
        userinput = NULL;
        size_t linesize = 0; // have getline allocate a buffer for us
        getline(&userinput, &linesize, stdin);
        
        
        //Split
        args = convertToCharArray(userinput);
        
        //If no command is entered, do nothing
        if(args[0]==NULL)
            continue;
        
        //Tests if exit command
        if(strcmp(args[0],"exit")==0){
            break;
        }
        //Run command
        run_command(args);
        
        //Clears command
        free(userinput);
        free(args);
    }
    
    return 0;
}
