include_directories(${CMAKE_SOURCE_DIR}/CS5651Lib)

add_executable(test_NetArgParsing
  test_NetArgParsing.cpp
)

# Need to link with the libcs5651-util.[a,so] library so can do that here
# with the following command (note the lack of 'lib' prefix and the
# '.a', or '.so' suffixes):
target_link_libraries(test_NetArgParsing cs5651-util)

# Also need to link against Boost to get the components we're
# using... namely the program options.
target_link_libraries(test_NetArgParsing ${Boost_PROGRAM_OPTIONS_LIBRARIES})

add_executable(test_fileDirExample
  test_fileDirExample.cpp
)

