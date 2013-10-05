/*
 * socketLibTest.cpp
 * @author: Blaed Johnston, Oct 2013
*/

#include "ServerSocket.h"

using namespace libcppsocket;
using namespace std;

int main( int argc, char *argv[] ) {

  int port = 45002;
  ServerSocket server(port);
  server.open_for_clients();
  server.accept_connection();

  return 0;
}
