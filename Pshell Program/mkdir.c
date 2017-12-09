//
//  mkdir.c
//  Pshell
//
//  Created by Pascal on 12/7/17.
//  Copyright © 2017 Operating Systems. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "commands.h"

extern int mkdirShell(char**args){
    return mkdir(args[1],S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
}
