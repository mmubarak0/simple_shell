#include "main.h"

/**
  * free_list - free a list_t
  * @head: head of the list.
  */
void free_list(list_t *head)
{
	list_t *p;

	p = head;
	while (p != NULL)
	{
		p = p->next;
		free(head->str);
		free(head);
		head = p;
	}
}
