/*
 * author: Blaed Johnston
 *
 */

#include <iostream>
#include <string>
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
  return "127.0.0.1";
}
