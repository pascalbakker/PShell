//
//  commands.h
//  Pshell
//
//  Created by Pascal on 12/7/17.
//  Copyright © 2017 Operating Systems. All rights reserved.
//

#ifndef commands_h
#define commands_h
extern int head(char**args);
extern int tail(char**args);
extern int cat(char**args);
extern int pwd();
extern int ls(char**args);
extern int cd(char**args);
extern int rm(char**args);
extern int mkdirShell(char**args);
extern int rm(char**args);
#endif /* commands_h */
