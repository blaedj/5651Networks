/*
 * socketServer.cpp
 * @author: Blaed Johnston, Oct 2013
 */

#include <sstream>

#include "libcs5651/CS5651Lib/handleNetworkArgs.h"
#include "libcppSocket/libcppsocket/ServerSocket.h"
#include "libcppSocket/libcppsocket/SocketException.h"

using namespace libcppsocket;
using namespace std;

int main( int argc, char *argv[] ) {

  int port = 45002;
  ServerSocket server(port);
  server.open_for_clients();
  while(true){
    try{
      int client_fd = server.accept_connection();
      string data_recieved = server.recieve(client_fd);
      cout << data_recieved<<"\n";
      stringstream response_msg("");
      response_msg << data_recieved << " and one!";
      server.respond(response_msg.str(), client_fd);
    } catch( SocketException e) {
      string str(e.what());
      cout << str << "\n";
      exit(1);
    }
  }

  return 0;
}
