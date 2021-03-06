/*
 * socketServer.cpp
 * @author: Blaed Johnston, Oct 2013
 */

#include <sstream>
#include <fstream>

#include "libcs5651/CS5651Lib/handleNetworkArgs.h"
#include "libcppSocket/libcppsocket/ServerSocket.h"
#include "libcppSocket/libcppsocket/SocketException.h"

using namespace libcppsocket;
using namespace std;

void signal_handler();
bool file_exists(char * filename);

int main( int argc, char *argv[] ) {
  ///int port = 45002;
  sivelab::NetworkArgs args;
  args.process(argc, argv);
  if(args.port < 1024){
    cout << "Please enter a valid port number with the option: '-p PORT_#'\n";
    exit(0);
  }
  int port = args.port;
  cout << "Starting server on port "<<port<<"...\n";
  ServerSocket server(port);
  server.open_for_clients();
  cout <<"Server up and running\n";
  cout << "Please note that this server is only able to successfully process"
       << " and send one file per client request\n";
  while(true){
    try{
      int client_fd = server.accept_connection();
      MessageBuffer data_recieved = server.recieve(client_fd);
      cout << "File requested: '"<< data_recieved.get_data() <<"'\n";
      char * file_requested = data_recieved.get_data();
      if(!file_exists(file_requested)){
	MessageBuffer fail_msg;
	string _404 = "404 FILE NOT FOUND";
	fail_msg.add((char *)_404.c_str(),sizeof(_404.c_str()));
	server.respond(fail_msg, client_fd);
	cout << _404 << "\n";
      } else {
	ifstream reader(file_requested, ios::in|ios::binary|ios::ate);
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
	server.respond(response_msg, client_fd);
	cout <<"'" <<file_requested << "'"<< " was sent.\n";
      }
    } catch( SocketException e) {
      string str(e.what());
      cout << "an error occured: '"<< str << "'\n";
      exit(1);
    }
  }
  return 0;
}

bool file_exists(char * filename){
  ifstream file(filename);
  return file;
}
