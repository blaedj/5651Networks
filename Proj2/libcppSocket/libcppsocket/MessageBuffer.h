/*
 * MessageBuffer.h
 * @author Blaed Johnston October 2013
 */


#include <cstdlib>

#include <vector>

using namespace std;

namespace libcppsocket {
  class MessageBuffer {
  public:
    MessageBuffer();
    void add(char *data, int size);
    char *get_data();
    size_t size() {return container.size();}
  private:
    vector<char> container;
  };


}
