cmake_minimum_required(VERSION 2.8)

include_directories(${CMAKE_SOURCE_DIR}/../libcs5651/CS5651Lib)
link_directories(${CMAKE_SOURCE_DIR}/../libcs5651/CS5651Lib)

include_directories(${CMAKE_SOURCE_DIR}/../libcs5651/build/CS5651Lib/)
link_directories(${CMAKE_SOURCE_DIR}/../libcs5651/build/CS5651Lib)

include_directories(${CMAKE_SOURCE_DIR}/../libcs5651/)
link_directories(${CMAKE_SOURCE_DIR}/../libcs5651/)


ADD_EXECUTABLE( dnsresolver
  AddressNameMapper.h
  AddressNameMapper.cpp
  main.cpp
  )



target_link_libraries(dnsresolver cs5651-util)

target_link_libraries(dnsresolver ${Boost_PROGRAM_OPTIONS_LIBRARIES})
