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
void error_check(char * data);

int main( int argc, char *argv[] ) {
  // TODO: extract region setup
  NetworkArgs args;
  args.process( argc, argv );
  if(!args.hasHostIP) {
    cout << "hostIP address and port number are required\n";
    exit(0);
  }
  string hostIP = args.hostIP;
  int port = args.port;
  ClientSocket socket(hostIP, port);
  // end setup

  cout << "Welcome to this simple client!\n Note that any files recieved from "
       << "a server will be placed in the 'received/' directory in the "
       << "current directory.\n If no such directory exists, one will be "
       << "created for you.\n\n";

  vector<string> request_files = getFiles();
  MessageBuffer request;
  MessageBuffer response;
  for(size_t i =0; i < request_files.size(); i++) {
    string req_msg = request_files[i];
    request.add((char*)req_msg.c_str(), sizeof(req_msg));
    socket.send_request(request);

    string file_name = "received/" + request_files[i];
    response = socket.get_response();
    if(response.size() < 100){
      error_check(response.get_data());
    } else {
      int write_size = response.size();
      ofstream data_writer(file_name.c_str(), ios::binary | ios::out);
      data_writer.write(response.get_data(), write_size);
      data_writer.close();
      cout << file_name << " was written\n";
    }
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

void error_check(char * data){
  string err_msg(data);
    cout << "Sorry, the server returned the following error: \n"
	 << err_msg<< "\n";
  exit(0);
}
