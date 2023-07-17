#include "findcmd.h"
#include "general.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>


/**
  * get_path_folders - find all folders in the path.
  * @env: environment variables.
  * Return: the head of a singly linked list.
  */
path_t *get_path_folders(char **env)
{
	char *token;
	char *s;
	path_t *pathes = NULL;
	path_t *head;
	path_t *p;

	s = _getenv("PATH", env, 4);
	token = strtok(s, ":");
	while (token != NULL)
	{
		p = malloc(sizeof(path_t));
		p->str = token;
		if (pathes == NULL)
		{
			pathes = p;
			head = p;
		}
		else
		{
			head->next = p;
			head = p;
		}
		token = strtok(NULL, ":");
	}
	return (pathes);
}

/**
  * check_cmd - check the availablity of the command.
  * @command: command to check for.
  * @env: environment variables.
  * Return: 1 (SUCCESS). -1 if not found or failed.
  */
int check_cmd(char *command, char **env)
{
	path_t *head;
	char *result;

	if (access(command, F_OK) != -1)
		return (1);
	head = get_path_folders(env);
	while (head != NULL)
	{
		/*
		 * TODO replace strcat with -> _strcat.
		 * TODO replace strcpy with -> _strcpy.
		 */
		result = malloc(strlen(command) + strlen(head->str) + 2);
		strcpy(result, head->str);
		if (result[strlen(result) - 1] != '/')
			strcat(result, "/");
		strcat(result, command);
		printf("%s\n", result);
		if (access(result, F_OK) != -1)
			return (1);
		head = head->next;
	}
	return (-1);
}
