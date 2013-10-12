/*
 * Socket.h
 *
 * author: Blaed Johnston
 *
 * generic socket structure.
*/

#ifndef __LIBCPPSOCKET__SOCKET_H__
#define __LIBCPPSOCKET__SOCKET_H__ 1

#include <cstdlib>
#include <iostream>

using namespace std;

namespace libcppsocket {
  class Socket {
  public:
    Socket();
    string recieve(int recv_socket);
  protected:
    int socket_fd;
  private:

  };

};

#endif
