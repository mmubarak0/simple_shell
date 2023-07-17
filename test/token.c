#include "main.h"

char **tokenize(char *str, char *split, size_t size)
{
	char *token, **toks;
	int i;

	token = strtok(str, split);
	toks = malloc(sizeof(char *) * size);
	
	if (!toks)
		perror("Allocation faild");
	i = 0;
	while (token)
	{
		toks[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	
	return (toks);
}
