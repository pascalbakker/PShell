//
//  rm.c
//  Pshell
//
//  Created by Pascal on 12/8/17.
//  Copyright © 2017 Operating Systems. All rights reserved.
//

//PWD: gets current working directory
//Current program state: working

#include <unistd.h>
#include <stdio.h>
#include "commands.h"

extern int rm(char**args){
    return remove(args[1]);
}
