/*
 * author Blaed Johnston
 *
 * SocketException.h a generic socket exception class.
 */

#include <iostream>
#include <exception>

using namespace std;

namespace libcppsocket {
  class SocketException : public exception {

  public:
    SocketException(string message="general socket exception")
      : _message(message) {}

    const char* what() const throw( ) { return _message.c_str(); }

    ~SocketException()  throw() {}

  private:
    string _message;
  };
}
