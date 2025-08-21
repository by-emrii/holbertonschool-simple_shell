#include "shell.h"

/**
 * resolve_path - resolve command path
 * @args: 
 * Return: void
 */

char *resolve_path(char *args)
{
	/* check if command has '/' */
	if (strchr(args, '/'))
	{
		if (access(args, X_OK) == 0)
			return (strdup(args));
		return (NULL);
	}
	return (get_full_path(args));
}
