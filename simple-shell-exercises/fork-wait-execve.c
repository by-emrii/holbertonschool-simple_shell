#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
        int i = 0;
        char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
        pid_t child_pid;
        int status;

        while (i < 5)
        {
                child_pid = fork();
                if (child_pid == -1) /* fork failed */
                {
                        perror("Error with fork");
                        return (1);
                }

                /* child process */
                if (child_pid == 0)
                {
                        printf("child process number %d with pid: %d is executing ls -l /tmp\n", i + 1, getpid());
                        if (execve(argv[0], argv, NULL) == -1)
                        {
                                perror("Error executing");
                                return (1);
                        }

                }
                else
                {
                        wait(&status);
                }
                i++;
        }
        return (0);
}
