/*
 * Socket.h
 *
 * author: Blaed Johnston
 *
 * generic socket structure.
*/

#ifndef __LIBCPPSOCKET__SOCKET_H__
#define __LIBCPPSOCKET__SOCKET_H__ 1

namespace libcppsocket {

  class Socket {
  public:
    Socket();
    virtual ~Socket();
    Socket(int port);
  private:

  };

};

#endif
