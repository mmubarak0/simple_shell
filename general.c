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
  * set_err_code - set the value of ERR_CODE.
  * @err: new error value.
  * Return: return the value of ERR_CODE.
  */
int set_err_code(int err)
{
	static int ERR_CODE;

	if (-99 == err)
		return (ERR_CODE);
	ERR_CODE = err;
	return (err);
}

/**
  * get_err_code - get the value of ERR_CODE.
  * Return: ERR_CODE.
  */
int get_err_code(void)
{
	return (set_err_code(-99));
}
