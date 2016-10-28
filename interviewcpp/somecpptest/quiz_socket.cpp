/*
 * quiz_socket.cpp
 *
 *  Created on: Oct 27, 2016
 *      Author: songjiguo
 */

//what is socket in Linux?

// Ans: From the interface perspective, socket in Linux is the API between the user process and the network stacks in the kernel.
//      From the user perspective, the socket in Linux can be the communication end-point between processes.
//      From the network perspective, the socket in Linux is the interface to the lower layers of the network (i.e., TCP/UDP and IP) and high level internet protocal can be built on top of it.

//what is TCP socket?

// Ans: When the socket is used in the TCP communication, it is a TCP socket.
//      Particularly a TCP connection can be defined as the tuple that consists of IP address and the port number (two end-point sockets, client and server).


//How does it work?

/*
 Ans:  From the protocol/connection state or interface function perspective, here are the steps:
      1) initialize a socket -- "int sockfd = socket(...)"
      2) bind a socket to a port -- "int bind(int sockfd,...)"
      3) ready to receive the connection -- "int listen(int sockfd,...) "
      4) accept a connection -- "int accept(int sockfd,..."
      5) request the connection to the server -- "int connect(int sockfd,...)"
      6) send/receive data -- "read(int sockfd,...), wirte(int sockfd,...)"
      7) close a socket  -- "int close(int sockfd)"
      Note: client does not need do step 2~4


      From the operating system perspective, here are the steps:
      1) When the network packet arrives (over physical layer and data link layer), an interrupt will occur and the kernel could be notified.
      2) the packet is saved in the buffer, which is usually indicated by the socket buffer (sk_buff)
      3) the buffer will pass up through the network layers (IP -> TCP -> HTTP -> application). During the process, the header in the packet is only processed by
         its corresponding layer.
      4) When the application is done processing, the new packet can be generated on its way back to the remove client.
*/


// please create a TCP server listening at myhost="123.121.10.10" and port=2020
// please also create a TCP client sending "Nice to meet you" to the server above
// Note: the server can proceed to do the accept, read/write etc. But the question only asks for the listening. So I stop there
// Note: to send the message, the client needs to call send_request("Nice to meet you")


/* server side code (create a TCP server listening at myhost="123.121.10.10" and port=2020)*/
using namespace std;

#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

class Server {
public:
    Server(int port_num);
    ~Server();

    void run();

private:
    void create();
    void close_socket();

    int port;
    int server;
    int bufflen;
    char* buff;
};

Server::Server(int port_num) {
    port = 2020;   // this should be initialized to be the port_num. Now I hard code to 2020
    bufflen = 1024;
    server = 0;
    buff = new char[bufflen+1];
}

Server::~Server() {
    delete buff;
}

void Server::run() {
    // create the server and put it into listening state
    create();
}

void Server::create() {
    struct sockaddr_in server_addr;

    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("123.121.10.10");  // hard code to an IP for now

    // create socket
    server = socket(PF_INET, SOCK_STREAM, 0);
    if (!server) {
        perror("socket fails");
        exit(-1);
    }

    // bind to associate the socket with the local address and port
    if (bind(server,(const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind fails");
        exit(-1);
    }

    // convert the socket to listen for incoming connections
    if (listen(server,SOMAXCONN) < 0) {
        perror("listen");
        exit(-1);
    }
}

void Server::close_socket() {
    close(server_);
}





/* client side code (sending "Nice to meet you" to the above server)*/

#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Client {
public:
    Client(string host, int port);
    ~Client();

    void run();

private:
    virtual void create();
    virtual void close_socket();
    void echo();
    bool send_request(string);
    bool get_response();

    string host;
    int port;
    int server;
    int buflen;
    char* buff;
};


Client::Client(string host_addr, int port_number) {
    host = host_addr;  // this can be set to 123.121.10.10
    port = 2020;   // hard code this one for now
    server = 0;
    buflen = 1024;
    buff = new char[buflen+1];
}

Client::~Client() {}

void Client::run() {
    create();
    echo();
}

void Client::create() {
    struct sockaddr_in server_addr;

    // setup socket address structure
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr((const char*)host);

    // create socket
    server = socket(PF_INET, SOCK_STREAM, 0);
    if (!server) {
        perror("socket");
        exit(-1);
    }

    // connect to server
    if (connect(server,(const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(-1);
    }
}

void
Client::close_socket() {
    close(server_);
}

bool Client::send_request(string request) {
    const char* ptr = request.c_str();
    int nleft = request.length();
    int nwritten;
    // loop to be sure it is all sent
    while (nleft) {
        if ((nwritten = send(server, ptr, nleft, 0)) < 0) {
            if (errno == EINTR) continue;
            else {
                perror("write");
                return false;
            }
        } else if (nwritten == 0) {
            return false;
        }
        nleft -= nwritten;
        ptr += nwritten;
    }
    return true;
}




//what is UDP socket?

// Ans: this is analogous to TCP socket, except the transport layer (Layer 4) now is using UDP protocol.

//How does it work?

// Ans: similar to TCP, except that UDP server does not need to call "accept" and the udp client does not need to call "connect" to server.
//      After bind, the server will directly receive data and the client can directly send the data. No connection establishment is required.


//
//please create a Multicast server at myhost="221.121.10.10" and port=24000
// please also create a receiver listening to the multicast server above
// show the Multicast server casts a message "Welcome to my group"
// Show how the receiver read the message

// Note: Multicasting can only be built on top of UDP, not TCP













//
//what is the main difference between TCP and UDP sockets?

// TCP is stream based protocol and it is connection-oriented (3-way handshaking). The packets arrive in order and TCP supports reliability and congestion control.
// UDP is datagram based protocol anbd it is connectoin-less. The packets arrive out of order.

//
//what is kernel bypass?
//show one example of kernel bypass in socket operation.


