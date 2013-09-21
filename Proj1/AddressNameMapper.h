/*
 * AddressNameMapper.h
 *
 * author: Blaed Johnston 09/2013
 *
 * The AddressNameMapper will return the IP address for a given hostname,
 * and the hostname for a given IP address.
 *
 */

#ifndef __BCJNETWORKS__ADDRESS_NAME_MAPPER_H__
#define __BCJNETWORKS__ADDRESS_NAME_MAPPER_H__ 1


#include <iostream>
#include <deque>
using namespace std;

namespace bcjnetworks {

  class AddressNameMapper {
  public:
    AddressNameMapper();
    virtual ~AddressNameMapper();

    string getHostname( string ipaddress);
    string getIPAddr( string hostname);

  private:
    double _ip_address;
    string _hostname;
  };
}

#endif // __BCJNETWORKS__ADDRESS_NAME_MAPPER_H__ 1
