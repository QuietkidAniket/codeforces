#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<string.h>

#define SERVER "0.0.0.0"
#define BUFF 2048
#define PORT 8080
#define TERMINATE "END"
#define printTable(s1,s2) printf("%-15s -|- %-15s\n",s1,s2)

int sockfd = 0 , n = 0;
char buffer[BUFF] = "";
char manipulate[2*BUFF] = "";
void die(char*s){
	printf("%s\n",s);
	exit(EXIT_FAILURE);
}

int main(int argc , char * argv[]){

	sockfd = socket(AF_INET , SOCK_DGRAM , 0);
	
	struct sockaddr_in serv_addr , client_addr;
	socklen_t size_serv = sizeof(serv_addr) , size_client = sizeof(client_addr);
	memset(&serv_addr , 0 , size_serv);
	memset(&client_addr , 0 ,size_client);


	serv_addr.sin_family  = AF_INET;
	serv_addr.sin_port = htons(PORT);
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(sockfd , (struct sockaddr *) &serv_addr , size_serv );

	while(1){
	
	recvfrom(sockfd , buffer , BUFF ,0 , (struct sockaddr *)&client_addr , &size_client);
	
	sprintf(manipulate, "%-500s -|- %s",buffer , inet_ntoa(client_addr.sin_addr));
	
	sendto(sockfd , manipulate, BUFF , 0 , (struct sockaddr *)&client_addr , size_client);

	
	}


close(sockfd);
return 0;
}
