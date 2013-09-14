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

namenspace bcjnetworks {

  class AddressNameMapper {
  public:
    AddressNameMapper( int IPAddress );
    AddressNameMapper( string hostName );
    virtual ~AddressNameMapper();

    string getHostname();
    string getIPAddr();

  private:
    AddressNameMapper();
    _ip_address;

  };

}

#endif // __BCJNETWORKS__ADDRESS_NAME_MAPPER_H__ 1
