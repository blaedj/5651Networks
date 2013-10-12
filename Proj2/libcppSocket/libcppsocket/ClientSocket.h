/*
 * @author: Blaed Johnston Oct 2013
 * ClientSocket.h
 *
 */

#ifndef __LIBCPPSOCKET__CLIENTSOCKET_H
#define  __LIBCPPSOCKET__CLIENTSOCKET_H 1

#include "Socket.h"

namespace libcppsocket {

  class ClientSocket : public Socket {
  public:
    ClientSocket(string hostname, int port_num);
    void sendRequest(string message);

  private:
    int host_ip;
    int port;

  };

}

#endif
