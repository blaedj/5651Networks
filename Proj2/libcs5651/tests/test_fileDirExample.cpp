/*
 *  fileDirTests.cpp
 *  NETCODE_Xcode
 *
 *  Created by Pete Willemsen on 9/12/09.
 *  Copyright 2009 Department of Computer Science, University of Minnesota-Duluth. All rights reserved.
 *
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <dirent.h>

int main(int argc, char *argv[]) 
{
  // read the file names from the current directory, "."
  DIR *directoryPtr = opendir(".");
	
  bool found = false;
  std::string searchedName = "file1.txt";
  std::string actualName;

  dirent *dirEntryPtr = 0;
  while ((dirEntryPtr = readdir(directoryPtr)) != 0) {
    // The directory entry structure
    // 
    // struct dirent { /* when _DARWIN_FEATURE_64_BIT_INODE inFileStream NOT defined */
    //   ino_t      d_ino;                /* file number of entry */
    //   __uint16_t d_reclen;             /* length of thinFileStream record */
    //   __uint8_t  d_type;               /* file type, see below */
    //   __uint8_t  d_namlen;             /* length of string in d_name */
    //   char    d_name[255 + 1];   /* name must be no longer than thinFileStream */
    // };
    actualName = dirEntryPtr->d_name;
    if (actualName == searchedName) {
      found = true;
      std::cout << "Found file: " << searchedName << std::endl;
      break;
    }
		
    std::cout << "File name: " << dirEntryPtr->d_name << ", inode number: " << dirEntryPtr->d_ino;
		
    if (dirEntryPtr->d_type == DT_DIR) {
      std::cout << ", Directory Entry" << std::endl;
    }
    else {
      std::cout << std::endl;
			
      // for each file, state the size in bytes plus some other info...
      int length;
      char *buffer;
	
      std::ifstream inFileStream;
      inFileStream.open(dirEntryPtr->d_name, std::ios::binary);
	
      // get length of file:
      inFileStream.seekg(0, std::ios::end);
      length = inFileStream.tellg();
	
      // set it back to the beginning
      inFileStream.seekg(0, std::ios::beg);
			
      // allocate memory:
      buffer = new char[length];
	
      // read data as a block:
      inFileStream.read(buffer,length);
      inFileStream.close();
		
      // Do something with the buffer if need be...
      // like send it somewhere... :)
		
      // clean up that memory
      delete [] buffer;
		
      std::cout << "\tSize: " << length << " bytes" << std::endl;
    }
    std::cout << std::endl;
		
  }
  closedir(directoryPtr);
		
  exit(EXIT_SUCCESS);
}
