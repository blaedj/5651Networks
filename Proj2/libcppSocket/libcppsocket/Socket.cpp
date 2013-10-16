/*
 * author: Blaed Johnston 10/13.
 *
 *  generic socket. can be extended to tcp, udp etc.
 */

#define DEBUG 1

#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <vector>
#include <cstring>

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


MessageBuffer Socket::recieve( int recv_socket ) {

  MessageBuffer message;

  int total_received_bytes = 0;
  int MSGSZ = 500;
  char buffer[MSGSZ];
  fd_set rfds;
  FD_ZERO(&rfds);
  FD_SET (recv_socket, &rfds);
  // timer to wait is set to zero to not wait,
  // but instead check the fd immediately
  struct timeval tv;
  tv.tv_sec = 0;
  tv.tv_usec = 0;
  int select_val = 0;
  int bytes_recvd = 0;

  do {
    memset((void *)&buffer, 0, MSGSZ);
    bytes_recvd = ::recv(recv_socket, buffer, MSGSZ, 0 );
    if(bytes_recvd == -1){
      throw SocketException("there was an error recieving data.");
    }
    total_received_bytes += bytes_recvd;

    message.add(buffer, sizeof(buffer));

    select_val = select(socket_fd+1, &rfds, NULL, NULL, &tv);
  } while (bytes_recvd == MSGSZ && select_val);
  return message;
}
