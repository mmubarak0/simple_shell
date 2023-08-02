#include "main.h"

/**
  * _getenv - get the value of an environment variable.
  * @s: name of the env.
  * Return: string corrospond to value of the s.
  */
char *_getenv(char *s)
{
	unsigned int i = 0;
	char **env = environ;
	size_t len = _strlen(s);

	while (env[i] && _strncmp(env[i], s, len))
		i++;

	if (env[i] == NULL)
		return (NULL);
	return (env[i] + len + 1);
}

/**
 * _tokenize - function that split a string into tokens, our own (strtok).
 * @str: the string to tokenize
 * @split: the delim used to split's string.
 * Return: the tokenize string on success, on failure NULL.
 */

char **_tokenize(char *str, char *split)
{
	char **toks;
	int delim = 0;
	int i, index = 0;
	int start, end;

	if (!str || !split)
		return (NULL);
	for (i = 0; str[i]; i++)
		if (_strchr(split, str[i]) != NULL)
			delim++;
	toks = (char **)malloc(sizeof(char *) * (delim + 2));
	if (!toks)
	{
		perror("malloc");
		return (NULL);
	}

	start = 0;
	while (str[start] != '\0')
	{
		while (str[start] != '\0' && _strchr(split, str[start]) != NULL)
			start++;
		if (str[start] == '\0')
			break;

		end = start;
		while (str[end] != '\0' && _strchr(split, str[end]) == NULL)
			end++;

		toks[index] = malloc(end - start + 1);
		_strncpy(toks[index], str + start, end - start);
		toks[index][end - start] = '\0';
		index++;
		start = end;
	}

	toks[index] = NULL;

	return (toks);
}

/**
  * _getline - read line from the file descriptor.
  * @lineptr: variable to store input.
  * @n: buffer size.
  * @fd: file descriptor.
  * Return: the number of bytes readed or -1 (eof, err, ...).
  */

ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	char buffer[BUFFER_SIZE];
	char *temp = NULL;
	ssize_t total = 0;
	ssize_t nread;

	if (lineptr == NULL || n == NULL)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		*n = BUFFER_SIZE;
		*lineptr = malloc((*n) + 1);
		if (*lineptr == NULL)
			return (-1);
	}
	while (1)
	{
		nread = read(fd, buffer, BUFFER_SIZE);
		if (nread == -1)
			return (-1);
		if (nread == 0)
			break;
		if ((size_t)(total + nread + 1) > *n)
		{
			*n = total + nread + 1;
			temp = (char *)_realloc(*lineptr, (*n) + 1);

			if (temp == NULL)
				return (-1);

			*lineptr = temp;
		}
		_memcpy(*lineptr + total, buffer, nread);
		total += nread;
		if (buffer[nread - 1] == '\n')
			break;
	}

	(*lineptr)[total] = '\0';
	return (total);
}
