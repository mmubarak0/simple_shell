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
		if (str[counter] == *split)
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
			toks[index++] = strdup(str + counter);
			break;
		}
		str[counter + locate] = '\0';
		toks[index++] = strdup(str + counter);
		counter = counter + locate + 1;
	}
	toks[index] = NULL;
	return (toks);
}

/**
 * _tokenize2 - function that split a string into tokens.
 * @str: the string to tokenize
 * @split: the delim used to split's string.
 * Return: the tokenize string on success, on failure NULL.
 */
char **_tokenize2(char *str, char *split)
{
	char *token, **toks;
	int i, j, size;

	i = 0;
	while (str[i])
	{
		for (j = 0; split[j]; j++)
			if (str[i] == split[j])
				size++;
		i++;
	}
	token = strtok(str, split);
	toks = malloc(sizeof(char *) * (size + 2));

	if (!toks)
		perror("Allocation faild");
	i = 0;
	while (token)
	{
		toks[i++] = token;
		token = strtok(NULL, split);
	}
	toks[i] = NULL;

	return (toks);
}
