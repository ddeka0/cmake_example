// Client side C/C++ program to demonstrate Socket programming 
#include "include/network.h"
using namespace std;
#define PORT 8080
#define LOCALHOST	"127.0.0.1"

int main(int argc, char const *argv[]) {

	struct sockaddr_in address;
	int sock = 0, valread;
	struct sockaddr_in serv_addr;
	char buffer[1024] = {0};
	
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) { 
		printf("\n Socket creation error \n"); 
		return -1; 
	} 

	bzero ((void *) &serv_addr, sizeof (serv_addr)); 


	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(PORT); 
	address.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	
	if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) { 
		printf("\nConnection Failed \n"); 
		return -1; 
	}

	printf("connected ...\n");

	int cnt = 0;
	string hello = " Hello from client";
	string msg = to_string(cnt) + hello;
	while(1) {
		

		write_stream(sock,(uint8_t*)(msg.c_str()), msg.length());
		printf("%s :: message sent\n",msg.c_str()); 
		valread = read(sock,buffer,1024); 
		printf("%s\n",buffer);	
		memset(buffer,0,sizeof(buffer));
		
		sleep(2);
		cnt++;
		string prefix = to_string(cnt);
		msg = prefix + hello;
	}

	return 0; 
} 

