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

#include <cstdlib>
#include <iostream>

namespace bcjnetworks {

  class AddressNameMapper {
  public:
    AddressNameMapper();
    virtual ~AddressNameMapper();

    std::string getHostname( std::string ipaddress);
    std::string getIPAddr( std::string hostname);

  private:

    double _ip_address;
    std::string _hostname;
  };

}

#endif // __BCJNETWORKS__ADDRESS_NAME_MAPPER_H__ 1
