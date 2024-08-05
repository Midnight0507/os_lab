#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    pid_t ret_value;

    printf("\nThe process ID is %d\n", getpid());

    ret_value = fork();

    if (ret_value < 0)
    {
        // Fork has failed
        printf("\nFork Failure\n");
    }
    else if (ret_value == 0)
    {
        // Child process
        printf("\nChild Process\n");
        printf("The process ID is %d\n", getpid());
        sleep(20);
    }
    else
    {
        // Parent process
        wait(NULL);
        printf("Parent Process\n");
        printf("The process ID is %d\n", getpid());
        sleep(30);
    }

    return 0;
}
