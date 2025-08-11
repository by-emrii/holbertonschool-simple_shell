#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t parent_pid = getppid();
	printf("My parent's process ID is: %d\n", parent_pid);
	return (0);
}
