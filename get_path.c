#include "main.h"

/**
  * getpath - Path environment variable value.
  * Return: char pointer to path value.
  */
char *getpath(void)
{
	return (_getenv("PATH"));
}
