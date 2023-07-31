#include "main.h"

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

/**
  * _atoi - convert a string to integer
  * @s: string to convert
  * Return: integer that is converted
  */

int _atoi(char *s)
{
	int i = 0, num, mul = 1;
	unsigned int ans = 0;
	char *a = s;

	num = hyphens(a, &i);

	a += i;
	while (isnum(*++a) && *a != '\0')
		mul *= 10;

	s += i;
	while (isnum(*s) && *s != '\0')
	{
		ans += (*s++ - '0') * mul;
		mul /= 10;
	}
	if (num % 2)
		return (-((unsigned int)ans));
	return (ans);
}
