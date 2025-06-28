#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCKET_PATH "/tmp/uds_socket"

int main() {
    int server_fd, client_fd;
    struct sockaddr_un addr;
    char buffer[1024] = {0};

    unlink(SOCKET_PATH);
    server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, SOCKET_PATH);

    bind(server_fd, (struct sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 5);

    printf("UDS Server waiting for connection...\n");
    socklen_t len = sizeof(addr);
    client_fd = accept(server_fd, (struct sockaddr*)&addr, &len);

    read(client_fd, buffer, sizeof(buffer));
    printf("Received: %s\n", buffer);
    write(client_fd, "Hello from UDS Server", 23);

    close(client_fd);
    close(server_fd);
    unlink(SOCKET_PATH);
    return 0;
}
