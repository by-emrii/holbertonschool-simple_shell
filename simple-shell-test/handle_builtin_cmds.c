#include "shell.h"

/**
 * handle_builtin_cmds - check and execute built in commands
 * @argv: argument array
 * Return: 1 if handled, 0 otherwise
 */
int handle_builtin_cmds(char **argv)
{
	int j;

	if (!argv || !argv[0])
		return (0);

	/* exit in built cmd */
	if (strcmp(argv[0], "exit") == 0)
	{
		/* no fork, just exit */
		exit(0);
	}

	/* env in built cmd */
	if (strcmp(argv[0], "env") == 0)
	{
		for (j = 0; environ[j]; j++)
			printf("%s\n", environ[j]);
		return (1);
	}
	return (0);
}
