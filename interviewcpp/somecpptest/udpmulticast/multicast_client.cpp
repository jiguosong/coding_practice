/*
 * multicast_client.cpp
 *
 *  Created on: Oct 28, 2016
 *      Author: songjiguo
 */

#include <iostream>
#include <string>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class multicast_client {
private:
	int multicast_client_sockfd;
	struct sockaddr_in multicast_sockaddr;
	char *multicast_ip;
	int multicast_port;
	int multicast_TTL;
	char *multicast_client_buffer;
	int multicast_client_buff_len;

	void create_socket();
	void close_socket();
	void process_msg();
public:
	multicast_client(char *ip, int port);
	~multicast_client();

	void start_multicast_client();
};

multicast_client::multicast_client(char *ip, int port) {
	multicast_ip = ip;
	multicast_port = port;
	multicast_client_buff_len = 1024;
	multicast_client_buffer = new char[multicast_client_buff_len+1];
	multicast_TTL = 1;
	multicast_client_sockfd = 0;
	memset(&multicast_sockaddr, 0, sizeof(multicast_sockaddr));
}

multicast_client::~multicast_client(){
	delete multicast_client_buffer;
}

void multicast_client::close_socket(){
	close(multicast_client_sockfd);
}

void multicast_client::create_socket(){

	multicast_sockaddr.sin_family = AF_INET;
	multicast_sockaddr.sin_port = htons(multicast_port);
	multicast_sockaddr.sin_addr.s_addr = inet_addr(multicast_ip);

	multicast_client_sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if(multicast_client_sockfd < 0) {
		perror("socket fails");
		exit(-1);
	}

	if(setsockopt(multicast_client_sockfd, IPPROTO_IP, IP_MULTICAST_TTL,
				  (void*)&multicast_TTL, sizeof(multicast_TTL)) < 0) {
		perror("set TTL fails");
		exit(-1);
	}
}

void multicast_client::process_msg(){
	string out_msg;
	while(getline(cin, out_msg)){
		out_msg += "\n";
		const char *out_ptr = out_msg.c_str();
		int out_sz = out_msg.length();

		if(sendto(multicast_client_sockfd, (void *)out_ptr, out_sz, 0,
				(struct sockaddr *)&multicast_sockaddr, sizeof(multicast_sockaddr)) != out_sz) {
			perror("sent different size");
			exit(-1);
		}
	}
}

void multicast_client::start_multicast_client(){
	create_socket();
	process_msg();
	close_socket();
}

int main(int argc, char **argv) {
	char *ip = "127.0.0.1";
	multicast_client test(ip, 5050);
	test.start_multicast_client();
}


