#include "main.h"

/**
  * free_buf - free a buffer array.
  * @arg: buffer to free.
  */
void free_buf(char **arg)
{
	int i;

	for (i = 0; arg[i]; i++)
		free(arg[i]);
	free(arg);
}
