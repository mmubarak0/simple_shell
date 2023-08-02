#include "main.h"

/**
  * _strlen - return the length of the string
  * @str: string
  * Return: length of the str.
  */

int _strlen(char *str)
{
	int i = 0;

	if (!str)
		return (-1);
	while (str[i])
		i++;
	return (i);
}

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

/**
  * _strncpy - copies a string.
  * @dest: destnation string
  * @src: source string
  * @n: number of bytes from src to be copied
  * Return: destnation address
  */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for ( ; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
