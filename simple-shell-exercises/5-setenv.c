#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ss.h"

extern char **environ;

int _setenv(const char *name, const char *value, int overwrite)
{
	size_t name_len, value_len;
	char **env = environ; /* ptr to walk thru environ array*/
	char **new_environ;
	char *new_var;
	size_t count = 0;

	/* name or value can't be NULL, and name cannot contain '=' */
	if (!name || !value || strchr(name, '=') != NULL)
		return (-1);

	name_len = strlen(name);
	value_len = strlen(value);

	/* check if existing var exists */
	while (env[count] != NULL)
	{
		if (strncmp(env[count], name, name_len) == 0 && env[count][name_len] == '=')
		{
			if (overwrite == 0)
				return (0); /* success, nothing to change */

			/* build "name=value" string */
			new_var = malloc(name_len + 1 + strlen(value) + 1);
			if (!new_var)
				return (-1);
			
			strcpy(new_var, name);
			new_var[name_len] = '=';
			strcpy(new_var + name_len + 1, value); /* copy value after '=' */

			free(env[count]); /* free old str */
			env[count] = new_var; /* replace with new string */
			return (0);
		}
		count++; /* move to next variable */
	}
	
	/* once this is reached = variable not found - append a new one into environ array */

	/* resize environ to hold one more var plus null terminator */
	new_environ = realloc(environ, sizeof(char *)* (count + 2));
	if (!new_environ)
		return (-1);
	environ = new_environ; /* update global environ ptr */

	/* new "name=value" string*/
	new_var = malloc(name_len + 1 + value_len + 1);
	if (!new_var)
		return (-1);
	strcpy(new_var, name);
	new_var[name_len] = '=';
	strcpy(new_var + name_len + 1, value);

	environ[count] = new_var; /* put new var at the end */
	environ[count + 1] = NULL; /* terminate array with NULL*/

	return (0);
}

int main(void)
{
       	char **env;
	
	printf("Before\n");
	for (env = environ; *env != NULL; env++)
		printf("%s\n", *env);
	
	printf("\nAdding NEW_VAR\n");
	_setenv("NEW_VAR", "hello", 0);
	
	printf("\nAfter adding\n");
	for (env = environ; *env != NULL; env++)
        printf("%s\n", *env);
	
	printf("\nOverwriting NEW_VAR\n");
	_setenv("NEW_VAR", "world", 1);
	
	printf("\nAfter overwrite\n");
	for (env = environ; *env != NULL; env++)
		printf("%s\n", *env);
	
	return (0);
}


