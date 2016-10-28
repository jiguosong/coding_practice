/*
 * client.cpp
 *
 *  Created on: Oct 27, 2016
 *      Author: songjiguo
 */

using namespace std;

#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class client {
private:
	int returned_server_sockfd;

	int port;
	char *buffer;
	int buffer_len;
	string remote_server_ip;

	virtual void close_socket();
	virtual void create_conn();
	bool send_request(string request);
	bool receive_response();
	void echo();
public:
	client(string remote_server_ip, int port_num);
	~client();

	void start_client();
};

client::~client() {
	delete buffer;
}

client::client(string server_ip, int port_num) {
	returned_server_sockfd = 0;
	remote_server_ip = server_ip;
	port = port_num;
	buffer_len = 1024;
	buffer = new char[buffer_len+1];
}

void client::close_socket(){
	close(returned_server_sockfd);
}

void client::create_conn() {
	struct sockaddr_in server_sockaddr;
	socklen_t server_socklen = sizeof(server_sockaddr);

	memset(&server_sockaddr, 0 , sizeof(server_sockaddr));
	server_sockaddr.sin_family = AF_INET;
	server_sockaddr.sin_port = htons(port);
	server_sockaddr.sin_addr.s_addr = inet_addr(remote_server_ip.c_str());

	// create a client socket
	returned_server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(!returned_server_sockfd) {
		perror("socket fails");
		exit(-1);
	}

	// connect to the remove server
	if(connect(returned_server_sockfd,
			(const struct sockaddr *)&server_sockaddr, sizeof(server_sockaddr)) < 0) {
		perror("connect fails");
		exit(-1);
	}
}

void client::start_client() {
	create_conn();
	// start communicating with the server
	string out_msg;
	while(getline(cin, out_msg)) {
		out_msg += "\n";
		bool issend = send_request(out_msg);
		if(!issend) break;

		bool isreceive = receive_response();
		if(!isreceive) break;
	}

	close_socket();

}

bool client::send_request(string response)
{
	const char *out_ptr = response.c_str();
	int sz_left = response.length();
	int sz_sent = 0;

	while(sz_left) {
		sz_sent = send(returned_server_sockfd, out_ptr, sz_left, 0);
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

bool client::receive_response() {
	string res = "";

	while(res.find("\n") == string::npos) {
		int size = recv(returned_server_sockfd, buffer, buffer_len, 0);
		if(size < 0) {
			if(errno == EINTR) continue;
			else return "";
		} else if(size == 0) {
			return "";
		}
		res.append(buffer, size);
	}
	cout << res;
	return true;
}

int main(int argc, char **aragv) {
	string server_ip = "127.0.0.1";
	client test(server_ip, 5600);
	test.start_client();
}
