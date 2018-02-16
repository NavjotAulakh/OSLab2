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
char arguments[10][256];
// Define functions declared in myshell.h here

int main(int argc, char *argv[])
{
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = {0};
    char command[BUFFER_LEN] = {0};
    char arg[BUFFER_LEN] = {0};
    int errorCode;

    // Parse the commands provided using argc and argv
    int i;
    system("echo $SHELL"); // Outputs "Myshell PWD/myshell"
    char *Myshell = getenv("PWD");
    setenv("PWD", Myshell, 1);
    strcat(Myshell, "/myshell");
    setenv("SHELL", Myshell, 1);      // Overwrite it
    system("echo $SHELL");            // Outputs "Myshell PWD/myshell"
    printf("echo %s", getenv("PWD")); // Outputs "Myshell PWD/myshell"
    for (i = 0; i < argc; ++i)
    {
        printf("\nMy Shell command line. \n");
        strcpy(command, argv[i]);
    }

    // Perform an infinite loop getting command input from users
    while (printf("%s: ", getenv("PWD")), fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Perform string tokenization to get the command and argument
        strcpy(arg, buffer);
        int num_tokens = 0;
        char *token = NULL;

<<<<<<< HEAD
    else if (strcmp(command, "dir") == 0) {
        if (num_tokens != 2){
            printf("%s\n", getenv("PWD") );
        }
        else {
            struct dirent *pDirStrut;
            DIR *pDirect;
            pDirect = opendir(arguments[1]);
            if (pDirect == NULL) {
                printf ("Cannot open directory '%s'. Sorry.\n", arguments[1]);
            } else {
                while ((pDirStrut = readdir(pDirect)) != NULL) {
                    printf ("[%s]\n", pDirStrut->d_name);
                }
=======
        for (token = strtok(buffer, " \n\0\r"); NULL != token; token = strtok(NULL, " \n\0\r"))
        {
            if (num_tokens == 0)
            {
                strcpy(command, token);
                printf("Command:%s\n", command);
            }
            else
            {
                strcpy(arguments[num_tokens], token);
                printf("Argument:%s\n", arguments[num_tokens]);
>>>>>>> 05e408ce6b4b733ec22628a767a1c46ddc63fd64
            }
            ++num_tokens;
        }
        
        // Send the commands to be executed. Perform sanity check.
        errorCode = commandHandler(command, arguments, num_tokens);
        if (errorCode == 1){
            break;
        }
        if (errorCode == -1){
            printf("Fatel Error: This error should be impossible. Redo commandHandler.");
            exit(11);
        }
    }
    return EXIT_SUCCESS;
}
