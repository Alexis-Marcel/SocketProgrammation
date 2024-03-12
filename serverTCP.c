//
// Created by Alexis on 05/03/2024.
//

#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/tcp.h>
#include <unistd.h>

int serverSocket;
int dialogSocket;

#define SERVER_PORT 2222
#define MAX_PENDING 5
struct sockaddr_in serverAddress;
struct sockaddr_in clientAddress;

int clientAddressLength;

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


int main() {

    printf("Server is starting...\n");
    // Create a socket
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    // Bind the socket to an address
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(SERVER_PORT);
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(serverSocket,(struct sockaddr *) &serverAddress, sizeof (serverAddress) ) <0) {
        perror ("servecho: erreur bind\n");
        exit (1);
    }

    // Listen for connections
    if (listen(serverSocket, MAX_PENDING) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Server is listening on port %d\n", SERVER_PORT);

    // Accept a connection
    dialogSocket = accept(serverSocket, (struct sockaddr *) &clientAddress,(socklen_t *) &clientAddressLength);

    // Send and receive data
    if (dialogSocket < 0) {
        perror("accept");
        exit(1);
    } else {
        send(dialogSocket, "Hello, World!\n", 14, 0);

        if(fork()) {
            sendMessage(&dialogSocket);
        } else {
            receiveMessage(&dialogSocket);
        }

    }




}
