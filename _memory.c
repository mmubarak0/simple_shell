#include "main.h"

/**
  * _memset - fills memory with a constant byte.
  * @s: memory area to fill
  * @b: constant byte to fill with
  * @n: first n bytes to be filled
  * Return: pointer to memory area s
  */
char *_memset(char *s, char b, unsigned int n)
{
	char *str = s;
	unsigned int i;

	for (i = 0; i < n; i++)
		*(str + i) = b;
	return (s);
}

/**
  * _memcpy - copies memory area.
  * @dest: destnation buffer
  * @src: buffer to copy from
  * @n: number of bytes to copy
  * Return: pointer to dest
  */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		*(dest + i) = src[i];

	return (dest);
}
