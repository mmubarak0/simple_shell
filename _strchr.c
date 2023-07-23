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
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
