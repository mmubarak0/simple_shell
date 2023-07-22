#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE

#define MAX_LENGTH 4096
#define BUFFER_SIZE 1024

#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/* -> utilities functions */

char **_tokenize(char *str, char *split);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);
int _strlen(char *str);
char *_memset(char *s, char b, unsigned int n);
char *_strchr(char *s, char c);
char *_strncpy(char *dest, char *src, int n);
char *_memcpy(char *dest, char *src, unsigned int n);

char *getpath(void);
int check_cmd(char *command, char **path, char buf[]);
void process(char **path);
void execute(pid_t pid, char *command, char **args);

/* General functions */
char *_getenv(char *s);
ssize_t _getline(char **lineptr, size_t *n, int fd);

#endif
