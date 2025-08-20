#include "shell.h"

/**
 * main - entry point
 * Return: 0 (success)
 */

int main(int argc, char **argv)
{
	char *line = NULL;
	char **args;
	size_t len = 0;
	ssize_t read;
	char *progname = argv[0];
	int line_count = 1;

	(void)argc;

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

		args = parse_line(line);
		execute(args, progname, line_count);
		free(args);
		line_count++;
	}
	free(line);
	return (0);
}
