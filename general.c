#include "general.h"
#include <string.h>

/**
  * _getenv - get the value of an environment variable.
  * @s: name of the env.
  * @env: env list.
  * @len: length of s.
  * Return: string corrospond to value of the s.
  */
char *_getenv(char *s, char **env, unsigned int len)
{
	unsigned int i = 0;

	/*
	 * TODO Replace strncmp with -> _strncmp.
	 */
	while (strncmp(env[i], s, len))
		i++;
	return (env[i] + len + 1);
}
