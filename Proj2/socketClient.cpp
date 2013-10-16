/*
 * socketClient
 * @author: Blaed Johnston, Oct 2013
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#include "libcppSocket/libcppsocket/ClientSocket.h"
#include "libcs5651/CS5651Lib/handleNetworkArgs.h"

using namespace libcppsocket;
using namespace std;
using namespace sivelab;

vector<string> getFiles();

int main( int argc, char *argv[] ) {
  // TODO: extract region setup
  NetworkArgs args;
  args.process( argc, argv );
  if(!args.hasHostIP) {
    cout << "A hostIP address is required\n";
    exit(0);
  }
  string hostIP = args.hostIP;
  int port = args.port;
  ClientSocket socket(hostIP, port);
  // end setup

  vector<string> request_files = getFiles();
  MessageBuffer request;
  MessageBuffer response;
  for(size_t i =0; i < request_files.size(); i++) {
    string req_msg = request_files[i];
    request.add((char*)req_msg.c_str(), sizeof(req_msg));
    socket.send_request(request);

    string file_name = "received/r_" + request_files[i];
    response = socket.get_response();

    int write_size = response.size();
    ofstream data_writer(file_name.c_str(), ios::binary | ios::out);
    data_writer.write(response.get_data(), write_size);
    data_writer.close();
  }
  socket.close_socket();
  return 0;
}

vector<string> getFiles(){
  vector<string> files;
  string aFile;
  while(aFile != "q") {
    cout << "enter a file name to request, 'q' when finished.\n";
    cin >> aFile;
    if(aFile != "q"){files.push_back(aFile);}
  }
  return files;
}
