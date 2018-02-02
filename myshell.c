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
#include "myshell.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256

// Put global environment variables here

// Define functions declared in myshell.h here

int main(int argc, char *argv[])
{
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };
    char command[BUFFER_LEN] = { 0 };
    char arg[BUFFER_LEN] = { 0 };

    // Parse the commands provided using argc and argv
    int i;

    for( i = 0; i < argc; ++i ) {
	printf("Argument %d = \"%s\"\n", i, argv[i]);
	strcpy(command, argv[i]);
    }

    // Perform an infinite loop getting command input from users
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Perform string tokenization to get the command and argument
	strcpy(arg,buffer);
	fputs(arg,stdout);
	int num_tokens = 0;
	char *token = NULL;

	printf("Tokenize Line: \"%s\"", buffer);
	for( token = strtok(buffer, " ");NULL != token;token = strtok(NULL, " "))
	{
		printf("\t%d) \"%s\"\n", num_tokens, token);
		if (num_tokens == 0) {strcpy(command,token);} 
		else {
			strcpy(arg,token);
		}
		++num_tokens;
	}
	printf("Command token: %s\n", command);
	printf("Command token: %s\n", arg);
	
        // Check the command and execute the operations for each command
        // cd command -- change the current directory
        if (strcmp(command, "cd") == 0)
        {
            // your code here
        }

        // other commands here...
        
        // quit command -- exit the shell
        else if (strcmp(command, "quit") == 0)
        {
            return EXIT_SUCCESS;
        }

        // Unsupported command
        else
        {
            fputs("Unsupported command, use help to display the manual\n", stderr);
        }
    }
    return EXIT_SUCCESS;
}
