cmake_minimum_required (VERSION 2.8)

include_directories(${CMAKE_SOURCE_DIR}/libcs5651/CS5651Lib)

add_subdirectory(libcs5651)
add_subdirectory(Proj1)
add_subdirectory(libcppSocket)

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
