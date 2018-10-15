#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT 1122

void main(){

	char input[100];	
	int clientSocket = socket(PF_INET, SOCK_STREAM, 0);
	struct sockaddr_in serverIn;	
	
	memset(&serverIn, '0', sizeof(serverIn));	
	serverIn.sin_family = AF_INET;
	serverIn.sin_port = htons(PORT);
	serverIn.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	
	connect(clientSocket, (struct sockaddr*)&serverIn, sizeof(serverIn));
	recv(clientSocket, input, 100, 0);
	printf("Data Recieved: %s", input);	

}
