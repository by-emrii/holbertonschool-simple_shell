#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_path_dir(void)
{
	char *path = getenv("PATH");
	char *copy, *dir_token;

	if (path == NULL)
		return;

	copy = strdup(path);
	if (copy == NULL)
		return;

	dir_token = strtok(copy, ":");
	while (dir_token != NULL)
	{
		printf("%s\n", dir_token);
		dir_token = strtok(NULL, ":");
	}
	free(copy);
}

int main(void)
{
	print_path_dir();
	return (0);
}
