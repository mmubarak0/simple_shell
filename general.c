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
