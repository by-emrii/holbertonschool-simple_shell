#include "shell.h"

/**
 * get_full_path - searches PATH for a command
 * @command: command name
 * Return: ptr to full path or null if not found
 */

char *get_full_path(char *command)
{
	char *path_env;
	char *copy, *dir_token, *full_path;
	size_t len;

	path_env = getenv("PATH");

	if (!path_env || !command)
		return (NULL);

	copy = strdup(path_env);
	if (!copy)
		return (NULL);

	dir_token = strtok(copy, ":");
	while (dir_token != NULL)
	{
		/* allocate mem for - dir + "/" + cmd + '\0' */
		len = strlen(dir_token) + strlen(command) + 2;
		full_path = malloc(len);
		
		if (!full_path)
		{
			free(copy);
			return (NULL);
		}

		strcpy(full_path, dir_token);
		strcat(full_path, "/");
		strcat(full_path, command);

		/* check if this path exists, and is executable? */
		if (access(full_path, X_OK) == 0)
		{
			free(copy);
			return (full_path); /* success */
		}
		free(full_path);
		dir_token = strtok(NULL, ":");
	}
	free(copy);
	return (NULL); /* not found */
}
