#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

#define PORT 8081

int main() {
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[1024];
    socklen_t len;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    printf("UDP Server waiting for data...\n");

    len = sizeof(cliaddr);
    recvfrom(sockfd, buffer, 1024, 0, (struct sockaddr*)&cliaddr, &len);
    printf("Received: %s\n", buffer);

    sendto(sockfd, "Hello from UDP Server", 22, 0, (struct sockaddr*)&cliaddr, len);
    close(sockfd);
    return 0;
}
