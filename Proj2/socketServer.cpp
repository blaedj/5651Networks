/*
 * socketServer.cpp
 * @author: Blaed Johnston, Oct 2013
 */

#include <sstream>
#include <fstream>

#include "libcs5651/CS5651Lib/handleNetworkArgs.h"
#include "libcppSocket/libcppsocket/ServerSocket.h"
#include "libcppSocket/libcppsocket/SocketException.h"
#include "libcppSocket/libcppsocket/HttpParser.h"

using namespace libcppsocket;
using namespace std;

void signal_handler();
MessageBuffer processFileSend(char * filename);

int main( int argc, char *argv[] ) {
  //TODO: Process args, require port number
  int port = 45002;
  cout << "Starting server on port "<<port<<"...\n";
  ServerSocket server(port);
  server.open_for_clients();
  while(true){
    try{
      int client_fd = server.accept_connection();
      MessageBuffer data_recieved = server.recieve(client_fd);

      //HttpParser worker;

      char * file_requested = data_recieved.get_data();
      MessageBuffer response_msg = processFileSend(file_requested);

      server.respond(response_msg, client_fd);
    } catch( SocketException e) {
      string str(e.what());
      cout << "an error occured: '"<< str << "'\n";
      exit(1);
    }
  }
  return 0;
}

MessageBuffer processFileSend(char *filename) {
  //TODO: check if file exists
  ifstream reader(filename, ios::in|ios::binary|ios::ate);
  ifstream::pos_type file_size;
  char * data_buf;
  if (reader.is_open()) {
    file_size = reader.tellg();
    data_buf= new char [file_size];
    reader.seekg (0, ios::beg);
    reader.read (data_buf, file_size);
    reader.close();
  }
  MessageBuffer response_msg;
  response_msg.add(data_buf, file_size);
  delete[] data_buf;
  return response_msg;
}
