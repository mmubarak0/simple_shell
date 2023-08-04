#ifndef MAIN_H
#define MAIN_H

/*---------------------------------------------------------------------------*/
/*
 * SIMPLE_SHELL - HEADER FILES.
 */
/*---------------------------------------------------------------------------*/

/* ------- */
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/* ------- */

/*---------------------------------------------------------------------------*/
/*
 * SIMPLE_SHELL - CONSTANTS.
 */
/*---------------------------------------------------------------------------*/

/* ------- */
#define MAX_LENGTH 1024
#define BUFFER_SIZE 7000
#define EXIT0x1 56
#define EXIT0x2 57
extern char **environ;
/* ------- */

/*---------------------------------------------------------------------------*/
/*
 * SIMPLE_SHELL - STRUCTURES.
 */
/*---------------------------------------------------------------------------*/

/* ------- */
/**
  * struct dynamic_ref - dynamic reference to some variables.
  * @command_number: command execution order number.
  * @exit_status: prev exit status.
  * @argc: argument count.
  * @cmd_buf: command buffer.
  * @path: variable holding the path env.
  * @file_name: file name.
  * @current_command: current command in process.
  * @argv: argument vector.
  * @cmd_argv: current command arguments vector.
  * @env: enviroment variables.
  */
typedef struct dynamic_ref
{
	unsigned int command_number;
	int exit_status;
	int argc;
	char cmd_buf[MAX_LENGTH];
	char *file_name;
	char **path;
	char **current_command;
	char **argv;
	char **cmd_argv;
	char **env;
} ref_t;
/* ------- */

/* ------- */
/**
  * struct identifier - select the function to process the format
  * @type: -> char: format type.
  * @function: -> pointer to a function taking va_list as argument return int:
  * function to process the format.
  */
typedef struct identifier
{
	char type;
	int (*function)(va_list, int);
} id;
/* ------- */

/*---------------------------------------------------------------------------*/
/*
 * SIMPLE_SHELL - FUNCTIONS.
 */
/*---------------------------------------------------------------------------*/

/*-> help functions used across the source code */
/*-> strings1.c, strings2.c, strings3.c */
/* ------- */
char *_strncpy(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);
int _strlen(char *str);
int _empty_input(char *str);
/* ------- */

/*-> Memory.c */
/* ------- */
char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, size_t size);
void _buffer_free(char **arg);
/* ------- */

/*-> Utilities.c */
/* ------- */
char *_dtos(long);
int _atoi(char *s);
void init_ref(ref_t *ref, unsigned int command_number, int exit_status,
		int argc, char cmd_buf, char *file_name, char **current_command,
		char **argv, char **path, char **cmd_argv, char **env);
char *_getenv(char *s);
char **_tokenize(char *str, char *split);
ssize_t _getline(char **lineptr, size_t *n, int fd);
/* ------- */

/*-> Eval.c */
/* ------- */
void _execute_file_command(ref_t *ref);
void _execute_builtin_command(ref_t *ref);
/* ------- */

/*-> Parser.c */
/* ------- */
void _readline(ref_t *);
void _process(ref_t *);
void _free_ref(ref_t *);
int _check_command(char *command, ref_t *ref);
/* ------- */

/*-> Printing */
/* ------- */
int _putchar(char c, int);
int print_c(va_list, int);
int print_s(va_list, int);
int print_d(va_list, int);
void id_select(const char *a, va_list args, int);
/* ------- */

/* print to stdout */
/* ------- */
int _printf(const char *format, ...);
/* ------- */

/* print to stderr */
/* ------- */
int _printe(const char *format, ...);
/* ------- */

/*-> _errors handling */
/* ------- */
/* ------- */

#endif
