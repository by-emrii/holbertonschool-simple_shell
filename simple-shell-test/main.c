#include "shell.h"

/**
 * main - entry point
 * Return: 0 (success)
 */

int main(void)
{
	char *line = NULL;
	char **argv;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("($) ");
			fflush(stdout); /* makes sure it shows immediately */
		}

		read = getline(&line, &len, stdin);
		if (read == -1) /* EOF */
		{
			free(line);
			printf("\n"); /* so prompt looks neat */
			exit(0);
		}

		argv = parse_line(line);
		execute(argv);
	}
	free(line);
	return (0);
}
