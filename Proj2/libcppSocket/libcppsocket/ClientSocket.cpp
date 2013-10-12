/*
 *
 * author: Blaed Johnston October 2013
 * ClientSocket.cpp
 */

#include <arpa/inet.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sstream>

#include "ClientSocket.h"
#include "AddressNameMapper.h"
#include "SocketException.h"

using namespace libcppsocket;

void check_sent_size(int sent);

ClientSocket::ClientSocket(string ip_address, int port_num){
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);

  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(port_num);

  inet_pton(AF_INET, ip_address.c_str(), &server.sin_addr);

  connect(socket_fd, (const sockaddr *)&server, sizeof(server));
}

void ClientSocket::send_request(string message){
  int size_to_send = message.length();
  int sent_bytes = 0;
  sent_bytes = send(socket_fd, message.c_str(), size_to_send, 0);
  check_sent_size(sent_bytes);
}

void check_sent_size(int sent){
  if(sent == -1){
    stringstream err_msg;
    err_msg << "an error occured sending the message to the server\n";
    throw SocketException(err_msg.str());
  }
}
