#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE

#define MAX_LENGTH 4096
#define BUFFER_SIZE 7000

#include <string.h>
#include <stdarg.h>
#include <stddef.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

/**
  * struct refs - bala
  * @ptr1: a
  * @ptr2: b
  * @ptr3: c
  */
typedef struct refs
{
	char **ptr1;
	char **ptr2;
	char **ptr3;
} ref_t;

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
	int (*function)(char **args, ref_t *, char *pname);
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
char *_readline(int *command_num, int isaty, ref_t *);
char *_dtos(long);
char *read_textfile(char *filename, size_t letters);

char *getpath(void);
int check_cmd(char *command, char **path, char buf[]);
void process(char **path, char *pname, int isaty);
void process_file(char **path, char *pname, char *fname);
void execute(pid_t pid, char *command, char **args);
void built(char **args, ref_t *, char *pname);
void eval(char *command, char **args);
void cmd_not_found(char *pname, int command_num, char *command);
void free_buf(char **arg);
void print_illegal_number(char **args, char *pname);

/* General functions */
char *_getenv(char *s);
ssize_t _getline(char **lineptr, size_t *n, int fd);
int _putenv(char *string);
int set_err_code(int);
int get_err_code(void);
int set_cmd_num(int);
int get_cmd_num(void);

/* printing functions */
int _putchar(char, int);
int print_c(char c, int);
int print_s(char *s, int);
int print_d(long d, int);

/* built-ins function */

int _ext(char **arg, ref_t *, char *);
int _env(char **arg, ref_t *, char *);
int _setenv(char **arg, ref_t *, char *);
int _unsetenv(char **arg, ref_t *, char *);
int _cd(char **arg, ref_t *, char *);

#endif
