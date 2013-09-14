
#include <iostream>

#include "ArgumentParsing.h"
#inclide "handleNetworkArgs.h"

using namespace bcjnetworks;

int main(int argc, char *argv[]) {
  NetworkArgs args;
  args.process( argc, argv );




  if (args.hasHostname) {

    }

  if (args.hasHostIP) {

    }
  return 0;
}
