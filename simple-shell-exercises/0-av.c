#include <stdio.h>
#include <stdlib.h>

/**
 *main - entry point
 * @ac: argument count
 * @av: double ptr argument vector
 * Return: return (0) on success
 */

int main(int ac, char **av)
{
	(void)ac;
	int i = 0;

	while (av[i] != NULL)
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}
