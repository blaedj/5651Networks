/*
 * HttpParser.cpp
 * @author Blaed Johnston October 2013
 *
 */


#include "HttpParser.h"

using namespace libcppsocket;
using namespace std;

HttpParser::HttpParser(MessageBuffer request) {
  req_message = request;
}

MessageBuffer HttpParser::process() {
  extract_header();
  parse_message_type();

  MessageBuffer buff;
  return buff;
}


void HttpParser::extract_header() {
  header = req_message.get_header();
}

void HttpParser::parse_message_type() {
  string head(header);
  if(head.compare(0, 2, "GET")) {
    request_type = GET;
  }
  if(head.compare(0, 2, "PUT")) {
    request_type = PUT;
  }
  if(head.compare(0, 6, "DELETE")) {
    request_type = DELETE;
  }
}
