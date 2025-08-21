#include "shell.h"

/**
 * execute - fork and executes command
 * @args: parsed argument array
 * @progname: program name for error messages, argv[0]
 * @line_count: current line for error msges
 * Return: 0 (success), 1 - failure
 */

int execute(char **args, char *progname, int line_count)
{
	pid_t child_pid;
	int status;
	char *path = NULL;

	if (!args || !args[0])
		return (0);
	if (handle_builtin_cmds(args))
		return (0);

	path = resolve_path(args[0]);
	if (!path)
	{
		fprintf(stderr, "%s: %d: %s: not found\n", progname, line_count, args[0]);
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
		if (execve(path, args, environ) == -1)
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
