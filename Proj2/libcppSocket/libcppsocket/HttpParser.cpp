/*
 * HttpParser.cpp
 * @author Blaed Johnston October 2013
 *
 */

#include "HttpParser.h"
#include "HttpException.h"
#include <fstream>
#include <regex>
#include <iostream>
#include <string>
#include <boost/regex.hpp>

using namespace libcppsocket;
using namespace std;

HttpParser::HttpParser(MessageBuffer request) {
  req_message = request;
}

MessageBuffer HttpParser::process() {
  MessageBuffer buff;
  extract_header();
  parse_message_type();


  if(request_type == "GET"){
    string filename = extract_filename();
    buff = process_file_send((char *)filename.c_str());
  }


  return buff;
}


void HttpParser::extract_header() {
  header = req_message.get_header();
}

void HttpParser::parse_message_type() {
  string head(header);
  if(head.substr(0,3)=="GET") {
    request_type = "GET";
  } else if(head.substr(0, 3) == "PUT") {
    request_type = "PUT";
  }else if(head.substr(0, 6)== "DELETE") {
    request_type = "DELETE";
  } else{
    throw HttpException("invalid message type");
  }
}
MessageBuffer HttpParser::process_file_send(char *filename) {
  //TODO: check if file exists
  ifstream reader(filename, ios::in|ios::binary|ios::ate);
  ifstream::pos_type file_size;
  char * data_buf;
  if (reader.is_open()) {
    file_size = reader.tellg();
    data_buf= new char [file_size];
    reader.seekg (0, ios::beg);
    reader.read (data_buf, file_size);
    reader.close();
  }
  MessageBuffer response_msg;
  response_msg.add(data_buf, file_size);
  delete[] data_buf;
  return response_msg;
}

string HttpParser::extract_filename(){
  const string head(header);
  string filename;
  static const boost::regex rgx(" [.]* ");
  boost::match_results<std::string::const_iterator> match;
  boost::match_flag_type flags = boost::match_default;

  if(boost::regex_search(head.begin(), head.end(), match, rgx, flags)){
    filename = "bad";
    //    filename = match[0];
  } else {
    //    throw HttpException("no valid filename found");
  }
  return filename;
}
