/*
 * HttpParser.h
 * @author Blaed Johnston October 2013
 *
 */
#ifndef __LIBCPPSOCKET__HTTP_PARSER_H__
#define __LIBCPPSOCKET__HTTP_PARSER_H__ 1

#include <iostream>

#include "MessageBuffer.h"


namespace libcppsocket {
  enum message_type { GET, PUT, DELETE };

  class HttpParser {
  public:
    HttpParser(MessageBuffer request);
    MessageBuffer process();
    string request_type;
    string extract_filename();
  private:
    bool check_for_file(char* filename);
    MessageBuffer process_file_send(char* filename);
    MessageBuffer req_message;
    void extract_header();
    void parse_message_type();


    char* header;
  };
}

#endif //  __LIBCPPSOCKET__HTTP_PARSER_H__ 1
