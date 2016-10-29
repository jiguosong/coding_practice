/*
 * multicast_server.cpp
 *
 *  Created on: Oct 28, 2016
 *      Author: songjiguo
 */

#include <iostream>
#include <string>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define SERVER_GROUP "225.0.0.37"

class multicast_server {
private:
	int multicast_server_sockfd;
	char *multicast_server_ip;
	int multicast_server_port;
	char *multicast_server_buffer;
	int multicast_server_buff_len;

	void create_socket();
	void close_socket();
	void process_msg();
public:
	multicast_server(char *ip, int port);
	~multicast_server();

	void start_multicast_server();
};

multicast_server::multicast_server(char *ip, int port) {
	multicast_server_ip = ip;
	multicast_server_port = port;
	multicast_server_buff_len = 1024;
	multicast_server_buffer = new char[multicast_server_buff_len+1];
	multicast_server_sockfd = 0;
}

multicast_server::~multicast_server(){
	delete multicast_server_buffer;
}

void multicast_server::close_socket() {
	close(multicast_server_sockfd);
}

void multicast_server::create_socket() {
	struct sockaddr_in server_addr;
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(multicast_server_port);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if((multicast_server_sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
		perror("sock fails");
		exit(-1);
	}

	 u_int yes = 1;
	if (setsockopt(multicast_server_sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) < 0)
	{
		perror("Reusing ADDR failed");
		exit(1);
	}

	if((bind(multicast_server_sockfd, (const struct sockaddr*)&server_addr,
				sizeof(server_addr)))< 0) {
		perror("bind fails");
		exit(-1);
	}

	cout << multicast_server_ip << endl;
	struct ip_mreq multicast_request;
	memset(&multicast_request, 0, sizeof(multicast_request));
	multicast_request.imr_multiaddr.s_addr = inet_addr(SERVER_GROUP);
	multicast_request.imr_interface.s_addr = htonl(INADDR_ANY);

	if(setsockopt(multicast_server_sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP,
				  (void*)&multicast_request, sizeof(multicast_request) < 0)) {
		perror("set multicasting fails");
		exit(-1);
	}


}

void multicast_server::process_msg(){
	while(1) {
		int request_len = recvfrom(multicast_server_sockfd, (void *)multicast_server_buffer,
									multicast_server_buff_len, 0, 0 ,0);
		if(request_len == -1) {
			perror("recv from fails");
			break;
		} else if(request_len == 0) continue;

		multicast_server_buffer[request_len] = '\0';
		cout << multicast_server_buffer << endl;
	}
}

void multicast_server::start_multicast_server() {
	create_socket();
	process_msg();
	close_socket();
}

int main(int argc, char **argv) {
	multicast_server test("192.168.0.1", 5050);
	test.start_multicast_server();
}
