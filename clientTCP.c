//
// Created by Alexis on 05/03/2024.
//

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/tcp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

struct sockaddr_in serv_addr;
int sockfd;

void *receiveMessage(void *socket) {
    int sockfd = *(int*)socket;
    char buffer[256];
    while(1) {
        int n = recv(sockfd, buffer, 255, 0);
        if (n > 0) {
            printf("\nMessage from server: %s\n", buffer);
        } else if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        bzero(buffer, 256);
    }
}

void *sendMessage(void *socket) {
    int sockfd = *(int*)socket;
    char buffer[256];
    while(1) {
        bzero(buffer, 256);
        fgets(buffer, 255, stdin);
        int n = send(sockfd, buffer, strlen(buffer), 0);
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
    }
}

int main(int argc, char *argv[]) {

    if (argc < 3) {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(0);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons( (ushort) atoi(argv[2]) );
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    } else {
        printf("Connected to server\n");

        if(fork()) {
            receiveMessage(&sockfd);
        } else {
            sendMessage(&sockfd);
        }
    }


}

