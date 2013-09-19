/*
 * author: Blaed Johnston
 *
 */

#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#include "AddressNameMapper.h"



using namespace bcjnetworks;
using namespace std;


AddressNameMapper::AddressNameMapper()
  : _hostname("localhost") {}

AddressNameMapper::~AddressNameMapper() {}

string AddressNameMapper::getHostname(string address){
return "a test local hostname";
}

string AddressNameMapper::getIPAddr( string ip_address) {

  struct addrinfo address_hints;
  struct addrinfo *results, *rp;
  int sfd, addressinfo_result_code;
  struct sockaddr_storage peer_address;
  socklen_t peer_address_length;
  ssize_t nread;
  char buffer[BUFFER_SIZE];

  getaddrinfo();


  return "127.0.0.1";
}
