#include "main.h"

/**
  * isnum - check for numbers
  * @a: character to test
  * Return: 1 if number 0 otherwise
  */
int isnum(char a)
{
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}

/**
  * hyphens - check number of minus signs
  * @string: string to check
  * @i: where the iteration stopped
  * Return: number of hyphens
  */
int hyphens(char *string, int *i)
{
	char *str = string;
	int sum = 0;

	while (!isnum(*str) && *str != '\0')
	{
		(*i)++;
		if (*str++ == '-')
			sum++;
	}
	return (sum);
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
