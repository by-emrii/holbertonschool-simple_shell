#include "shell.h"

/**
 * execute - executes single command
 * @line: command from user
 * Return: 0 (success), 1 - failure
 */

int execute(char *line)
{
	pid_t child_pid;
	int status;
	char **argv, *path = NULL;

	argv = parse_line(line);
	if (!argv || argv[0] == NULL)
	{
		free(argv);
		return (0);
	}

	/* exit in built cmd */
	if (strcmp(argv[0], "exit") == 0)
	{
		/* no fork, just exit */
		exit(0);
	}

	/* env in built cmd */
	if (strcmp(argv[0], "env") == 0)
	{
		return (printenv());
	}

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
		free(argv);
		return (1);
	}
	
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error with fork");
		free(argv);
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
	{
		 wait(&status);
	}
	free(argv);
	free(path);
	return (0);
}
