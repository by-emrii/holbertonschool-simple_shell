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
	char *argv[1024]; /* only cmds, no args */
	int i = 0;
	char *token, *path = NULL;

	if (line[strlen(line) - 1] == '\n')
		line[strlen(line) - 1] = '\0';

	/* Split strings */
	token = strtok(line, " \t"); /* spaces and tabs are delimiters */
	while (token != NULL)
	{
		argv[i++] = token;
		token = strtok(NULL, " \t");
	}
	argv[i] = NULL; /* execve expects a NULL terminated arr */

	if (argv[0] == NULL)
		return (0);

	if (strcmp(argv[0], "exit") == 0)
	{
		/* no fork, just exit */
		exit(0);
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
		return (1);
	}
	
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error with fork");
		return (1);
	}

	/* child process */
	if (child_pid == 0)
	{
		if (execve(path, argv, environ) == -1)
		{
			free(path);
			exit(127); /* cmd not found */
		}
	}
	else
	{
		 wait(&status);
	}
	free(path);
	return (0);
}
