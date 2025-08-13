#ifndef SS_H
#define SS_H

#include <stddef.h>

/**
 * struct path_list - singly linked list node for storing strings
 * @str: string (directory path)
 * @len: length of the string
 * @next: pointer to the next node
 */

typedef struct path_list
{
	char *str;
	unsigned int len;
	struct path_list *next;
} path_list_t;

/* helper func  prototypes */
path_list_t *add_node(path_list_t **head, const char *str);
path_list_t *add_node_end(path_list_t **head, const char *str);
size_t print_list(const path_list_t *h);
void free_list(path_list_t *head);

void path_linkedlist(path_list_t **head);


#endif
