/*
 * socketClient
 * @author: Blaed Johnston, Oct 2013
*/

#include <sstream>

#include "libcppSocket/libcppsocket/ClientSocket.h"
#include "libcs5651/CS5651Lib/handleNetworkArgs.h"

using namespace libcppsocket;
using namespace std;
using namespace sivelab;

int main( int argc, char *argv[] ) {
  NetworkArgs args;
  args.process( argc, argv );
  if(!args.hasHostIP){
    cout << "A hostIP address is required\n";
    exit(0);
  }
  string hostIP = args.hostIP;
  int port = args.port;
  ClientSocket socket(hostIP, port);
  // TODO: make some way for this to be changed.
  string client_request = "this is a test";
  socket.send_request(client_request);
  string return_message = socket.get_response();

  cout << return_message;

  return 0;
}
