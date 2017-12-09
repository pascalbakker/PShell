//PWD: gets current working directory
//Current program state: working 

#include <unistd.h>
#include <stdio.h>
#include "commands.h"

int pwd() {
    char currentdirectory[1024];
    size_t buffsize = 1024;
    getcwd(currentdirectory, buffsize);
    printf("%s\n",currentdirectory);
    return 1;
}
