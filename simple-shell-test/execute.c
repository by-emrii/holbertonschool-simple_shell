#include "shell.h"

/**
 * execute - fork and executes command
 * @argv: argument array
 * Return: 0 (success), 1 - failure
 */

int execute(char **argv)
{
	pid_t child_pid;
	int status;
	char *path = NULL;

	if (!argv || !argv[0])
		return (0);

	if (handle_builtin_cmds(argv))
		return (0);

	/* check if command has '/' */
	if (strchr(argv[0], '/'))
	{
		if (access(argv[0], X_OK) == 0)
			path = strdup(argv[0]);
	}
	else
		path = get_full_path(argv[0]);

	if (!path)
	{
		fprintf(stderr, "%s: command not found\n", argv[0]);
		return (1);
	}
	
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error with fork");
		free(path);
		return (1);
	}

	/* child process */
	if (child_pid == 0)
	{
		if (execve(path, argv, environ) == -1)
		{
			free(path);
			perror("Error with execution");
			exit(127); /* cmd not found */
		}
	}
	else
		wait(&status);

	free(path);
	return (0);
}
