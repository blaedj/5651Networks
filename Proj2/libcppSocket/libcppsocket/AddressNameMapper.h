/*
 * AddressNameMapper.h
 *
 * author: Blaed Johnston 09/2013
 *
 * The AddressNameMapper will return the IP address for a given hostname,
 * and the hostname for a given IP address.
 *
 */

#ifndef __LIBCPPSOCKET__ADDRESS_NAME_MAPPER_H__
#define __LIBCPPSOCKET__ADDRESS_NAME_MAPPER_H__ 1


#include <iostream>
#include <vector>

using namespace std;

namespace libcppsocket {

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

#endif // __LIBCPPSOCKET__ADDRESS_NAME_MAPPER_H__ 1
