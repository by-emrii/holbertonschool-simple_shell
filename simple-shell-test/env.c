#include "shell.h"

/**
 * printenv - prints the environment
 *
 * Return: 0 on success
 */
int printenv(void)
{
	int j = 0;

	while (environ[j])
	{
		printf("%s\n", environ[j]);
		j++;
	}
	return (0);
}
