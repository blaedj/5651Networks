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
#include <sstream>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <errno.h>

using namespace std;
using namespace libcppsocket;

void check_socket_fd(int sock_fileDesc);
void bind_socket(int port);
void check_return_code(int code);
/* creates and binds a socket to the specified port*/
ServerSocket::ServerSocket(int port) {
  _port = port;
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  check_socket_fd(socket_fd);
}

/* waits for a client to connect to the server*/
int ServerSocket::open_for_clients() {
  //  int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
  bind_socket( _port );
  // 42 is the que size for pending connections to the socket
  listen( socket_fd, 42 );
  return 0;
}

// bind the socket to the given port.
void ServerSocket::bind_socket(int port) {
  // setup the sockaddr for the bind call
  if(port < 1024 || port > 65535){
    stringstream ss;
    ss << "Non-usable port number specified: " << port<< "\n";
    throw SocketException(ss.str());
  }
  struct sockaddr_in serv_address;
  memset(&serv_address, 0, sizeof(serv_address));
  serv_address.sin_family = AF_INET;
  serv_address.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_address.sin_port = htons(port);

  if( bind(socket_fd,(const struct sockaddr *)&serv_address, sizeof(serv_address)) < 0) {
    stringstream ss;
    ss << "Unable to bind socket to port: " << port<< "\n";
    throw SocketException(ss.str());
  }
}

// waits for a client to connect, *Blocks!*
int ServerSocket::accept_connection() {
  int client_socket_fd;
  struct sockaddr_in client_addr;
  socklen_t length = sizeof(client_addr);
  client_socket_fd = accept(socket_fd, (sockaddr*)&client_addr, &length);
  check_socket_fd(client_socket_fd);

  return client_socket_fd;
}

// Send the specified message to the given client
void ServerSocket::respond(string response_message, int client_fd){
  char CR = '\r';
  char LF = '\n';
  int msgSize = response_message.length();

  ostringstream output_stream("");
  output_stream << response_message << CR << LF;
  send(client_fd, output_stream.str().c_str(), msgSize, 0);

  int client_close = close(client_fd);
  if(client_close != 0){
    int errCode = errno;
    check_return_code(errCode);
  }

  int serv_close = close(socket_fd);
  if(serv_close != 0){
    int errCode = errno;
    check_return_code(errCode);
  }
}

// error checking function
void check_socket_fd(int sock_fileDesc) {
  if(sock_fileDesc < 0) {
    throw SocketException("A generic error occured in ServerSocket.cpp");
  }
}

void check_return_code(int code){
  if(code != 0){
    stringstream ss;
    ss << "An error occured when closing a socket. Error # is: "
       << code << "\n";
    throw SocketException(ss.str());
  }
}
