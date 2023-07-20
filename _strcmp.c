#include "main.h"

/**
  * _strcmp - compares two strings.
  * @s1: string 1
  * @s2: string 2
  * Return: 0 if equalls an integer otherwise
  */
int _strcmp(char *s1, char *s2)
{
	int len_s1 = 0, len_s2 = 0;
	int i = 0, n;
	char *a = s1;
	char *b = s2;

	while (*a++ != '\0')
		len_s1++;
	while (*b++ != '\0')
		len_s2++;

	n = (len_s1 > len_s2) ? len_s1 : len_s2;

	while (s1[i] == s2[i] && i < n)
		i++;

	return (s1[i] - s2[i]);
}
