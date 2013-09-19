/*
 * author: Blaed Johnston
 *
 */

#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <deque>

#include "AddressNameMapper.h"

#define BUFFER_SIZE 500
#define INET_ADDRSTRLEN 16

using namespace bcjnetworks;
using namespace std;


AddressNameMapper::AddressNameMapper()
  : _hostname("localhost") {}

AddressNameMapper::~AddressNameMapper() {}

string AddressNameMapper::getHostname(string ip_address){
  return "a test local hostname";
}

deque<char*> AddressNameMapper::getIPAddr( string hostname) {

  // struct addrinfo address_hints;
  struct addrinfo *results, *result_iter;
  int result_code;
  char buffer[BUFFER_SIZE];
  // make sure address_hints is cleared out in mem
  // memset( &address_hints, 0, sizeof(struct addrinfo) );

  // address_hints.ai_flags = 0; // flags are optional
  // address_hints.ai_family = AF_UNSPEC; // don't specify IPv4 or IPv6
  // address_hints.ai_socktype = 0; // any socket type
  // address_hints.ai_protocol = 0; // any protocol
  // address_hints.ai_canonname = NULL;
  // address_hints.ai_addr = NULL;
  // address_hints.ai_next = NULL;

  // the hostname converted to a c_str, 0 for service,
  result_code = getaddrinfo( hostname.c_str(), 0, 0, &results );

  if(result_code != 0){
    // TODO: Create an exception for this
    cerr << "this is a placeholder for an exception, couldn't get addrinfo.\n";
    exit(EXIT_FAILURE);
  }

  std::deque<char*> ip_addresses;
  for(result_iter = results; result_iter != NULL; result_iter = result_iter->ai_next){
    char* ip_string;

    // get the address information struct
    struct sockaddr_in *result_addr  = (struct sockaddr_in *)(result_iter->ai_addr);

    // convert the binary ip address in resultAddr to dotted decimal form
    inet_ntop(result_iter->ai_family, (const void *)&(result_addr->sin_addr), ip_string,
	      INET_ADDRSTRLEN);

    //cout << hostname << " is " << ip_string << "\n";

    // make sure we don't have duplicates, then push onto the deque
    if(strcmp(ip_addresses.front(), ip_string ) != 0){
      ip_addresses.push_front( ip_string );
    }
  }

  // release memory
  freeaddrinfo(results);
  return ip_addresses;
    //  return "IP_ADDRESSES_HERE";
}
