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
  char CR = '\r';
  char LF = '\n';
  MessageBuffer buff;
  char a[] = {'a', 'b', 'c', 'd', 'e'};
  char b[] = {'f', 'g', 'h', 'i', 'j'};
  char *c = b;
  int tc = 0;
  buff.add((char *)&a, 5);

  char* data1 = buff.get_data();
  assert(data1[0] == 'a');
  tc++;
  assert(data1[2] == 'c');
  tc++;
  buff.add(c, 5);

  char* data2 = buff.get_data();
  assert(data2[0] == 'a');
  tc++;
  assert(data2[1] == 'b');
  tc++;
  assert(data2[2] == 'c');
  tc++;
  assert(data2[3] == 'd');
  tc++;
  assert(data2[5] == 'f');
  tc++;
  assert(data2[6] == 'g');
  tc++;
  assert(data2[7] == 'h');
  tc++;
  // test the header-end finding function
  char endHeader[] = {CR, LF, CR, LF};
  MessageBuffer second_buff;
  second_buff.add((char *)&a, 5);
  second_buff.add((char *)&endHeader, 4);
  second_buff.add(c, 5);
  char * head = second_buff.get_header();
  string head_str(head);
  int code = head_str.compare("abcde\r\n\r\n");
  assert( code == 0 );
  tc++;

  for(int i=0;i<tc;i++)
    cout << "+";
  cout << "\nTests run OK\n";
  return 0;
}
