/*
 * author Blaed Johnston
 *
 * HttpException.h a generic http exception class.
 */

#include <iostream>
#include <exception>

using namespace std;

namespace libcppsocket {
  class HttpException : public exception {

  public:
    HttpException(string message="general http exception")
      : _message(message) {}
    ~HttpException() throw() {}

    const char* what() const throw() { return _message.c_str(); }
  private:
    string _message;
  };
}
