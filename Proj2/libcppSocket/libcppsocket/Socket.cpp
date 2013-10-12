/*
 * author: Blaed Johnston 10/13.
 *
 *  generic socket. can be extended to tcp, udp etc.
 */

#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <vector>

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


string Socket::recieve( int recv_socket) {
  char buffer[500];
  int total_received_bytes = 0;
  int MSGSZ = 500;
  fd_set rfds;
  FD_ZERO(&rfds);
  FD_SET (recv_socket, &rfds);
  // timer to wait is set to zero to not wait,
  // but instead check the fd immediately
  struct timeval tv;
  tv.tv_sec = 0;
  tv.tv_usec = 0;

  int select_val = 0;
  vector<char> recvd_data;
  std::vector<char>::iterator total_recvd_cntr;
  do {
    int bytes_recvd = ::recv(recv_socket, buffer, MSGSZ, 0 );
    total_received_bytes += bytes_recvd;
    for(int i = 0; i < (int)sizeof(buffer); i++){
      total_recvd_cntr = recvd_data.insert(total_recvd_cntr, buffer[i]);
    }
    select_val = select(socket_fd+1, &rfds, NULL, NULL, &tv);
  } while (total_received_bytes == MSGSZ && select_val);
  char* data_arr = recvd_data.data();
  //TODO convert the vector<char> to a message somehow
  string str(data_arr);
  return str;
}
