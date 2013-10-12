/*
 *
 * author: Blaed Johnston October 2013
 * ClientSocket.cpp
 */

#include "ClientSocket.h"
#include <arpa/inet.h>
#include <string.h>
#include "AddressNameMapper.h"

using namespace libcppsocket;

ClientSocket::ClientSocket(string ip_address, int port_num){
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);

  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(port_num);

  inet_pton(AF_INET, ip_address.c_str(), &server.sin_addr);

  connect(socket_fd, (const sockaddr *)&server, sizeof(server));
}
