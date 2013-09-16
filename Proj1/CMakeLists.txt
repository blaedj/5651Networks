include_directories(${CMAKE_SOURCE_DIR}/libcs5651)

ADD_EXECUTABLE( dnsresolver
  AddressNameMapper.h
  AddressNameMapper.cpp
  main.cpp
  )

target_link_libraries(dnsresolver cs5651-util)

target_link_libraries(dnsresolver ${Boost_PROGRAM_OPTIONS_LIBRARIES})