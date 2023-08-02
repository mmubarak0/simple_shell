#include "main.h"

/**
 * _strcpy - function that copies src string to dest string.
 * @dest: dest ptr holds the copied string.
 * @src: src ptr to copy from.
 * Return: dest ptr on success, NULL on failrue.
 */

char *_strcpy(char *dest, char *src)
{
	int i;
	int len;

	len = _strlen(src);

	if (!dest || !src)
		return (NULL);
	for (i = 0; i <= len; i++)
		dest[i] = src[i];

	return (dest);
}

/**
  * _strcat - function that concatenates two strings.
  * @dest: string that will hold appended src
  * @src: string to append
  * Return: address of dest
  */

char *_strcat(char *dest, char *src)
{
	int dest_len = 0, i = 0;
	char *a = dest, *b = src;

	while (*a++ != '\0')
		dest_len++;

	while (*b++ != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';

	return (dest);
}

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
