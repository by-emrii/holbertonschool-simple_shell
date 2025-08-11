#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - entry point
 * Desc: function that splits a string
 * @ac: argument count
 * @av: double ptr argument vector
 * Return: 0 on success
 */


int main(int ac, char **av)
{
	char *prompt = "$ ";
	char *lineptr = NULL;
	size_t n = 0;
	char delim[] = " \n";
	char *token;

	(void)ac;
	(void)av;
	
	/* print shell prompt first for input */
	printf("%s", prompt);

	if (getline(&lineptr, &n, stdin) == -1)
	{
		perror("getline");
		free(lineptr);
		return (1); /* fail */
	}	
	
	/* get first token */
        token = strtok(lineptr, delim);

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}
	free(lineptr);
	return (0);
}
