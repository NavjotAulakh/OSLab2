/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, <GROUP MEMBERS>
 * All rights reserved.
 * 
 */
#ifndef UTILITY_H_
#define UTILITY_H_
#define _XOPEN_SOURCE 500
// Include your relevant functions declarations here they must start with the 
// extern keyword such as in the following example:
// extern void display_help(void);

#endif /* UTILITY_H_ */
extern int commandHandler(char command[256], char arguments[10][256], int num_tokens);
extern void changeDirectory(char arguments[10][256], int num_tokens);
extern void seeDirectory(char arguments[10][256], int num_tokens);
extern void exec(char arguments[10][256], int num_tokens);
extern void checkEnvironVar();
extern void pauseShell();
extern void shellPrint(char arguments[10][256], int num_tokens);
extern void printHelp();
extern int setenv(const char *envname, const char *envval, int overwrite);

