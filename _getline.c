#include "main.h"

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
		*lineptr = malloc(*n);
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
			temp = (char *)_realloc(*lineptr, *n);

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
