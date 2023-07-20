#include "main.h"

/**
  * process - process the input.
  */
void process(char **path)
{
	char *str = NULL, **args;
	size_t size = 1024, i;
	int found;

	if (getline(&str, &size, stdin) == -1)
		exit(98);

	args = _tokenize2(str, " ");
	/* Test */
	for (i = 0; args[i]; i++)
		printf("args[%ld]: %s\n", i, args[i]);
	/**
	 * decied wether built-in, alias, executable.
	 * execute()
	 **/
	found = check_cmd(args[0], path);
	/* Test */
	printf("found %d\n", found);
}
