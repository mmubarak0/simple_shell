#include "main.h"
#include <stdlib.h>

/**
 * _dtos - integer to string.
 * @d: integer to convert
 * Return: char pointer
 */
char *_dtos(long d)
{
	int len = 1;
	int sign = 0;
	int i = 0;
	int ent;
	long div = 10;
	char *buff;

	if (d < 0)
	{
		sign = 1;
		d = -d;
	}
	while (d / div > 0)
	{
		div *= 10;
		len++;
	}
	buff = malloc(sizeof(char) * len + sign + 1);
	if (sign)
		buff[i++] = '-';
	while (div > 1)
	{
		div /= 10;
		ent = d / div;
		buff[i++] = '0' + (ent % 10);
	}
	buff[i] = '\0';
	return (buff);
}
