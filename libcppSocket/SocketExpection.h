/*
 * author Blaed Johnston
 *
 * SocketException.h a generic socket exception class.
 */

using namespace std;


class SocketException : public std::exception {

 public:
  SocketException(std::string message="general socket exception")
    : _message(message) {}

  SocketException() throw() {}

  const char* what() const throw( ) {return _message.c_str(); }

private:
  string _message;

};
