/*
 * author: Blaed Johnston 10/13.
 *
 *  generic socket. can be extended to tcp, udp etc.
 */

#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>

#include "Socket.h"
#include "SocketException.h"

using namespace std;
using namespace libcppsocket;

/*
 * Creates an IPv4, TCP socket.
 */
Socket::Socket( ){
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if ( socket_fd < 0 ) {
    throw SocketException("Unable to create socket");
  }
}
