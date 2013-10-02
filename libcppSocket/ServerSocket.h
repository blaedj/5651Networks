/*
 * @author: Blaed Johnston Oct 2013
 * TCPSocket.h
 *
 */

#ifndef __LIBCPPSOCKET__SERVERSOCKET_H
#define  __LIBCPPSOCKET__SERVERSOCKET_H 1

#include "Socket.h"

namespace libcppsocket {

  class ServerSocket : public Socket {
  public:
    ServerSocket(int port);
    int accept_clients();
  protected:
    void bind_socket(int port);
  };

}

#endif
