#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <unistd.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    char buffer[BUFFER_SIZE];
    struct timeval tv;
    struct tm *tm;
    char time_str[BUFFER_SIZE];

    // création de la socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    // configuration de l'adresse de la socket
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // liaison de la socket à l'adresse
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    printf("Serveur UDP en attente de requêtes sur le port %d...\n", PORT);

    clilen = sizeof(cli_addr);

    // réception du datagramme
    if (recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *) &cli_addr, &clilen) < 0) {
        perror("recvfrom");
        exit(1);
    }

    printf("Heure reçue du client : %s\n", buffer);


    // fermeture de la socket
    close(sockfd);
    exit(0);

}
