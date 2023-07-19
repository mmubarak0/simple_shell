#include "main.h"

/**
 * _tokenize - function that split a string into tokens, our own (strtok).
 * @str: the string to tokenize
 * @split: the delim used to split's string.
 * Return: the tokenize string on success, on failure NULL.
 */

char **_tokenize(char *str, char *split)
{
	size_t locate, index = 0;
	size_t counter, delim = 0;
	char **toks;

	if (!str || !split)
		return (NULL);


	for (counter = 0; str[counter]; counter++)
		if(str[counter] == *split)
			delim++;

	toks = (char **)malloc(sizeof(char *) * (delim + 2));

	if (!toks)
	{
		perror("malloc");
		return (NULL);
	}

	counter = 0;
	while (str[counter])
	{
		while (str[counter] == *split)
			counter++;

		locate = strcspn(str + counter, split);
		if (locate == counter)
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
