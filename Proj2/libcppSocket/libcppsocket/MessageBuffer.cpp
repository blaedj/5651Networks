/*
 * MessageBuffer.cpp
 * @author Blaed Johnston October 2013
 */
#include <cstring>
#include <iostream>
#include <sstream>

#include "MessageBuffer.h"

using namespace libcppsocket;
using namespace std;

MessageBuffer::MessageBuffer() {

}

void MessageBuffer::add(char* data , int size) {
  container.insert(container.end(), data, data+size );
}

// returns pointer to the data held in the buffer
char *MessageBuffer::get_data() {
  return &container[0];
}

char * MessageBuffer::get_header(){
  char CR = '\r';
  char LF = '\n';
  stringstream head;
  int crlf_counter = 0;

  // iterate through the container and add the contents at each index
  // until we encounter 2 CRLF 's in a row.
  vector<char>::iterator iter = container.begin();
  while(crlf_counter < 2){
    if(*iter == CR && *(iter+1) == LF){
      crlf_counter += 1;
      head << *iter++;
    }
    head << *iter++;
  }
  return (char *)head.str().c_str();
}

void MessageBuffer::clear_data(){
  container.clear();
}
