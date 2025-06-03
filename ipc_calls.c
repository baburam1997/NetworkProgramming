#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/socket.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <string.h>

int main() {
    printf("=== IPC Calls ===\n");

    // Pipe
    int fd[2];
    pipe(fd);
    pid_t pid = fork();
    if (pid == 0) {
        close(fd[0]);
        write(fd[1], "IPC Pipe Msg\n", 13);
        close(fd[1]);
        exit(0);
    } else {
        close(fd[1]);
        char buf[100];
        read(fd[0], buf, sizeof(buf));
        printf("Pipe received: %s", buf);
        wait(NULL);
    }

    // Socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock >= 0) {
        printf("Socket created: %d\n", sock);
        close(sock);
    } else {
        perror("socket");
    }

    // Shared Memory
    int shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
    printf("Shared Memory ID: %d\n", shmid);

    // Semaphore
    int semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
    printf("Semaphore ID: %d\n", semid);

    // Message Queue
    int msgid = msgget(IPC_PRIVATE, IPC_CREAT | 0666);
    printf("Message Queue ID: %d\n", msgid);

    return 0;
}

