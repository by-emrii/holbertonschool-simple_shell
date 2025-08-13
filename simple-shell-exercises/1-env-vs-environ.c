#include <stdio.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	printf("address of env: %p\n", (void *)env);
	printf("address of environ: %p\n", (void *)environ);

	return (0);
}
