/*
 * @author: Blaed Johnston Oct 2013
 * ServerSocket.h
 *
 */

#ifndef __LIBCPPSOCKET__SERVERSOCKET_H
#define  __LIBCPPSOCKET__SERVERSOCKET_H 1

#include "Socket.h"
#include "IMessage.h"

namespace libcppsocket {

  class ServerSocket : public Socket {
  public:
    ServerSocket(int port);

    int open_for_clients();
    int accept_connection();

    void respond(MessageBuffer response_message, int client_fd);
  protected:
    void bind_socket(int port);
    int _port;
  };

}

#endif
