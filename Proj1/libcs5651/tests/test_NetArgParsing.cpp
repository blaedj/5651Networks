#include <iostream>
#include <string>

#include "handleNetworkArgs.h"

using namespace sivelab;

int main(int argc, char *argv[])
{
  NetworkArgs args;
  args.process(argc, argv);

  if (args.verbose)
    {
      if (args.hasHostname)
	{
	  std::cout << "Hostname provided: " << args.hostname << std::endl;
	}

      if (args.hasHostIP)
	{
	  std::cout << "Host IP provided: " << args.hostIP << std::endl;
	}
    }
}
