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

/**
  * _realloc - reallocates memory size.
  * @ptr: old pointer.
  * @size: new size.
  * Return: a pointer to the newly allocated memeory.
  */
void *_realloc(void *ptr, size_t size)
{
	void *new_ptr = malloc(size);

	if (!new_ptr)
		return (NULL);
	_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}

/**
  * _buffer_free - free a buffer array.
  * @arg: buffer to free.
  */
void _buffer_free(char **arg)
{
	int i;

	for (i = 0; arg[i]; i++)
		free(arg[i]);
	free(arg);
}
