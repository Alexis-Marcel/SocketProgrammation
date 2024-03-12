#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <unistd.h>

#define PORT 12345

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in serv_addr;
    time_t t;

    // création de la socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    // configuration de l'adresse du serveur
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_port = htons( (ushort) atoi(argv[2]) );
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // récupération de l'heure actuelle
    time(&t);

    // envoi du datagramme au serveur
    if (sendto(sockfd, ctime(&t), strlen(ctime(&t)), 0, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("sendto");
        exit(1);
    }

    printf("Heure envoyée au serveur : %s", ctime(&t));

    // fermeture
    close(sockfd);

    return 0;
}