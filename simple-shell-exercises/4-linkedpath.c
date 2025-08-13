#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ss.h"

void path_linkedlist(path_list_t **head)
{
	char *path = getenv("PATH");
	char *copy, *dir;

	if (!path)
		return;

	copy = strdup(path);
	if (!copy)
		return;

	dir = strtok(copy, ":");
	while (dir != NULL)
	{
		add_node_end(head, dir);
		dir = strtok(NULL, ":");
	}
	free(copy);
}

int main(void)
{
	path_list_t *path_list = NULL;

	path_linkedlist(&path_list);
	print_list(path_list);
	free_list(path_list);

	return (0);
}
