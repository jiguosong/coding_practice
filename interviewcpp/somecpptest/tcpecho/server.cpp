/*
 * server.cpp
 *
 *  Created on: Oct 27, 2016
 *      Author: songjiguo
 */

#include <errno.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>   // for calling close

using namespace std;

class server {
private:
	int server_sockfd;
	int port;
	char *buffer;
	int buff_len;

	void create_conn();
	void close_server();

	void process(int client_sockfd);
	string receive_request(int client_sockfd);
	bool send_response(int client_sockfd, string response);
public:
	server(const int port_num);
	~server();

	void start_server();
};

server::server(const int port_num)
{
	port = port_num;
	server_sockfd = 0;
	buff_len = 1024;
	buffer = new char[buff_len+1];
}

server::~server(){
	delete buffer;
}

/*
 // For IPv4, use the sockaddr_in structure.
 struct in_addr {
	uint32_t s_addr;  // Internet address (32 bits)
  };

 struct sockaddr_in {
	sa_family_t sin_family;
	in_port_t sin_port;
	struct in_addr sin_addr;
	char sin_zero[8];
 };

*/

void server::close_server()
{
	close(server_sockfd);
}


void server::create_conn() {
	struct sockaddr_in server_addr;

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	server_addr.sin_addr.s_addr = INADDR_ANY;;

	// create a socket here (IPv4)
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(!server_sockfd) {
		perror("socket error");
		exit(-1);
	}

	// bind the socket to the address and port
	if(bind(server_sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
		perror("bind error");
		exit(-1);
	}

	// start listening on this socket
	if(listen(server_sockfd, SOMAXCONN) < 0) {
		perror("listen error");
		exit(-1);
	}
}

void server::start_server()
{
	create_conn();

	// for the incoming client connection
	int client_sockfd;
	struct sockaddr_in client_addr;
	socklen_t client_socklen = sizeof(client_addr);

	while ((client_sockfd = accept(server_sockfd,(struct sockaddr *)&client_addr,&client_socklen)) > 0) {
		process(client_sockfd);
	}

	close_server();

}

// process the incoming packets
void server::process(int client_sockfd) {
	while(1) {
		string request = receive_request(client_sockfd);
		if(request.empty()) break;
		bool success = send_response(client_sockfd, request);
		if(!success) break;
	}
}

string server::receive_request(int client_sockfd) {
	string res = "";

	while(res.find("\n") == string::npos) {
		int size = recv(client_sockfd, buffer, buff_len, 0);
		if(size < 0) {
			if(errno == EINTR) continue;
			else return "";
		} else if(size == 0) {
			return "";
		}
		res.append(buffer, size);
	}

	cout << res << endl;
	return res;
}

bool server::send_response(int client_sockfd, string response)
{
	const char *out_ptr = response.c_str();
	int sz_left = response.length();
	int sz_sent = 0;

	while(sz_left) {
		sz_sent = send(client_sockfd, out_ptr, sz_left, 0);
		if(sz_sent < 0) {
			if(errno == EINTR) continue;
			else {
				perror("write fails");
				return false;
			}
		} else if(sz_sent == 0) {
			return false;
		}

		sz_left -= sz_sent;
		out_ptr += sz_sent;
	}

	return true;
}


int main(int argc, char** argv)
{
	server test(5600);
	test.start_server();
}
