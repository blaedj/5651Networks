/*
 * test_MessageBuffer.cpp
 * @author: Blaed Johnston, Oct 2013
 */

#include <sstream>
#include <assert.h>

#include "libcs5651/CS5651Lib/handleNetworkArgs.h"
#include "libcppSocket/libcppsocket/MessageBuffer.h"

using namespace libcppsocket;
using namespace std;
using namespace sivelab;

int main( int argc, char *argv[] ) {

  MessageBuffer buff;
  char a[] = {'a', 'b', 'c', 'd', 'e'};
  char b[] = {'f', 'g', 'h', 'i', 'j'};
  char *c = b;

  buff.add((char *)&a, 5);

  char* data1 = buff.get_data();
  assert(data1[0] == 'a');
  assert(data1[2] == 'c');
  buff.add(c, 5);

  char* data2 = buff.get_data();
  assert(*(data2) == 'a');
  assert(*(data2+1) == 'b');
  assert(*(data2+2) == 'c');
  assert(*(data2+3) == 'd');
  assert(*(data2+6) == 'g');
  assert(*(data2+8) == 'i');
  assert(*(data2+9) == 'j');
  return 0;
}
