#include "main.h"

/**
 * _strcat - function that concatenate two strings
 * @dest: string to concatenate
 * @src: string to concatenate
 * Return: dest ptr on success
 */

char *_strcat(char *dest, char *src)
{
	int src_len, dest_len, i;

	src_len = strlen(src);
	dest_len = strlen(dest);

	for (i = 0; i <= src_len; i++)
		dest[dest_len + i] = src[i];

	return (dest);
}
