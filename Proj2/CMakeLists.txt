cmake_minimum_required(VERSION 2.8)

project(DROPBOXCLONE)

include_directories(${CMAKE_SOURCE_DIR}/libcs5651/CS5651Lib)
include_directories(${CMAKE_SOURCE_DIR}/../libcppsocket)

SET(CMAKE_CXX_FLAGS "-g")
SET (Boost_MULTITHREADED TRUE)

# If you want to get more info on what the Find Boost macro is
# doing...
# SET(Boost_DEBUG 1)

# Necessary to get Win32 version to work, plus, not a bad idea to link
# statically for our purposes.
SET(Boost_USE_STATIC_LIBS TRUE)

FIND_PACKAGE(Boost REQUIRED date_time program_options system thread unit_test_framework)
IF(${Boost_FOUND})
  INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
ENDIF()

ADD_EXECUTABLE( socketTest
  socketLibTest.cpp
  )

target_link_libraries(socketTest cs5651-util)

target_link_libraries(socketTest ${Boost_PROGRAM_OPTIONS_LIBRARIES})

target_link_libraries(socketTest libcppsocket)