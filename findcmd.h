#ifndef FINDCMD_H
#define FINDCMD_H

/**
  * struct ppath - linked list containing path folders.
  * @str: folder name.
  * @next: next pointer.
  */
typedef struct ppath
{
	char *str;
	struct ppath *next;
} path_t;

path_t *get_path_folders(char **env);
int check_cmd(char *command, char **env);

#endif /* FINDCMD_H */
