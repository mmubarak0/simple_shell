#include "main.h"

/**
  * _strcat - concatenates two strings.
  * @dest: string that will hold appended src
  * @src: string to append
  * Return: address of dest
  */
char *_strcat(char *dest, char *src)
{
	int dest_len = 0, i = 0;
	char *a = dest, *b = src;

	while (*a++ != '\0')
		dest_len++;

	while (*b++ != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';

	return (dest);
}
