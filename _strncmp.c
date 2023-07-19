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
	size_t i;

	if (!s1 || !s2)
		return (-1);

	for (i = 0; *s1 != '\0'; i++)
		if (*s1++ != *s2++ || i == n)
			break;

	return (*s1 - *s2);
}
