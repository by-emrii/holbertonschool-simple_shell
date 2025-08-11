#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 * Write a program that prints "$ ",
 * wait for the user to enter a command, prints it on the next line.
 * @ac: argument count
 * @av: double ptr argument vector
 * Return: return (0) on success
 */


int main(int ac, char **av)
{
	char *prompt = "$ ";
	char *lineptr;
	size_t n = 0;

	(void)ac;
	(void)av;

	printf("%s", prompt);
	getline(&lineptr, &n, stdin);
	printf("%s", lineptr);

	free(lineptr);
	return (0);
}
