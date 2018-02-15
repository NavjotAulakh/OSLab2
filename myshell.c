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
#include <sys/stat.h>
#include <string.h>
#include "utility.h"
#include "myshell.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256

// Put global environment variables here
char arguments[5][256];
// Define functions declared in myshell.h here

int main(int argc, char *argv[])
{
// Input buffer and and commands
char buffer[BUFFER_LEN] = { 0 };
char command[BUFFER_LEN] = { 0 };
char arg[BUFFER_LEN] = { 0 };

// Parse the commands provided using argc and argv
int i;
char * Myshell = getenv("PWD"); strcat(Myshell,"/myshell");
    setenv("SHELL", Myshell , 1); // Overwrite it

    system("echo $SHELL"); // Outputs "Myshell PWD/myshell"
for(i = 0; i < argc; ++i ) {
printf("\nMy Shell command line. \n");
strcpy(command, argv[i]);
}

// Perform an infinite loop getting command input from users
while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
{
// Perform string tokenization to get the command and argument
strcpy(arg,buffer);
int num_tokens = 0;
char *token = NULL;

for( token = strtok(buffer, " \n\0\r");NULL != token; token = strtok(NULL, " \n\0\r"))
{
    if (num_tokens == 0) 
    {strcpy(command,token); printf ("Command:%s\n", command);} 
    else 
    {
        strcpy(arguments[num_tokens],token);
        printf ("Argument:%s\n", arguments[num_tokens]);
    }
    ++num_tokens;
}

    if (strcmp(command, "cd") == 0) {
        printf("Cd command.\n");
    }
    else if (strcmp(command, "clr") == 0) {
        system("clear");
    }
    else if (strcmp(command, "directory") == 0) {
        if (num_tokens == 1){
            printf("%s\n",getenv("PWD"));
        }
        else {
               // printf(getenv("PWD"));
        }
    }
    else if (strcmp(command, "dir") == 0) {
        if (!(arguments[1])){
            printf("Invalid argument. See Help page.\n");
        }
        else {
            struct dirent *pDirStrut;
            DIR *pDirect;
            pDirect = opendir(arguments[1]);
            if (pDirect == NULL) {
                printf ("Cannot open directory '%s'. Sorry.\n", arguments[1]);
            }
            while ((pDirStrut = readdir(pDirect)) != NULL) {
                printf ("[%s]\n", pDirStrut->d_name);
            }
            closedir (pDirect);
        }
    }
        
    else if (strcmp(command, "environ") == 0) {
        extern char **environ;

        int i = 0;
        while(environ[i]) {
        printf("%s\n", environ[i++]); // prints in form of "variable=value"
        }
    }
    else if (strcmp(command, "echo") == 0) {
        int i = 1;
        while (i < num_tokens) {
            printf("%s ", arguments[i]);
            ++i;
        }
        printf("\n");   
    }
    
    //prints the README.md manual
    else if (strcmp(command, "help") == 0) {
        int c;
        FILE *file;
        file = fopen("README.md", "r");
        if (file) {
            while ((c = getc(file)) != EOF)
                putchar(c);
            fclose(file);
        }
    }
    else if (strcmp(command, "pause") == 0) {
        printf("Press enter to continue...");
        char c = 'm';
        while (c != '\r' && c != '\n') { c = getchar(); }
        printf ("Unpaused.\n");

    }

    // quit command -- exit the shell
    else if (strcmp(command, "quit") == 0) {
        return EXIT_SUCCESS;
    }

    // Unsupported command
    else {
        fputs("Unsupported command, use help to display the manual.\n", stderr);
    }
}
return EXIT_SUCCESS;
}
