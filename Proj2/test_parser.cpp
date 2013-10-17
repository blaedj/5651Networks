/*
 * test_parser.cpp
 * @author: Blaed Johnston, Oct 2013
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#include "libcppSocket/libcppsocket/ClientSocket.h"
#include "libcs5651/CS5651Lib/handleNetworkArgs.h"
#include "libcppSocket/libcppsocket/HttpParser.h"
#include "libcppSocket/libcppsocket/SocketException.h"

using namespace libcppsocket;
using namespace std;
using namespace sivelab;

void testGetTypeGet();
void testGetTypePut();
void testGetTypeDelete();
int testGetTypeInvalid();


int main(int argc, char *argv[]) {
  testGetTypeGet();
  testGetTypePut();
  testGetTypeDelete();
  testGetTypeInvalid();
  return 0;
}


void testGetTypeGet(){
  MessageBuffer buff;
  string data = "GET . HTTP/1.1 \r\n\r\n this is the datax";
  buff.add((char *)data.c_str(), data.length());
  HttpParser parser(buff);
  parser.process();

  assert(parser.request_type == GET);
}

void testGetTypePut(){
  MessageBuffer buff;
  string data = "PUT . HTTP/1.1 \r\n\r\n this is the datax";
  buff.add((char *)data.c_str(), data.length());
  HttpParser parser(buff);
  parser.process();

  assert(parser.request_type == PUT);
  buff.clear_data();
}

void testGetTypeDelete(){
  MessageBuffer buff;
  string data = "DELETE . HTTP/1.1 \r\n\r\n this is the datax";
  buff.add((char *)data.c_str(), data.length());
  HttpParser parser(buff);
  parser.process();

  assert(parser.request_type == DELETE);
  buff.clear_data();
}

int testGetTypeInvalid(){
  MessageBuffer buff;
  string data = "ET . HTTP/1.1 \r\n\r\n this is the datax";
  buff.add((char *)data.c_str(), data.length());
  HttpParser parser(buff);
  try{
    parser.process();
  } catch(SocketException e){
    return 0;
  }
  buff.clear_data();
  /*shouldn't get here, the method should throw an error*/
  assert(false == true);
  return 1;
}
