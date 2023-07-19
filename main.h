#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

/* -> utilities functions */

char **_tokenize(char *str, char *split);

char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strncmp(char *s1, char *s2, size_t n);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);
int _strlen(const char *str);
char *getpath(void);

/* General functions */
char *_getenv(char *s);

#endif
