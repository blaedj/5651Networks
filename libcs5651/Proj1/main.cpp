/*
 *
 * main.cpp
 * author Blaed Johnston
 */

#include <iostream>
#include "AddressNameMapper.h"
#include "../CS5651Lib/handleNetworkArgs.h"

using namespace bcjnetworks;
using namespace sivelab;


int main(int argc, char *argv[]) {
  NetworkArgs args;
  args.process( argc, argv );
  AddressNameMapper identifier;

  if (args.hasHostname) {
    //identifier = new AddressNameMapper( args.hostname );
    std::string resolved_ip_addr = identifier;
    std::cout << "has a hostname!\n";

  } else if (args.hasHostIP) {
    //    identifier = new AddressNameMapper( args.hostIP );
    std::cout << "has an ipaddress!\n";
  } //else  return 0;

  std::cout << "this is a place holder for the Endian-ness\n";
  std::cout << "this is a placeholder for the hostname or IP address\n";

  return 0;
}
