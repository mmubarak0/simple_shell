#include "main.h"

/**
 * _strcpy - function that copies src string to dest.
 * @dest: dest ptr holds the copied string.
 * @src: src ptr to copy from
 * Return: return dest ptr on Success
 */

char *_strcpy(char *dest, char *src)
{
	int i;
	int length;

	length = strlen(src);

	for (i = 0; i <= length; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
