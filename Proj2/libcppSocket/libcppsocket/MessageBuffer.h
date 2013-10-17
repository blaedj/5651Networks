/*
 * MessageBuffer.h
 * @author Blaed Johnston October 2013
 */

#ifndef __LIBCPPSOCKET__MESSAGE_BUFFER_H__
#define __LIBCPPSOCKET__MESSAGE_BUFFER_H__ 1

#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

namespace libcppsocket {
  class MessageBuffer {
  public:
    MessageBuffer();
    void add(char *data, int size);
    char *get_data();
    size_t size() {return container.size();}
    char * get_header();
    void clear_data();
  private:
    vector<char> container;
    string header;
  };


}

#endif //  __LIBCPPSOCKET__MESSAGE_BUFFER_H__ 1
