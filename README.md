# Répertoire de clients et serveurs TCP/UDP

Ce répertoire contient deux implémentations de clients et serveurs en C, l'une utilisant le protocole TCP et l'autre le protocole UDP.

## Prérequis
- Compilateur C

## Serveur TCP
Le serveur TCP écoute sur un port spécifié et attend des connexions de clients. Une fois qu'un client se connecte, le serveur envoie un message de bienvenue et lit les messages envoyés par le client.

### Compilation
Pour compiler le serveur TCP, utilisez la commande suivante dans un terminal Linux :
```bash
gcc -o serveurTCP serveurTCP.c
```
### Exécution
Pour exécuter le serveur TCP, utilisez la commande suivante :
```bash
./serveurTCP
```
Le serveur commence à écouter sur le port spécifié en attente de connexions clients.

## Client TCP
Le client TCP se connecte à un serveur en utilisant l'adresse IP et le numéro de port spécifiés. Une fois connecté, le client affiche le message de bienvenue du serveur et lit les lignes de l'entrée standard pour les envoyer au serveur.

### Compilation
Pour compiler le client TCP, utilisez la commande suivante dans un terminal Linux :
```bash
gcc -o clientTCP clientTCP.c
```
### Exécution
Pour exécuter le client TCP, utilisez la commande suivante :
```bash
./clientTCP <adresse IP du serveur> <port>
```
Remplacez `<adresse IP du serveur>` par l'adresse IP du serveur et `<port>` par le numéro de port sur lequel le serveur écoute.

## Serveur UDP
Le serveur UDP écoute sur un port spécifié et attend des datagrammes de clients. Une fois qu'un datagramme est reçu, le serveur affiche le message et envoie une réponse.

### Compilation
Pour compiler le serveur UDP, utilisez la commande suivante dans un terminal Linux :
```bash
gcc -o serveurUDP serveurUDP.c
```
### Exécution
Pour exécuter le serveur UDP, utilisez la commande suivante :
```bash
./serveurUDP
```
Le serveur commence à écouter sur le port spécifié en attente de datagrammes clients.

## Client UDP
Le client UDP envoie un datagramme à un serveur en utilisant l'adresse IP et le numéro de port spécifiés. Une fois que le datagramme est envoyé, le client écoute une réponse du serveur.

### Compilation
Pour compiler le client UDP, utilisez la commande suivante dans un terminal Linux :
```bash
gcc -o clientUDP clientUDP.c
```
### Exécution
Pour exécuter le client UDP, utilisez la commande suivante :
```bash
./clientUDP <adresse IP du serveur> <port>
```
Remplacez `<adresse IP du serveur>` par l'adresse IP du serveur et `<port>` par le numéro de port sur lequel le serveur écoute.

## Fonctionnalités
- Les clients et serveurs TCP utilisent les fonctions `socket()`, `bind()`, `listen()`, `accept()`, `send()` et `recv()`.
- Les clients et serveurs UDP utilisent les fonctions `socket()`, `bind()`, `sendto()` et `recvfrom()`.
- Les clients et serveurs TCP utilisent les fonctions `htons()` et `htonl()` pour convertir les numéros de port et les adresses IP en format réseau.
- Les clients et serveurs UDP utilisent les fonctions `htons()` et `htonl()` pour convertir les numéros de port et les adresses IP en format réseau.
- Les clients et serveurs TCP utilisent la fonction `inet_addr()` pour convertir les adresses IP en format binaire.
- Les clients et serveurs UDP utilisent la fonction `inet_addr()` pour convertir les adresses IP en format binaire.
- Les clients et serveurs TCP utilisent la fonction `strlen()` pour déterminer la longueur des messages.
- Les clients et serveurs UDP utilisent la fonction `strlen()` pour déterminer la longueur des messages.
- Les clients et serveurs TCP utilisent la fonction `perror()` pour afficher des messages d'erreur.
- Les clients et serveurs UDP utilisent la fonction `perror()` pour afficher des messages d'erreur.
- Les clients et serveurs TCP utilisent la fonction `exit()` pour terminer le programme en cas d'erreur.
- Les clients et serveurs UDP utilisent la fonction `exit()` pour terminer le programme en cas d'erreur.
