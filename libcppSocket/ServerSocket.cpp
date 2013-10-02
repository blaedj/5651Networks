/*
 * @author Blaed Johnston Oct 2013
 * ServerSocket.cpp
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "ServerSocket.h"
#include "SocketException.h"
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace libcppsocket;

void check_socket_fd(int sock_fileDesc);
void bind_socket(int port);

/* creates and binds a socket to the specified port*/
ServerSocket::ServerSocket(int port){
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  check_socket_fd(socket_fd);
  bind_socket(port);

}
/* waits for a client to connect to the server*/
int ServerSocket::accept_clients(){
  //  int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
  return 0;
}

void check_socket_fd(int sock_fileDesc){
  if(sock_fileDesc < 0) {
    throw SocketException("A generic error occured in ServerSocket.cpp");
  }
}

void ServerSocket::bind_socket(int port){

  // setup the sockaddr for the bind call
  struct sockaddr_in serv_address;
  memset(&serv_address, 0, sizeof(serv_address));
  serv_address.sin_family = AF_INET;
  serv_address.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_address.sin_port = htons(port);

  if( bind(socket_fd,(const struct sockaddr *)&serv_address, sizeof(serv_address)) < 0) {
    throw SocketException("Unable to bind socket to port");
  }


  //int bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);

}
