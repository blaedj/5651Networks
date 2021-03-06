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
    string resolved_addr = identifier.getIPAddr( args.hostname );
    cout << args.hostname << " is " << resolved_addr << "\n";
  }
  if (args.hasHostIP) {
    string resolved_hostname = identifier.getHostname( args.hostIP );
    cout << args.hostIP << " is: " << resolved_hostname << "\n";
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
