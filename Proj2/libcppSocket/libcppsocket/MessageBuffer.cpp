/*
 * MessageBuffer.cpp
 * @author Blaed Johnston October 2013
 */
#include <cstring>
#include <iostream>

#include "MessageBuffer.h"

using namespace libcppsocket;
using namespace std;

MessageBuffer::MessageBuffer() {

}

void MessageBuffer::add(char* data , int size) {
  // size_t curlen = container.size();

  // size_t newlen = curlen + size;
  // char *tempContainer = new char[newlen];
  // memcpy(tempContainer, &container, curlen );
  // memcpy(tempContainer+curlen, (const void *)data, size);
  // container.clear();
  container.insert(container.end(), data, data+size );
}

char *MessageBuffer::get_data() {
  return &container[0];
}
