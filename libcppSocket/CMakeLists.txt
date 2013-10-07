cmake_minimum_required (VERSION 2.8)

add_library( cppSocket ${LIB_TYPE}
  AddressNameMapper.cpp AddressNameMapper.h
  Socket.h Socket.cpp ServerSocket.h ServerSocket.cpp
  SocketException.h
  # put various library classes here
  )

## This may be needed to install and use the library
 FILE(GLOB files "*.h")
 INSTALL(FILES ${files} DESTINATION include/util)
 INSTALL(TARGETS cppSocket LIBRARY ARCHIVE DESTINATION lib)
