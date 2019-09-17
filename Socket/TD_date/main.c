/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: abourrelly
 *
 * Created on 10 septembre 2019, 11:37
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>

/*
 * 
 */

int main(int argc, char** argv) {
    typedef struct{
	unsigned char jour;
	unsigned char mois;
	unsigned short int annee;
	char jourDeLaSemaine[10];	// le jour en toute lettre
}datePerso;
    
    int clientSocket;
    struct sockaddr_in informationsServeur;
    datePerso date;
    strcpy(date.jourDeLaSemaine,"Toto");
    date.mois = 13;
    date.jour = 13;
    date.annee = 1995;
     
    int retourSendto;

    clientSocket = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (clientSocket == -1) {
        printf("pb socket : %s\n", strerror(errno));
        exit errno;
    }
    // init de informationsServeur
    // IP, port, type
    informationsServeur.sin_family = AF_INET;
    informationsServeur.sin_port = htons(4444);
    informationsServeur.sin_addr.s_addr = inet_addr("172.18.58.147");

    memset(&informationsServeur.sin_zero, 0, sizeof (informationsServeur.sin_zero));


    retourSendto = sendto(clientSocket, &date, sizeof(date), 0, &informationsServeur,sizeof(informationsServeur));
    if (retourSendto) {

    }
    

    return (EXIT_SUCCESS);
}

