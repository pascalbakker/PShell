#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include "commands.h"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>

//https://latesthackingnews.com/2017/03/22/c-program-implement-ls-command/
int ls(char **argv)
{
    struct dirent **namelist;
    int n=scandir(".",&namelist,NULL,alphasort);

    for (int i=1; i<=n; i++) {

        printf("%s\n",namelist[i]->d_name);
        free(namelist[n]);
    }

    free(namelist);


    return 1;
}
