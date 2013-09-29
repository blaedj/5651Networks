/*
 *  handleNetworkArgs.cpp
 *
 *  Created by Pete Willemsen on 10/6/09.
 *  Copyright 2009 Department of Computer Science, University of Minnesota-Duluth. All rights reserved.
 *
 * This file is part of libSIVELab (libsivelab).
 *
 * libsivelab is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libsivelab is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with libsivelab.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "handleNetworkArgs.h"

using namespace sivelab;

NetworkArgs::NetworkArgs()
  : verbose(false), port(8000), hasHostname(false), hostname("localhost"), 
    hasHostIP(false), hostIP("127.0.0.1"), domain(INET_IPv4)
{
  reg("help", "help/usage information", ArgumentParsing::NONE, '?');
  reg("verbose", "turn on verbose output", ArgumentParsing::NONE, 'v');

  reg("type", "protocol family AF_INET | AF_INET6", ArgumentParsing::STRING, 't');
  reg("port", "port number", ArgumentParsing::INT, 'p');
  reg("hostname", "hostname of machine in string, user-friendly notation", ArgumentParsing::STRING, 'n');
  reg("hostip", "hostname in dotted-decimal or dotted-quad notation", ArgumentParsing::STRING, 'i');
  reg("useIPv4", "use IPv4 networking", ArgumentParsing::NONE, '4');
  reg("useIPv6", "use IPv6 networking", ArgumentParsing::NONE, '6');
}

void NetworkArgs::process(int argc, char *argv[])
{
  processCommandLineArgs(argc, argv);

  if (isSet("help"))
    {
      printUsage();
      exit(EXIT_SUCCESS);
    }

  verbose = isSet("verbose");

  isSet("port", port);

  if (isSet("hostname", hostname))
    hasHostname = true;

  if (isSet("hostip", hostIP))
    hasHostIP = true;

  if (isSet("useIPv4"))
    domain = INET_IPv4;
  else if (isSet("useIPv6"))
    domain = INET_IPv6;
}

