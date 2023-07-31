#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*-> help functions used across the source code */

/*-> strings1.c, strings2.c */
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);
int _strlen(char *str);
char *_strchr(char *s, char c);
char *_strncpy(char *dest, char *src, int n);

/*-> _memory.c */
char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);

/*-> _utilities.c */
char *_dtos(long);
int _atoi(char *s);

/*-> printing to STDOUT */
/*-> _errors handling */

#endif
