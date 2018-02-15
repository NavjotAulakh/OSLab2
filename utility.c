/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, <GROUP MEMBERS>
 * All rights reserved.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "utility.h"

// Define your utility functions here, these will most likely be functions that you call
// in your myshell.c source file

extern void changeDirectory(char arguments[5][256], int num_tokens ){
    char* path = arguments[1];
    if (num_tokens == 1){
        printf("%s\n",getenv("PWD"));
    }
    if (num_tokens > 2){
        printf("Invalid input. See help file.\n");
    }
    else {
        printf("Changing Current directory:%s to %s\n",getenv("PWD"),path);
        int r = chdir(path);
        if (r!= 0){
            printf("failed.");
        }
    }
    
        
}
//extern void clearScreen();
//extern void seeDirectory();
//extern void checkEnvironVar();
//extern void pause();
//extern void printHelp();