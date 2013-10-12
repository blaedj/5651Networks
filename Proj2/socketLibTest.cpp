/*
 * socketLibTest.cpp
 * @author: Blaed Johnston, Oct 2013
*/

#include <sstream>

#include "handleNetworkArgs.h"
#include "ServerSocket.h"

using namespace libcppsocket;
using namespace std;

int main( int argc, char *argv[] ) {

  int port = 45002;
  ServerSocket server(port);
  server.open_for_clients();
  while(true){
    int client_fd = server.accept_connection();
    string data_recieved = recieve(client_fd);

    stringstream response_msg("");
    response_msg << data_recieved << " and one!";
    respond(response_msg.str(), client_fd);
  }

  return 0;
}
