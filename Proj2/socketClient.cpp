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
  string next_message = "initial";
  string hostIP = args.hostIP;
  int port = args.port;

  while(next_message != "q"){
    ClientSocket socket(hostIP, port);
    // TODO: make some way for this to be changed.
    string client_request = next_message;
    socket.send_request(client_request);
    string return_message = socket.get_response();

    cout << "return message is: "<< return_message << "\n";
    cin >> next_message;
  }
  return 0;
}
