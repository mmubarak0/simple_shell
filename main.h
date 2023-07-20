#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE

#define MAX_LENGTH 4096

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/* -> utilities functions */

char **_tokenize(char *str, char *split);
char **_tokenize2(char *str, char *split);

char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);
int _strlen(char *str);
char *getpath(void);
int check_cmd(char *command, char **path);
char *_memset(char *s, char b, unsigned int n);

void process(char **path);

/* General functions */
char *_getenv(char *s);

#endif
