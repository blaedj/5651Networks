/*
 * Socket.h
 *
 * author: Blaed Johnston
 *
 * abstract class, generic socket structure.
*/

#ifndef __LIBCPPSOCKET__SOCKET_H__
#define __LIBCPPSOCKET__SOCKET_H__ 1

namespace libcppsocket {


  class Socket {
  public:
    virtual ~Socket();
  private:
    Socket();
  }


}

#endif
