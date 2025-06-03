#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    printf("=== File System Calls ===\n");

    int fd = open("example.txt", O_CREAT | O_RDWR, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    write(fd, "Hello, World!\n", 14);
    lseek(fd, 0, SEEK_SET);

    char buffer[100];
    read(fd, buffer, sizeof(buffer));
    printf("Read content: %s", buffer);

    close(fd);
    return 0;
}

