#include "main.h"

/**
 * _strncmp - funciton that compare two strings.
 * @s1: the 1st string.
 * @s2: the 2nd string.
 * @n: buffer length to compare.
 * Return: (< 0) if first character doesn't match has a lower value in s1
 * than in s2.
 * ** (0) if both strings are equal.
 * ** (> 0) if first character doesn't match has greater value in s1
 * than in s2.
 */

int _strncmp(char *s1, char *s2, size_t n)
{
	if (!s1 || !s2)
		return (-1);

	while (n && *s1 && (*s1 == *s2))
	{
		++s1;
		++s2;
		--n;
	}
	if (n == 0)
		return (0);
	else
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
