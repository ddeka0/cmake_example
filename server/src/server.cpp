#include "include/network.h"
using namespace std;
#define PORT 8080

int main(int argc, char const *argv[]) {
	if(argc != 2) {
		cout << "usage : ./build/bin/server <server ip>" << endl;
		return 0;
	}

	int server_fd, new_socket; 
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[1024] = {0};


	if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
		perror("socket failed");
		exit(EXIT_FAILURE);
	}


	if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, 
		sizeof(opt))) {
		perror("setsockopt"); 
		exit(EXIT_FAILURE); 
	}
	
	address.sin_family = AF_INET; 
	address.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	address.sin_port = htons(PORT); 



	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0 ) {
		perror("bind failed");
		exit(EXIT_FAILURE);
	}

	if (listen(server_fd, 3) < 0) {
		perror("listen"); 
		exit(EXIT_FAILURE); 
	}
	

	if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
		(socklen_t*)&addrlen)) < 0) {
		perror("accept");
		exit(EXIT_FAILURE);
	}

	printf("accepted ...\n");
	string hello = "Hello from server";
	while(1) {

		memset(buffer,0,sizeof(buffer));

		// user protocol is not fully defined yet
		// thereore using read() directly
		
		read(new_socket,buffer,1024);  
		
		printf("%s\n",buffer); 
		
		write_stream(new_socket,(uint8_t*)(hello.c_str()), hello.length());
		
		printf("%s :: message sent\n",hello.c_str());

	}
	return 0; 
} 

