#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("=== Process Control Calls ===\n");

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        printf("Child: PID %d\n", getpid());
        execlp("ls", "ls", "-l", NULL);
        perror("execlp");
        exit(1);
    } else {
        wait(NULL);
        printf("Parent: Child finished.\n");
    }

    return 0;
}

