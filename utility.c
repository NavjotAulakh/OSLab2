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

extern void changeDirectory(char arguments[10][256], int num_tokens)
{
    char *path = arguments[1];
    if (num_tokens == 1)
    {
        printf("%s\n", getenv("PWD"));
    }
    if (num_tokens > 2)
    {
        printf("Invalid input. See help file.\n");
    }
    else
    {
        printf("Changing Current directory:%s to %s\n", getenv("PWD"), path);
        int r = chdir(path);
        if (r != 0)
        {
            printf("Failed to change directory.");
        }
    }
}

extern void exec(char arguments[10][256], int num_tokens)
{
    if (num_tokens != 2)
    {
        printf("Usage: myshell [batchfile] ");
    }
    else
    {
        FILE *fp;
        char line[256], command[256];
        char args[5][256];
        char *token;
        fp = fopen(arguments[1], "r");
        while (fgets(line, 256, fp) != 0)
        {
            num_tokens = 0;
            for (token = strtok(line, " \n\0\r"); NULL != token; token = strtok(NULL, " \n\0\r"))
            {
                if (num_tokens == 0)
                {
                    strcpy(command, token);
                    printf("Command:%s\n", command);
                }
                else
                {
                    strcpy(args[num_tokens], token);
                    printf("Argument:%s\n", args[num_tokens]);
                }
                ++num_tokens;
            }
            commandHandler(command, args, num_tokens);
        }
        fclose(fp);
        free(token);
    }
}

extern int commandHandler(char command[256], char arguments[10][256], int num_tokens)
{
    // Change the working directory.
    if (strcmp(command, "cd") == 0)
    {
        changeDirectory(arguments, num_tokens);
        return 0;
    }

    // Clear the screen of garbage. Portable to windows. Monstrous.
    else if (strcmp(command, "clr") == 0)
    {
        system("clear||clr");
        return 0;
    }

    // Executes a script, written for this shell. Lax rules.
    else if (strcmp(command, "exec") == 0)
    {
        exec(arguments, num_tokens);
        return 0;
    }

    // Show the contents of the directory.
    else if (strcmp(command, "dir") == 0)
    {
        seeDirectory(arguments, num_tokens);
        return 0;
    }

    // Prints the environment variables.
    else if (strcmp(command, "environ") == 0)
    {
        checkEnvironVar();
        return 0;
    }

    // Prints the arguments to stdout.
    else if (strcmp(command, "echo") == 0)
    {
        shellPrint(arguments, num_tokens);
        return 0;
    }

    //prints the README.md manual
    else if (strcmp(command, "help") == 0)
    {
        printHelp();
        return 0;
    }

    // Pauses the terminal from executing.
    else if (strcmp(command, "pause") == 0)
    {
        pauseShell();
        return 0;
    }

    // quit command -- exit the shell
    else if (strcmp(command, "quit") == 0)
    {
        return 1;
    }

    // Unsupported command
    else
    {
        fputs("Unsupported command, use help to display the manual.\n", stderr);
        return 0;
    }

    // Logic Error. Common reason: Didn't add return value to new shell command.
    return -1;
}

extern void seeDirectory(char arguments[10][256], int num_tokens)
{
    if (num_tokens != 2)
    {
        printf("%s\n", getenv("PWD"));
    }
    else
    {
        struct dirent *pDirStrut;
        DIR *pDirect;
        pDirect = opendir(arguments[1]);
        if (pDirect == NULL)
        {
            printf("Cannot open directory '%s'. Sorry.\n", arguments[1]);
        }
        while ((pDirStrut = readdir(pDirect)) != NULL)
        {
            printf("[%s]\n", pDirStrut->d_name);
        }
        closedir(pDirect);
    }
}
extern void checkEnvironVar()
{
    extern char **environ;
    int i = 0;
    while (environ[i])
    {
        printf("%s\n", environ[i++]); // prints in form of "variable=value"
    }
}

extern void shellPrint(char arguments[10][256], int num_tokens)
{
    int i = 1;
    while (i < num_tokens)
    {
        printf("%s ", arguments[i]);
        ++i;
    }
    printf("\n");
}
extern void pauseShell()
{
    printf("Press enter to continue...");
    char c = 'm';
    while (c != '\r' && c != '\n')
    {
        c = getchar();
    }
    printf("Unpaused.\n");
}
extern void printHelp()
{
    int c;
    FILE *file;
    file = fopen("README.md", "r");
    if (file)
    {
        while ((c = getc(file)) != EOF)
            putchar(c);
        fclose(file);
    }
}
