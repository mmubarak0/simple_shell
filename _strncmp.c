#include "main.h"

/**
 * _strncmp - funciton that compare two strings.
 * @s1: the 1st string.
 * @s2: the 2nd string.
 * Return: (< 0) if first character doesn't match has a lower value in s1
 * 		than in s2.
 * 	** (0) if both strings are equal.
 * 	** (> 0) if first character doesn't match has greater value in s1
 * 		than in s2.
 */

int _strncmp(char *s1, char *s2, size_t n)
{
	size_t i;

	for (i = 0; s1[i] != '\0'; i++)
		if (s1[i] != s2[i] || i == n)
			break;

	return (s1[i] - s2[i]);
}
