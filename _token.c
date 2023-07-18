#include "main.h"

/**
 * _tokenize - function that split a string into tokens, our own (strtok).
 * @str: the string to tokenize
 * @split: the delim used to split's string.
 * Return: the tokenize string on success, on failure ..
 */

char **_tokenize(char *str, char *split)
{
	size_t locate, index = 0;
	size_t length, counter;
	char **toks;

	length = strlen(str + 1);
	toks = malloc(sizeof(char *) * length + 1);

	if (!toks)
	{
		perror("Allocation failed");
	}

	counter = 0;
	while (counter < length)
	{
		locate = strcspn(str + counter, split);
		if (locate == length - counter)
		{
			toks[index] = strdup(str + counter);
			index++;
			break;
		}
		str[counter + locate] = '\0';
		toks[index] = strdup(str + counter);
		index++;
		counter = counter + locate + 1;
	}

	toks[index] = '\0';

	return (toks);

}
