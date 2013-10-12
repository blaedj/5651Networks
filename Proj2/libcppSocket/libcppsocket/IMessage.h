/**
 * @author: Blaed Johnston Oct 2013
 *
 * IMessage.h
 * generic message interface to be sent through socket
 */
#ifndef __LIBCPPSOCKET_IMESSAGE_H
#define __LIBCPPSOCKET_IMESSAGE_H 1

#include <iostream>

using namespace std;

namespace libcppsocket {

  class IMessage {

  public:
    //virtual IMessage() = 0;
    virtual ~IMessage();
    std::string header;
    std::string data;

  private:

  };

}
#endif
