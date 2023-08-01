#ifndef MAIN_H
#define MAIN_H

/*---------------------------------------------------------------------------*/
/*
 * SIMPLE_SHELL - HEADER FILES.
 */
/*---------------------------------------------------------------------------*/

#include <stdarg.h>
#include <stddef.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*---------------------------------------------------------------------------*/
/*
 * SIMPLE_SHELL - CONSTANTS.
 */
/*---------------------------------------------------------------------------*/

#define BUFFER_SIZE 7000
extern char **environ;

/*---------------------------------------------------------------------------*/
/*
 * SIMPLE_SHELL - STRUCTURES.
 */
/*---------------------------------------------------------------------------*/

/**
  * struct dynamic_ref - dynamic reference to some variables.
  * @command_number: command execution order number.
  * @exit_status: prev exit status.
  * @argc: argument count.
  * @path: variable holding the path env.
  * @file_name: file name.
  * @current_command: current command in process.
  * @argv: argument vector.
  */
typedef struct dynamic_ref
{
	unsigned int command_number;
	int exit_status;
	char *argc;
	char *path;
	char *file_name;
	char *current_command;
	char **argv;
} ref_t;

/*---------------------------------------------------------------------------*/
/*
 * SIMPLE_SHELL - FUNCTIONS.
 */
/*---------------------------------------------------------------------------*/

/*-> help functions used across the source code */
/*-> strings1.c, strings2.c */
char *_strncpy(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);
int _strlen(char *str);

/*-> Memory.c */
char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, size_t size);
void _buffer_free(char **arg);

/*-> Utilities.c */
char *_dtos(long);
int _atoi(char *s);

/*-> Printing */
int _putchar(char c, int n);
int print_c(char c, int file_no);
int print_s(char *s, int file_no);
int print_d(long d, int file_no);
/* print to stdout */
int _printf(const char *format, ...);
/* print to stderr */
int _printe(const char *format, ...);
void id_select(const char *a, va_list args, int n);

/*-> _errors handling */

#endif
