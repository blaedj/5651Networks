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
#include <string>

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

string AddressNameMapper::getIPAddr( string hostname) {
  struct addrinfo *results;//, *result_iter;
  int result_code;
  char buffer[BUFFER_SIZE];
  // struct addrinfo address_hints;
  // memset( &address_hints, 0, sizeof(struct addrinfo) );
  // address_hints.ai_flags = 0; // flags are optional
  // address_hints.ai_family = AF_UNSPEC; // don't specify IPv4 or IPv6
  // address_hints.ai_socktype = 0; // any socket type
  // address_hints.ai_protocol = 0; // any protocol
  // address_hints.ai_canonname = NULL;
  // address_hints.ai_addr = NULL;
  // address_hints.ai_next = NULL;

  // the hostname converted to a c_str, 0 for service, 0 for hints
  result_code = getaddrinfo( hostname.c_str(), 0, 0, &results );

  if(result_code != 0){
    cerr << "this is a placeholder for an exception, couldn't get addrinfo.\n";
    exit(EXIT_FAILURE);
  }
  char ip_string[INET_ADDRSTRLEN];
  // get the address information struct
  struct sockaddr_in *result_addr =(struct sockaddr_in *)(results->ai_addr);

  // convert the binary ip address in resultAddr to dotted decimal form
  inet_ntop(results->ai_family, (const void *)&(result_addr->sin_addr),
	    ip_string, INET_ADDRSTRLEN);

  // release memory
  freeaddrinfo(results);
  string str(ip_string);
  return str;
}
