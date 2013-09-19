/*
 *
 * main.cpp
 * author Blaed Johnston
 */

#include <iostream>
#include "AddressNameMapper.h"
#include "handleNetworkArgs.h"

using namespace bcjnetworks;
using namespace sivelab;
using namespace std;


bool isLittleEndian();


int main( int argc, char *argv[] ) {
  NetworkArgs args;
  args.process( argc, argv );
  AddressNameMapper identifier;

  if(isLittleEndian()) {
    cout << "Byte order is Little Endian\n";
  } else {
    cout << "Byte order is Big Endian\n";
  }

  if (args.hasHostname) {
    deque<char*> resolved_addr = identifier.getIPAddr( args.hostname );

    for(int i = 0; i < resolved_addr.size(); i++) {
      char *cur_address = resolved_addr.front();
      resolved_addr.pop_front();
      cout << args.hostname << " is " << cur_address << "\n";
    }

  }
  if (args.hasHostIP) {
    string resolved_hostname = identifier.getHostname( args.hostIP );
    cout << "hostname is: " << resolved_hostname << "\n";
  }

  return 0;
}


/* tests the byte-order of this machine.
 * returns true if little endian, false if big endian.
 */
bool isLittleEndian() {
  // we cast an unsigned int (1) to a char
  // if the zeroth index of the char is 1,
  // then the least significant byte is
  // at starting address, so must be Little Endian
  unsigned int i = 1;
  char *char_pointer = (char *) &i;
  if (char_pointer[0] == 1) {
    return true;
  } else {
    return false;
  }
}
