cmake_minimum_required (VERSION 2.8)
SET(CMAKE_CXX_FLAGS "-g")

set(LIB_TYPE STATIC)

add_library( cppSocket ${LIB_TYPE}
  # put various library classes here
  AddressNameMapper.cpp AddressNameMapper.h
  ClientSocket.h ClientSocket.cpp
  Socket.h Socket.cpp ServerSocket.h ServerSocket.cpp
  SocketException.h  MessageBuffer.h MessageBuffer.cpp
  )

## This may be needed to install and use the library
 FILE(GLOB files "*.h")
 INSTALL(FILES ${files} DESTINATION include/util)
 INSTALL(TARGETS cppSocket LIBRARY ARCHIVE DESTINATION lib)
