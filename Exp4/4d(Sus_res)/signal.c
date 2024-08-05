#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid == -1) {
        printf("\nChild not created\n");
    } else if (pid == 0) {
        printf("\nChild created\n");
        while (1) {
            printf("Child process is running...\n");
            sleep(1);
        }
    } else {
        printf("\nParent process\n");
        kill(pid, SIGSTOP); // Suspend the child process
        printf("Child process suspended\n");
        
        sleep(5); // Wait for 5 seconds
        
        kill(pid, SIGCONT); // Resume the child process
        printf("Child process resumed\n");
        
        sleep(10); // Wait for 10 seconds
        
        printf("\nParent got control back\n");
        kill(pid, SIGKILL); // Terminate the child process
        wait(NULL); // Wait for the child process to terminate
    }

    return 0;
}

/*
gcc signal.c -o signal
./signal
*/