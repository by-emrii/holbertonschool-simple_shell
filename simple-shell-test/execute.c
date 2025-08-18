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
	char *argv[100]; /* only cmds, no args */
	int i = 0;
	char *token;

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

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error with fork");
		return (1);
	}

	/* child process */
	if (child_pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], argv[0]);
			exit(127); /* cmd not found */
		}
	}
	else
	{
		 wait(&status);
	}
	return (0);
}
