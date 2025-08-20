#include "shell.h"

char **parse_line(char *line)
{
	char **argv;
	char *token;
	int i = 0;

	argv = malloc(sizeof(char *) * 1024);
	if (!argv)
		return (NULL);

	/* remove trailing newline */
	if (line[strlen(line) - 1] == '\n')
		line[strlen(line) - 1] = '\0';

	/* split strings */
	token = strtok(line, " \t"); /* spaces and tabs are delimiters */
	while (token != NULL)
	{
		argv[i++] = token;
		token = strtok(NULL, " \t");
	}
	argv[i] = NULL; /* execve expects a NULL terminated arr */
	return (argv);
}
