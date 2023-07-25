#include "main.h"
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile - reads text file and prints it to the POSIX standard output.
 * @filename: file name.
 * @letters: number of letters to print.
 * Return: string in the file
 */
char *read_textfile(char *filename, size_t letters)
{
	int fd, rd;
	char *buf;

	fd = rd = 0;
	if (!filename || !letters)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);

	buf = malloc(sizeof(char) * letters + 1);
	if (!buf)
		return (0);
	rd = read(fd, buf, letters);
	if (rd < 0)
	{
		free(buf);
		return (0);
	}
	buf[letters] = '\0';

	close(fd);
	return (buf);
}
