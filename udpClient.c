#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8081

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[1024];
    socklen_t len;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

    sendto(sockfd, "Hello UDP Server", 17, 0, (struct sockaddr*)&servaddr, sizeof(servaddr));
    recvfrom(sockfd, buffer, 1024, 0, NULL, NULL);
    printf("Server reply: %s\n", buffer);

    close(sockfd);
    return 0;
}
