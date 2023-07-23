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
