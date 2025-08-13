#include <stdio.h>
#include <string.h>

extern char **environ;

char *_getenv(const char *name)
{
	size_t length = strlen(name);
	char **env = environ;

	while (*env != NULL)
	{
		/* compare current env str is same length as name and next char is = */
		if (strncmp(*env, name, length) == 0 && (*env)[length] == '=')
		{
			/* return ptr value after = */
			return &((*env)[length + 1]);
		}
		env++;
	}
	return (NULL); /* not found otherwise */
}

int main(void)
{
	char *path = _getenv("PATH");

	if (path != NULL)
		printf("PATH=%s\n", path);
	else
		printf("PATH not found\n");

	return (0);
}
