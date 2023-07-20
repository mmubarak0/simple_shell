#include "main.h"
#include <stddef.h>

/**
  * _strchr - locates a character in a string.
  * @s: searching string
  * @c: character to search for
  * Return: pointer to first occurence of the c character
  */
char *_strchr(char *s, char c)
{
	char *str = s;

	while (*str != c && *str++ != '\0')
		continue;
	if (*str == '\0' && *str != c)
		return (NULL);

	return (str);
}
