/*
 * @author: Blaed Johnston Oct 2013
 * ClientSocket.h
 *
 */

#ifndef __LIBCPPSOCKET__CLIENTSOCKET_H
#define  __LIBCPPSOCKET__CLIENTSOCKET_H 1

#include "Socket.h"

#include <sys/types.h>
#include <netinet/in.h>

namespace libcppsocket {

  class ClientSocket : public Socket {
  public:
    ClientSocket(string ip_address, int port_num);
    void send_request(string message);
    string get_response();
  private:
    int host_ip;
    int port;
    sockaddr_in server;
  };

}

#endif
