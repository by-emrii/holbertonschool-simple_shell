#include "shell.h"

char **parse_line(char *line)
{
	char **args;
	char *token;
	int i = 0;

	args = malloc(sizeof(char *) * 1024);
	if (!args)
		return (NULL);

	/* remove trailing newline */
	if (line[strlen(line) - 1] == '\n')
		line[strlen(line) - 1] = '\0';

	/* split strings */
	token = strtok(line, " \t"); /* spaces and tabs are delimiters */
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " \t");
	}
	args[i] = NULL; /* execve expects a NULL terminated arr */
	return (args);
}
