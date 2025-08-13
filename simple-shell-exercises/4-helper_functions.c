#include "ss.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * add_node - function that adds a new node at the beginning of the list
 * @head: double ptr to the head of list
 * @str: the string to be dup and add
 * Return: the address of the new element, or NULL
 */
path_list_t *add_node(path_list_t **head, const char *str)
{
	path_list_t *new_node;
	int i = 0;

	new_node = malloc(sizeof(path_list_t));

	if (!new_node)
		return (NULL);

	new_node->str = strdup(str); /* dup input str, now points to copy*/
	if (!new_node->str) /* if dup failed, clean up, free node */
	{
		free(new_node);
		return (NULL);
	}

	while (str[i] != '\0')
	{
		i++;
	}

	new_node->len = i;
	new_node->next = *head; /* connects new node to current head of list*/
	*head = new_node; /* update head pointer to new node, at front*/

	return (new_node);
}

/**
 * add_node_end - function that adds a new node at the end of the list
 * @head: double ptr to head of the list
 * @str: str to dup into new node
 * Return: addy of new element, null if failed
 */
path_list_t *add_node_end(path_list_t **head, const char *str)
{
	path_list_t *new_node, *temp_node;
	int i = 0;

	new_node = malloc(sizeof(path_list_t));

	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	while (str[i] != '\0')
		i++;

	new_node->len = i;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		temp_node = *head;
		while (temp_node->next != NULL) /* traverse until end of list*/
		{
			temp_node = temp_node->next;
		}
		temp_node->next = new_node;
	}
	return (new_node);
}

/**
 * print_list - function that prints all the elements of a list_t list
 * @h: pointer to the head of the list
 * Return: number of nodes
 */
size_t print_list(const path_list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);

		h = h->next;
		count++;
	}
	return (count);
}

/**
 * free_list - function that frees a list_t list
 * @head: ptr to the head the list
 * Return: void
 */
void free_list(path_list_t *head)
{
	path_list_t *temp_node;

	while (head != NULL)
	{
		temp_node = head->next; /* save the next node first */
		free(head->str);
		free(head); /* free current head */
		head = temp_node;
	}
}
