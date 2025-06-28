#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

#define PORT 8080

int main() {
    int server_fd, client_fd;
    struct sockaddr_in addr;
    char buffer[1024] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 3);

    printf("TCP Server is waiting for connection...\n");
    socklen_t len = sizeof(addr);
    client_fd = accept(server_fd, (struct sockaddr*)&addr, &len);
    
    read(client_fd, buffer, 1024);
    printf("Received: %s\n", buffer);
    send(client_fd, "Hello from TCP Server", 22, 0);
    
    close(client_fd);
    close(server_fd);
    return 0;
}
