#include "main.h"

/**
  * _realloc - reallocates memory size.
  * @ptr: old pointer.
  * @size: new size.
  * Return: a pointer to the newly allocated memeory.
  */
void *_realloc(void *ptr, size_t size)
{
	void *new_ptr = malloc(size);

	if (new_ptr == NULL)
	{
		return (NULL);
	}
	memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}
