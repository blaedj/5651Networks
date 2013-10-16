/*
 * socketClient
 * @author: Blaed Johnston, Oct 2013
 */

#include <iostream>
#include <sstream>
#include <fstream>

#include "libcppSocket/libcppsocket/ClientSocket.h"
#include "libcs5651/CS5651Lib/handleNetworkArgs.h"

using namespace libcppsocket;
using namespace std;
using namespace sivelab;

int main( int argc, char *argv[] ) {
  NetworkArgs args;
  args.process( argc, argv );
  if(!args.hasHostIP) {
    cout << "A hostIP address is required\n";
    exit(0);
  }
  string hostIP = args.hostIP;
  int port = args.port;
  ClientSocket socket(hostIP, port);

  MessageBuffer request;
  char req_msg[] = "test.txt";
  request.add(&req_msg[0], sizeof(req_msg));

  socket.send_request(request);

  MessageBuffer response;
  response = socket.get_response();
  int write_size = response.size();

  ofstream data_writer("testRecvd.txt", ios::binary | ios::out);
  data_writer.write(response.get_data(), write_size);
  data_writer.close();

  socket.close_socket();

  return 0;
}
