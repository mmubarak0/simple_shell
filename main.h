#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE

#define MAX_LENGTH 4096
#define BUFFER_SIZE 1024

#include <string.h>
#include <stdarg.h>
#include <stddef.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/* built-ins function */

int _ext(__attribute__((unused))char **arg);
int _env(__attribute__((unused))char **arg);
int _cd(char **arg);
int _setenv(char **args);
/**
 * struct built - struct for built-ins commands
 * @command_name: name of the command
 * @function: pointer to the command's related function
 * Description: structer holds name of built-ins commands
 * ** and callback function.
 */

typedef struct built
{
	char *command_name;
	int (*function)(char **args);
} builts_cmd;

/**
  * struct identifier - select the function to process the format
  * @type: -> char: format type.
  * @function: -> pointer to a function taking va_list as argument return int:
  * function to process the format.
  */
typedef struct identifier
{
	char type;
	int (*function)(va_list, unsigned long *);
} id;

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
void *_realloc(void *ptr, size_t size);
int _atoi(char *s);
void print_strings(char *separator, unsigned int n, ...);
char *_readline(int *command_num);
char *_dtos(long);

char *getpath(void);
int check_cmd(char *command, char **path, char buf[]);
void process(char **path, char *pname);
void execute(pid_t pid, char *command, char **args);
void built(char **args);
void eval(char *command, char **args);
void cmd_not_found(char *pname, int command_num, char *command);

/* General functions */
char *_getenv(char *s);
ssize_t _getline(char **lineptr, size_t *n, int fd);

/* printing functions */
int _putchar(char);
int print_c(char c);
int print_s(char *s);
int print_d(long d);

#endif
